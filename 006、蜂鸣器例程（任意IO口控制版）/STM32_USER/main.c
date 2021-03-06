
#include "sys.h"
#include "delay.h"
#include "beep.h"

/***********************************************************************/
//此程序适用于七彩光子太极M3—STM32F103开发板及部分兼容的STM32系统，
//只供学习使用，未经作者许可，不得用于其它任何用途！
/***********************************************************************/
 

/*

特别说明:
    此程序与前一个蜂鸣器例程唯一的区别就是将控制蜂鸣器的IO口由PB8改成了PB10,目的是(重点!!!!!)往下看。
此实验时实验时需要用杜邦线将PB10与蜂鸣器跳线的上方连接,这个程序的目的就是为了提醒大家,我们没有将蜂鸣
器直接与单片机相连,而是在硬件上设置了一个跳线,通过跳线帽连接,这样做的目的有两个:
    1、在其他程序用到PB8的时候可以将蜂鸣器的跳线帽拔掉,避免蜂鸣器乱叫;
		2、可以通过杜邦线将蜂鸣器连接到任何IO口,通过蜂鸣器的声音就可以知道IO口的状态,从而判断程序的配置
是否正确,在手头没有万用表的时候尤其方便。

*/
int main(void)
{
	delay_init();	    //延时函数初始化
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
	Beep_Init();
	while(1)
	{
		BEEP_ON();
		delay_ms(100);
		BEEP_TOGGLE();
		delay_ms(200);
		BEEP_TOGGLE();
		delay_ms(100);
		BEEP_TOGGLE();
		delay_ms(100);
		BEEP_TOGGLE();
		delay_ms(100);
		BEEP_OFF();
		delay_ms(1000);
	}
}




