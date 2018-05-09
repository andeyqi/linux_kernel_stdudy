#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/platform_device.h>/* for the driver model interface to the platform bus */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("andeyqi");
MODULE_DESCRIPTION("PlatformDriverModule");
MODULE_ALIAS("platform driver module");


int platform_driver_test_probe(struct platform_device * data){
    
    printk("platform_driver_probe is called\n");
	return 0;
}

static struct platform_driver m_driver = {
    .probe      = platform_driver_test_probe,
    .driver     = {
        .name   = "test",
        .owner  = THIS_MODULE,
    },
};


 
int platform_driver_init()
{
    platform_driver_register(&m_driver); /* 向内核添加驱动 */
    return 0;
} 

void platform_driver_exit()
{
    platform_driver_unregister(&m_driver); /* 告诉内核移除驱动 */
}

 
module_init(platform_driver_init);
module_exit(platform_driver_exit);
