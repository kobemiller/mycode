#include <linux/config.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/types.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/cdev.h>
#include <asm/system.h>
#include <asm/uaccess.h>

#include "scull.h"

int scull_major = SCULL_MAJOR;
int scull_minor = 0;
int scull_nr_devs = SCULL_NR_DEVS;
int scull_quantum = SCULL_QUANTUM;
int scull_qset = SCULL_QSET;

module_param(scull_major, int ,S_IRUGO);
module_param(scull_minor, int, S_IRUGO);
module_param(scull_nr_devs, int , S_IRUGO);
module_param(scull_quantum, int, S_IRUGO);
module_param(scull_qset, int, S_IRUGO);

MODULE_AUTHOR("kobemiller");
MODULE_LICENSE("Dual BSD/GPL");

struct scull_dev *scull_devices;

int scull_trim(struct scull_dev *dev)
{
    struct scull_qset *next, *dptr;
    int qset = dev->qset;
    int i;

    for (dptr = dev->data; dptr; dptr = next)
    {
        if (dptr->data)
        {
            for (i = 0; i < qset; i++)
                kfree(dptr->data[i]);
            kfree(dptr->data);
            dptr->data = NULL;
        }
        next = dptr->next;
        kfree(dptr);
    }
    dev->size = 0;
    dev->quantum = scull_quantum;
    dev->qset = scull_qset;
    dev->data = NULL;

    return 0;
}

#ifdef  SCULL_DEBUG

int scull_read_procmem(char *buf, char **start, off_t offset,
        int count, int *eof, void *data)
{
    int i, j, len = 0;
    int limit = count - 80;

    for (i = 0; i < scull_nr_devs && len <= limit; i++)
    {
        struct scull_dev *d = &scull_devices[i];
        struct scull_qset *qs = d->data;
        if (down_interruptible(&d->sem))
            return -ERESTARTSYS;
        len += sprintf(buf + len, "\nDevice %i: qset %i, q %i, sz %li\n",
                i, d->qset, d->quantum, d->size);
        for (; qs && len <= limit; qs = qs->next)
        {
            len += sprintf(buf + len, " iterm at %p, qset at %p\n", qs, qs->data);
            if (qs->data && !qs->next)
                for (j = 0; j < d->qset; j++)
                {
                    if (qs->data[j])
                        len += sprintf(buf + len, " %4i: %8p\n", j, qs->data[j]);
                }
        }
        up(&scull_devices[i].sem);
    }
    *eof = 1;

    return len;
}

static void *scull_seq_start(struct seq_file *s, loff_t *pos)
{
    if (*pos >= scull_nr_devs)
        return NULL;
    return scull_devices + *pos;
}

static void *scull_seq_next(struct seq_file *s, void *v, loff_t *pos)
{
    (*pos)++;
    if (*pos >= scull_nr_devs)
        return NULL;
    return scull_devices + *pos;
}

static void scull_seq_stop(struct seq_file *s, void *v)
{
    
}

static int scull_seq_show(struct seq_file *s, void *v)
{
    struct scull_dev *dev = (struct scull_dev *)v;
    struct scull_qset *d;
    int i;

    if (down_interruptible(&dev->sem))
        return -ERESTARTSYS;
    seq_printf(s, "\nDevice %i: qset %i, q %i, sz %Li\n", (int)(dev - scull_devices),
            dev->qset, dev->quantum, dev->size);
    for (d = dev->data; d; d = d->next)
    {
        seq_printf(s, " item at %p, qset at %p\n", d, d->data);
        if (d->data && !d->next)
            for (i = 0; i < dev->qset; i++)
            {
                if (d->data[i])
                    seq_printf(s, "     %4i: %8p\n", i, d->data[i]);
            }
    }
    up(&dev->sem);
    return 0;
}

static struct seq_operations scull_seq_ops =
{
    .start  = scull_seq_start,
    .next   = scull_seq_next,
    .stop   = scull_seq_stop,
    .show   = scull_seq_show
};

static int scull_proc_open(struct inode *inode, struct file *file)
{
    return seq_open(file, &scull_seq_ops);
}

static struct file_operations scull_proc_ops = 
{
    .owner  = THIS_MODULE,
    .open   = scull_proc_open,
    .read   = seq_read,
    .llseek = seq_lseek,
    .release = seq_release
};

static void scull_create_proc(void)
{
    struct proc_dir_entry *entry;
    create_proc_read_entry("scullmem", 0, NULL, scull_read_procmem, NULL);
    entry = create_proc_entry("scullseq", 0, NULL);
    if (entry)
        entry->proc_fops = &scull_proc_ops;
}

#endif  //SCULL_DEBUG

int scull_open(struct inode *inode, struct file *filp)
{
    struct scull_dev *dev;
    dev = container_of(inode->i_cdev, struct scull_dev, cdev);
    filp->private_data = dev;

    if ((filp->f_flags & O_ACCMODE) == O_WRONLY)
    {
        if (down_interruptible(&dev->sem))
            return -ERESTARTSYS;
        scull_trim(dev);
        up(&dev->sem);
    }

    return 0;
}

int scull_release(struct inode *inode, struct file *filp)
{
    return 0;
}

struct scull_qset *scull_follow(struct scull_dev *dev, int n)
{
    struct scull_qset *qs = dev->data;
    if (!qs)
    {
        qs = dev->data = kmalloc(sizeof(struct scull_qset), GFP_KERNEL);
        if (qs == NULL)
            return NULL;
        memset(qs, 0, sizeof(struct scull_qset));
    }

    while (n--)
    {
        if (!qs->next)
        {
            qs->next = kmalloc(sizeof(struct scull_qset), GFP_KERNEL);
            if (qs->next == NULL)
                return NULL;
            memset(qs->next, 0, sizeof(struct scull_qset));
        }
        qs = qs->next;
        continue;
    }
    return qs;
}

ssize_t scull_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
    struct scull_dev *dev = filp->private_data;
    struct scull_qset *dptr;
    int quantum = dev->quantum, qset = dev->qset;
    int itemsize = quantum * qset;
    int item, s_pos, q_pos, rest;
    ssize_t retval = 0;

    if (down_interruptible(&dev->sem))
        return -ERESTARTSYS;
    if (*f_pos >= dev->size)
        goto out;
    if (*f_pos + count > dev->size)
        count = dev->size - *f_pos;

    item = (long)*f_pos / itemsize;
    rest = (long)*f_pos % itemsize;
    s_pos = rest / quantum;
    q_pos = rest % quantum;

    dptr = scull_follow(dev, item);

    if (dptr == NULL || !dptr->data || !dptr->data[s_pos])
        goto out;

    if (count > quantum - q_pos)
        count = quantum - q_pos;

    if (copy_to_user(buf, dptr->data[s_pos] + q_pos, count))
    {
        retval = -EFAULT;
        got out;
    }
    *f_pos += count;
    retval = count;

out:
    up(&dev->sem);
    return retval;
}

