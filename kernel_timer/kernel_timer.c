#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/timer.h>  /*timer*/
#include <asm/uaccess.h>  /*jiffies*/

MODULE_LICENSE("GPL");
MODULE_AUTHOR("andeyqi");
MODULE_DESCRIPTION("TimerModule");
MODULE_ALIAS("timer module");

struct timer_list timer;
//定时器超时执行函数 
void timer_function(int para)
{
   printk("<0>Timer Expired and para is %d !!\n",para);   
}
 
int timer_init()
{
    init_timer(&timer);                  //初始化内核定时器
    timer.data= 5;                       //给执行的函数传参
    timer.expires= jiffies + (5 * HZ);   //当前jiffies的值加上5秒钟之后
    timer.function= timer_function;      //如果超时了就执行这个函数
    add_timer(&timer);                   //启动定时器
    return 0;

} 

void timer_exit()
{
    del_timer(&timer );
}

 
module_init(timer_init);
module_exit(timer_exit);
