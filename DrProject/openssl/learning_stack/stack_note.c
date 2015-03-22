typedef struct stack_st
	{
		int 	num;
		char 	**data;
		int 	sorted;
		int 	num_alloc;
		int 	(*comp) (const void *, const void *);
	} _STACK;

	int (*sk_set_cmp_func(_STACK *sk, int (*c) (const void *, const void *))) (const void *, const void *)
	//函数名可以这么理解：
	//typedef int(*comp_func_t)(const void *, const void *)
	//comp_func_t sk_set_cmp_func(_STACK *sk, comp_func_t c)
	{
		//此函数用于设置堆栈存放数据的比较函数。由于堆栈不知道用户存放的是什么数据，所以，比较函数必须又用户自己实现。
		//返回值：若设置成功，则返回比较函数。否则返回原来的比较函数。
		int (*old)(const void *, const void *) = sk->comp;
		if ( sk->comp != c )
			sk->sorted = 0;
		sk->comp = c;

		return old;
	}
	int sk_find(_STACK *st, void *data)
	{
		//根据数据地址来查找它在堆栈中的位置。当堆栈设置了比较函数时，它首先对堆栈进行排序，然后通过二分法进行查找。
		//如果堆栈没有设置比较函数，它只是简单的比较数据地址来查找。
		//openssl/objects.h中定义的：
		//# define OBJ_BSEARCH_VALUE_ON_NOMATCH            0x01
		//# define OBJ_BSEARCH_FIRST_VALUE_ON_MATCH        0x02
		return internal_find(st, data, OBJ_BSEARCH_FIRST_VALUE_ON_MATCH);
	}
	int sk_find_ex(_STACK *st, void *data)
	{
		return internal_find(st, data, OBJ_BSEARCH_VALUE_ON_NOMATCH);
	}
	static int internal_find(_STACK *st, void *data, int ret_val_options)
	{
		const void *const *r;
		int i;

		if ( st == NULL )
			return -1;
		if ( st->comp == NULL )
		{
			for ( i = 0; i < st->num; i++ )
				if ( st->data[i] == data )
					return (i);
			return -1;
		}

		sk_sort(st);
		if ( data == NULL )
			return -1;
		r = OBJ_bsearch_ex_(&data, st->data, st->num, sizeof(void *), st->comp, ret_val_options);
		if ( r == NULL )
			return -1;
		return (int)((char **)r - st->data);
	}
	void sk_sort(_STACK *st)
	{
		if ( st && !st->sorted )
		{
			int (*comp_func) (const void *, const void *);
			comp_func = (int (*)(const void *, const void *))(st->comp);
			qsort(st->data, st->num, sizeof(char *), comp_func);
			st->sorted = 1;
		}
	}
	void sk_pop_free(_STACK *st, void (*func) (void *))
	{
		//本函数用于释放堆栈内存放的数据以及堆栈本身， 它需要一个由用户指定的针
		//对具体数据的释放函数。如果用户仅调用 sk_free 函数，则只会释放堆栈本身所用
		//的内存，而不会释放数据内存。
		int i;
		if ( st == NULL )
			return;
		for ( i = 0; i < st->num; i++ )
			if ( st->data[i] != NULL )
				func(st->data[i]);
		sk_free(st);
	}
	void sk_free(_STACK *st)
	{
		//openssl/crypto.h
		//#define OPENSSL_free(addr) 	CRYPTO_free(addr)
		//void CRYPTO_free(void *ptr);
		//实现在crypto/mem.c中：
		// void CRYPTO_free(void *str)
		// {
		// 	if ( free_debug_func != NULL )
		// 		free_debug_func(str, 0);
		// 	#ifdef LEVITTE_DEBUG_MEM
		// 	fprintf(stderr, "LEVITTE_DEBUG_MEM: 		< 0x%p\n", str);
		// 	#endif
		// 	free_func(str);
		// 	if ( free_debuf_func != NULL )
		// 		free_debug_func(NULL, 1);
		// }
		if ( st == NULL )
			return;
		if ( st->data != NULL )
			OPENSSL_free(st->data);
		OPENSSL_free(st);
	}
	

