//指明该驱动程序适用于哪一些PCI设备
static struct pci_device_id_demo_pci_tbl [] __initdata =
{
    {PCI_VENDOR_ID_DEMO, PCI_DEVICE_ID_DEMO, PCI_ANY_ID, PCI_ANY_ID, 0, 0, DEMO},
    {0,}
};

//对特定PCI设备进行描述的数据结构
struct demo_card
{
    unsigned int magic;
    struct demo_card *next; //使用链表保存所有同类的PCI设备

    /* ... */
};

//中断处理模块
static void demo_interrupt(int irq, void *dev_id, struct pt_regs *regs)
{

}

//设备文件操作接口
static struct file_operations demo_fops = 
{
    owner:  THIS_MODULE,    //demo_fops所属的设备模块
    read:   demo_read,      //读设备操作
    write:  demo_write,     //写设备操作
    ioctl:  demo_ioctl,     //控制设备操作
    mmap:   demo_mmap,      //内存重映射操作
    open:   demo_open,      //打开设备操作
    release:demo_release    //释放设备操作
    /* ... */
};

static int __init demo_init_module(void)
{
    
}

static void __exit demo_clean_module(void)
{
    pci_unregister_driver(&demo_pci_driver);
}

//加载驱动程序入口
module_init(demo_init_module);

//卸载驱动程序入口
module_exit(demo_cleanup_module);


static int __init demo_init_module(void)
{
    //检查系统是否支持PCI总线
    if (!pci_present())
        return -ENODEV;
    //注册硬件驱动程序
    if (!pci_register_driver(&demo_pci_driver))
}
