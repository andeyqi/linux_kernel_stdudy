#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/platform_device.h>/* for the driver model interface to the platform bus */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("andeyqi");
MODULE_DESCRIPTION("PlatformDeviceModule");
MODULE_ALIAS("platform device module");

struct platform_device m_device = {
    .name       = "test",
};


 
int platform_device_init()
{
    platform_device_register(&m_device); /* 向内核添加设备 */
    return 0;
} 

void platform_device_exit()
{
    platform_device_unregister(&m_device); /* 告诉内核移除设备 */
}

 
module_init(platform_device_init);
module_exit(platform_device_exit);
