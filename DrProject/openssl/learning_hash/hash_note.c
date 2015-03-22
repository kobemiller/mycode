typedef struct lhash_node_st
	{
		void *data;
		struct lhash_node_st *next;
		#ifndef OPENSSL_NO_HASH_COMP
		unsigned long hash;
		#endif
	} LHASH_NODE;

	typedef struct lhash_node_st
	{
		LHASH_NODE **b; 					//b指针数组存放所有的数据，数组中的每一个值为数据链表的头指针
		LHASH_COMP_FN_TYPE 	comp; 			//comp存放数据比较函数地址
		LHASH_HASH_FN_TYPE 	hash;			//hash存放计算hash值函数的地址
		unsigned int 	num_nodes; 			//num_nodes为链表个数
		unsigned int 	num_alloc_nodes;	//num_alloc_nodes为b分配空间的大小
		unsigned int 	p;
		unsigned int 	pmax;
		unsigned long 	up_load;
		unsigned long 	down_load;
		unsigned long 	num_items;
		unsigned long 	num_expands;
		unsigned long 	num_expands_reallocs;
		unsigned long 	num_contracts;
		unsigned long 	num_contract_reallocs;
		unsigned long 	num_hash_calls;
		unsigned long 	num_comp_calls
		unsigned long 	num_insert;
		unsigned long 	num_replace;
		unsigned long 	num_delete;
		unsigned long 	num_no_delete;
		unsigned long 	num_retrieve;
		unsigned long 	num_retrieve_miss;
		unsigned long 	num_hash_comps;
		int 			error;
	} _LHASH;

	_LHASH *lh_new(LHASH_HASH_FN_TYPE h, LHASH_COMP_FN_TYPE c)
	{
		//h和c均为回调函数，用户必须提供
		//h为哈希函数，c为比较函数
		_LHASH *ret;
	    int i;

	    if ((ret = OPENSSL_malloc(sizeof(_LHASH))) == NULL)
	        goto err0;
	    if ((ret->b = OPENSSL_malloc(sizeof(LHASH_NODE *) * MIN_NODES)) == NULL)
	        goto err1;
	    for (i = 0; i < MIN_NODES; i++)
	        ret->b[i] = NULL;
	    ret->comp = ((c == NULL) ? (LHASH_COMP_FN_TYPE)strcmp : c);
	    ret->hash = ((h == NULL) ? (LHASH_HASH_FN_TYPE)lh_strhash : h);
#@	    ret->num_nodes = MIN_NODES / 2;
	    ret->num_alloc_nodes = MIN_NODES;
	    ret->p = 0;							//
	    ret->pmax = MIN_NODES / 2;			//
	    ret->up_load = UP_LOAD;
	    ret->down_load = DOWN_LOAD;
	    ret->num_items = 0;
 
	    ret->num_expands = 0;
	    ret->num_expand_reallocs = 0;
	    ret->num_contracts = 0;
	    ret->num_contract_reallocs = 0;
	    ret->num_hash_calls = 0;
	    ret->num_comp_calls = 0;
	    ret->num_insert = 0;
	    ret->num_replace = 0;
	    ret->num_delete = 0;
	    ret->num_no_delete = 0;
	    ret->num_retrieve = 0;
	    ret->num_retrieve_miss = 0;
	    ret->num_hash_comps = 0;

	    ret->error = 0;
	    return (ret);
	 err1:
	    OPENSSL_free(ret);
	 err0:
	    return (NULL);
	}

	unsigned long lh_strhash(const char *c)
	{
		unsigned long ret = 0;
		long n;
		unsigned long v;
		int r;

		if ( (c == NULL) || (*c == '\0') )
			return (ret);

		n = 0x100;
		while ( *c )
		{
			v = n | (*c);
			n += 0x100;
			r = (int)((v >> 2) ^ v) & 0x0f;
			ret = (ret << r) | (ret >> (32 - r));
			ret &= 0xFFFFFFFFL;
			ret ^= v * v;
			c++;
		}
		return ((ret >> 16) ^ ret);
	}
	
	void *lh_delete(_LHASH *lh, const void *data)
	{
		unsigned long hash;
		LHASH_NODE *nn, **rn;
		void *ret;

		lh->error = 0;
		rn = getrn(lh, data, &hash);
		if ( *rn == NULL )
		{
			lh->num_no_delete++;
			return (NULL);
		}
		else
		{
			nn = *rn;
			*rn = nn->next;
			ret = nn->data;
			OPENSSL_free(nn);
			lh->num_delete++;
		}

		lh->num_items--;
		if ( (lh->num_nodes > MIN_NODES) && (lh->down_load >= (lh->num_items * LH_LOAD_MULT / lh->num_nodes)) )
			contract(lh);

		return (ret);
	}

	static LHASH_NODE **getrn(_LHASH *lh, const void *data, unsigned long *rhash)
	{
		LHASH_NODE **ret, *n1;
		unsigned long hash, nn;
		LHASH_COMP_FN_TYPE cf;

#@		hash = (*(lh->hash)) (data); 	//这句是干嘛？
		lh->num_hash_calls++;
		*rhash = hash;

		nn = hash % lh->pmax;
		if ( nn < lh->p )
			nn = hash % lh->num_alloc_nodes;

		cf = lh->comp;
		ret = &(lh->b[(int)nn]);
		for ( n1 = *ret; n1 != NULL; n1 = n1->next )
		{
			#ifndef OPENSSL_NO_HASH_COMP
			lh->num_hash_comps++;
			if ( n1->hash != hash )
			{
				ret = &(n1->next);
				continue;
			}
			#endif
			lh->num_comp_calls++;
			if ( cf(n1->data, data) == 0 )
				break;
			ret = &(n1->next);
		}

		return (ret);
	}

	void lh_doall(_LHASH *lh, LHASH_DOALL_FN_TYPE func)
	{
		doall_util_fn(lh, 0, func, (LHASH_DOALL_ARG_FN_TYPE)0, NULL);
	}
	void lh_doall_arg(_LHASH *lh, LHASH_DOALL_ARG_FN_TYPE func, void *arg)
	{
		doall_util_fn(lh, 1, (LHASH_DOALL_FN_TYPE)0, func, arg);
	}
	static void doall_util_fn(_LHASH *lh, int use_arg, LHASH_DOALL_FN_TYPE func, LHASH_DOALL_ARG_FN_TYPE func_arg, void *arg)
	{
		int i;
		LHASH_NODE *a, *n;

		if ( lh == NULL )
			return;
		/*
		 *reverse the order so we search from top to bottom we were having memory leak otherwise
		 */
		for ( i = lh->num_nodes - 1; i >= 0; i-- )
		{
			a = lh->b[i];
			while ( a != NULL )
			{
				n = a->next;
				if ( use_arg )
					func_arg(a->data, arg);
				else
					func(a->data);
				a = n;
			}
		}
	}

	void lh_free(_LHASH *lh)
	{//释放哈希表
		unsigned int i;
		LHASH_NODE *n, *nn;

		if ( lh == NULL )
			return;
		for ( i = 0; i < lh->num_nodes; i++ )
		{
			n = lh->b[i];
			while ( n != NULL )
			{
				nn = n->next;
				OPENSSL_free(n);
				n = nn;
			}
		}
		OPENSSL_free(lh->b);
		OPENSSL_free(lh);
	}

	void *lh_insert(_LHASH *lh, void *data)
	{
		unsigned long hash;
		LHASH_NODE *nn, **rn;
		void *ret;

		lh->error = 0;
		if ( lh->up_load <= (lh->num_items * LH_LOAD_MULT / lh->num_nodes) )
			expand(lh);
		rn = getrn(lh, data, &hash);

		if ( *rn == NULL )
		{
			if ( (nn = (LHASH_NODE *)OPENSSL_malloc(sizeof(LHASH_NODE))) == NULL )
			{
				lh->error++;
				return (NULL);
			}
			nn->data = data;
			nn->next = NULL;
			#ifndef OPENSSL_NO_HASH_COMP
			nn->hash = hash;
			#endif
			*rn = nn;
			ret = NULL;
			lh->num_insert++;
			lh->num_items++;
		}
		else
		{
			ret = (*rn)->data;
			(*rn)->data = data;
			lh->num_replace++;
		}
		return (ret);
	}

