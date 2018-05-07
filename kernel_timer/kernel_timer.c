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
//��ʱ����ʱִ�к��� 
void timer_function(int para)
{
   printk("<0>Timer Expired and para is %d !!\n",para);   
}
 
int timer_init()
{
    init_timer(&timer);                  //��ʼ���ں˶�ʱ��
    timer.data= 5;                       //��ִ�еĺ�������
    timer.expires= jiffies + (5 * HZ);   //��ǰjiffies��ֵ����5����֮��
    timer.function= timer_function;      //�����ʱ�˾�ִ���������
    add_timer(&timer);                   //������ʱ��
    return 0;

} 

void timer_exit()
{
    del_timer(&timer );
}

 
module_init(timer_init);
module_exit(timer_exit);
