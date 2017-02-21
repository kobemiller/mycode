#include <linux/kfifo.h>

init()
{
    ret = kfifo_alloc(&wng_fifo, WNG_FIFO_SIZE, GFP_KERNEL);
    if (ret)
        return ret;
}

produce_wng()
{
#define WNG_BUF_SIZE    1024
    unsigned char buf[WNG_BUF_SIZE];
    int i;
    
    while (1)
    {
        if ((ret = kfifo_avail(&wng_fifo)) > 0)
        {
            for (i = 0; i < WNG_BUF_SIZE; i++)
                buf[i] = (unsigned char)get_random();

            kfifo_in(wng_fifo, buf, WNG_BUF_SIZE);
            continue;
        }
        else
        {
            sleep(3);
        }
    }
}

consume_wng(unsigned char *usr, unsigned int len)
{
    unsigned int offset;
    unsigned char buf[WNG_BUF_SIZE];

    while (offset < len)
    if (!kfifo_empty(&wng_fifo))
    {
    }
        kfifo_out();

    tmp_len = kfifo_len(&wng_kfifo);
    if (tmp_len >= len)
    {
        kfifo_out(&wng_kfifo, buf, len);
        copy_to_user(usr, buf, len);
    }
    else
    {
        kfifo_out(&wng_kfifo, buf, tmp_len);
        copy_to_user(usr, buf, tmp_len);
    }
    kfifo_out(&wng_kfifo, buf, (t = kfifo_len(&wng_kfifo)) >= len ? len : t);
    copy_to_user(usr, buf, t >= len ? len : t);
    offset += t;
}

exit()
{
    kfifo_free(&wng_kfifo);
}
