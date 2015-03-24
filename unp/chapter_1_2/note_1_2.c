/*
 * note for UNP chapter 1
 */
/*
 * 包裹函数（wrapper function）
 * 每个包裹函数完成实际的函数调用，检查返回值，并在发生错误的时候终止进程
 */
sockfd = Socket(AF_INET, SOCK_STREAM, 0);
int Socket(int family, int type, int protocol)
{
    int n;
    if ( (n = socket(family, type, protocol)) < 0 )
        err_sys("socket error");
    return (n);
}

/*
 * 以pthread_开头的函数，我们必须分配一个变量来存放函数返回值，
 * 以便在调用err_sys前把errno变量设置成该值。
 */
{
    int n;
    if ( (n = pthread_mutex_lock(&ndone_mutex)) != 0 )
        errno = n, err_sys("pthread_mutex_lock error");
}

/*
 * 习惯使用snprintf代替sprintf。
 * 用sprintf是无法检查目的缓冲区是否溢出，
 * snprintf要求其第二个参数指定目的缓冲区的大小，因此可确保缓冲区不溢出
 */
snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));

/*
 * UDP不保证UDP数据报会到达其最终目的地，不保证各个数据报的
 * 先后顺序跨网络后保持不变，也不保证每个数据报只到达一次
 */
/*
 * TCP提供了可靠性，但并不保证数据一定会被对方端点接收。
 * 它提供的是数据的可靠递送或故障的可靠通知
 */
