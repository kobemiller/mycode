/*
 * hello.c -- 
 *
 * Version: 1.0  02/10/2017 11:55:54 PM
 */

#include <linux/init.h>     //
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

static char *whom = "kobemiller";
static int howm = 1;
module_param(howm, int, S_IRUGO|S_IWUSR);
module_param(whom, charp, S_IRUGO|S_IWUSR);

static int hello_init(void)
{
    printk(KERN_ALERT "Hello, world\n");

    return 0;
}

static void hello_exit(void)
{
    printk(KERN_ALERT "Goodbye, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);
