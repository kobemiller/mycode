/*
openssl内存分配
	openssl 分配内存时，在其内部维护一个内存分配哈希表，用于存放已经分配但未释放的内存信息。当用户申请内存分配时，在哈希表中添加此项信息，
	内存释放时删除该信息。当用户通过 openssl
函数查找内存泄露点时，只需查询该哈希表即可。用户通过 openssl 回调函数还能处理那些泄露的内存。可以方便地检查内存的泄露点，可以知道某一次
对内存的申请造成了多大的内存泄露，是哪个文件，哪行语句造成的。
*/
	typedef struct app_mem_info_st
	{
		unsigned long 	thread;			//申请内存的线程号
		const char*		file;			//申请内存的文件名
		int 			line;			//申请内存的行号
		const char* 	info;
		struct app_mem_info_st* next;
		int 			references; 	//被引用次数
	} APP_INFO;

	typedef struct mem_set
	{
		void* 			addr; 		//分配内存的地址
		int 			num; 		//分配内存的大小
		const char* 	file; 		//分配内存的文件
		int 			line; 		//分配内存的行号
		CRYPTO_THREADID threadid; 	//分配内存的线程ID
		unsigned long 	order; 		//第几次内存分配
		time_t 			time; 		//内存分配时间
		APP_INFO* 		app_info; 	//用于存放用户应用信息，为一个链表，存放文件、行号以及线程ID等信息
	} MEM;

	void *CRYPTO_malloc(int num, const char *file, int line)
	{
		void *ret = NULL;
		if ( num <= 0 )
			return NULL;
		if ( allow_customize )
			allow_customize = 0;
		if ( malloc_debug_func != NULL ) 	//malloc_debug_func初值为0，如果用户编程时没有改变这个值，CRYPTO_malloc = malloc
		{
			if ( allow_customize_debug )
				allow_customize_debug = 0;
			malloc_debug_func(NULL, num, file, line, 0);
		}
		ret = malloc_ex_func(num, file, line);
		#ifdef LEVITTE_DEBUG_MEM
		fprintf(stderr, "LEVITTE_DEBUG_MEM: 		> 0x%p (%d)\n", ret, num);
		#endif
		if ( malloc_debug_func != NULL )
			malloc_debug_func(ret, num, file, line, 1);
		#ifndef OPENSSL_CPUID_OBJ
		if ( ret && (num > 2048) )
		{
			extern unsigned char cleanse_ctr;
			((unsigned char *)ret)[0] = cleanse_ctr;
		}
		#endif

		return ret;
	}
	static void *(*malloc_func) (size_t) = malloc;
	static void *default_malloc_ex(size_t num, const char *file, int line)
	{
		return malloc_func(num);
	}
	static void *(malloc_ex_func) (size_t, const char *file, int line) = default_malloc_ex;
