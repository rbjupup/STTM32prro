/*  main.c  */

#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "LcdBsp.h"
#include "LcdApi.h"
#include "image.h"
#include "imageMain.h"
#include "imageBackGround.h"
/***********************************************************************/
//�˳����������߲ʹ���̫��M3��STM32F103�����弰���ּ��ݵ�STM32ϵͳ��
//ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;��
/***********************************************************************/
 
 
	u16* imageGroup[3];
	int i = 0;
int main(void)
{
	//u32 i=0;
	delay_init();	    //��ʱ������ʼ��
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	LED_Init();
	USART1_Init(115200);//����1��ʼ��
	
	LCD_Init();	
	POINT_COLOR = RED;
	LCD_ShowString(20,150,220,24,24,"STM32 LCD Test !");//��ʾ�ַ���
	
	Show_Str(20,20,220,12,"�߲ʹ��� ̫��M3������",12,0);//������ʾ
	Show_Str(20,40,220,16,"�߲ʹ��� ̫��M3������",16,0);//������ʾ
	Show_Str(20,65,220,24,"�߲ʹ��� ̫��M3������",24,0);//������ʾ
	
	delay_ms(1000);
	delay_ms(1000);
	
	//LCD_Fill(20,150,20+220,150+24,WHITE);
	
	

	
	imageGroup[0] = (u16*)&gImage_image2[0];
	imageGroup[1] = (u16*)&gImage_image[0];
	imageGroup[2] = (u16*)&gImage_imageBackGround[0];
	
	
	while(1)
	{
		LED_TOGGLE(LED0);
		for( i = 0 ; i < 3;i++){
				LCD_Color_Fill(0,0,240-1,320-1,imageGroup[i]);//������ǿ��ת��Ϊu16*,ע��ͼ���С���ܳ�����,������ܻ��ܷ�
				delay_ms(500);
		}


	}
}




