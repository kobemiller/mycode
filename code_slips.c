//use this to suppress gcc's `...may be used before initialized` warnings.
#ifdef lint
#define   IF_LINT(code) code
#else
#define   IF_LINT(code)   //empty
#endif

//open() examples
fd = open("startup", O_RDONLY);
if (fd == -1)
  errExit("open");

fd = open("myfile", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
if (fd == -1)
  errExit("open");

fd = open("w.log", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, S_IRUSR | S_IWUSR);
if (fd == -1)
  errExit("open");

//试图以独占方式打开文件的错误代码
{
  fd = open(argv[1], O_WRONLY);   //check if file exits
  if (fd != -1)
  {
    printf("[PID %ld] File \"%s\" already exists\n", (long)getpid(), argv[1]);
    close(fd);
  }
  else
  {
    if (errno != ENOENT)    //failed for unexpected reason
      errExit("open");
    else  //window for failure
    {
      fd = open(argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
      if (fd == -1)
        errExit("open");

      printf("[PID %ld] Created file \"%s\" exclusively\n", (long)getpid(), argv[1]);
    }
  }
}

//复制文件描述符的两种方式
dup2(oldfd, newfd);
newfd = fcntl(oldfd, F_DUPFD, startfd);

//一种不错的goto用法
int my_init_function(void)
{
    int err;

    err = register_this(ptr1, "skull");
    if (err)
        goto fail_this;
    err = register_that(ptr2, "skull");
    if (err)
        goto fail_that;
    err = register_those(ptr3, "skull");
    if (err)
        goto fail_those;

    return 0;

fail_those:
    unregister_that(ptr2, "skull");
fail_that:
    unregister_this(ptr1, "skull");
fail_this:
    return err;
}

//驱动ioctl函数的一个小demo

//头文件
#include <asm/ioctl.h>

#define MAXBUF  20
typedef struct _buf_data
{
    int size;
    char data[MAXBUF];
}buf_data;

#define HELLO_IOCTL_NR_BASE     0
#define HELLO_IOCTL_NR_SET_DATA     (HELLO_IOCTL_NR_BASE + 1)
#define HELLO_IOCTL_NR_MAX          (HELLO_IOCTL_NR_GET_BUFF + 1)

#define HELLO_IOCTL_SET_DATA        _IOR('h', HELLO_IOCTL_NR_SET_DATA, buf_data*)

//实现
static int hello_ioctl(struct inode *inode, struct file *filp,
        unsigned int cmd, unsigned long arg)
{
    int cmd_nr;
    int err;
    buf_data buff;

    err = 0;
    cmd_nr = _IOC_NR(cmd);
    switch (cmd_nr)
    {
        case HELLO_IOCTL_NR_SET_DATA:
            if (copy_from_user(&buff, (unsigned char *)arg, sizeof(buf_data)))
            {
                err = -ENOMEM;
                goto err;
            }
            memset(hello_buf, 0, sizeof(hello_buf));
            memcpy(hello_buf, buff.data, buff.size);
            break;

        default:
            printk("hello_ioctl: Unknown ioctl command(%d)\n", cmd);
            break;
    }

error:
    return err;
}

//scull.c中获取主设备号的代码
if (scull_major)
{
    dev = MKDEV(scull_major, sucll_minor);
    result = register_chrdev_region(dev, scull_nr_devs, "scull");
}
else
{
    result = alloc_chrdev_region(&dev, scull_minor, scull_nr_devs, "scull");
    scull_major = MAJOR(dev);
}
if (result < 0)
{
    printk(KERN_WARNING "scull: can't get major %d\n", scull_major);
    return result;
}

//mkstemp
int fd;
char template[] = "/tmp/somestring*******";

fd = mkstemp(template);
if (fd == -1)
    errExit("mkstemp");
printf("Generate filename was : %s\n", template);
unlink(template);

if (close(fd) == -1)
    errExit("close");
