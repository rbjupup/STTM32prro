#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"	 
#include "24cxx.h"
#include "flash.h"
#include "touch.h"
#include "LcdApi.h"
#include "lcdBsp.h"
#include "CWSTMdlg.h"
//#include "0.h"
#include "image.h"
//ALIENTEKս��STM32������ʵ��26
//������ ʵ��  
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾  	

extern frame totalFrame[TOTAL_FRAME];
extern frame *curFrame;
void MainCircle();
void Load_Drow_Dialog(void)
{
	LCD_Clear(WHITE);//����   
 	POINT_COLOR=BLUE;//��������Ϊ��ɫ 
	LCD_ShowString(lcddev.width-24,0,200,16,16,"RST");//��ʾ��������
  	POINT_COLOR=RED;//���û�����ɫ 
}
	u16* imageGroup[3];
	int i = 0;
int main(void)
{	 	
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_Configuration(); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 	//���ڳ�ʼ��Ϊ9600
 	LED_Init();			     //LED�˿ڳ�ʼ��
	LCD_Init();	
	KEY_Init();	 
 	POINT_COLOR=RED;//��������Ϊ��ɫ 
	LCD_ShowString(60,50,200,16,16,"WarShip STM32");	
	LCD_ShowString(60,70,200,16,16,"TOUCH TEST");	
	LCD_ShowString(60,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(60,110,200,16,16,"2012/9/11");
  LCD_ShowString(60,130,200,16,16,"Press KEY0 to Adjust");	
 	tp_dev.init();
	 
	 
//	delay_ms(1500);
//	Load_Drow_Dialog();
//	delay_ms(1500); 
//	while(1)
//	{
//		int key = 0;
//	 	key=KEY_Scan(0);
//		tp_dev.scan(0); 		 
//		if(tp_dev.sta&TP_PRES_DOWN)			//������������
//		{	
//		 	if(tp_dev.x<lcddev.width&&tp_dev.y<lcddev.height)
//			{	
//				if(tp_dev.x>(lcddev.width-24)&&tp_dev.y<16)Load_Drow_Dialog();//���
//				else {
//					TP_Draw_Big_Point(tp_dev.x,tp_dev.y,RED);		//��ͼ
////					LCD_ShowString(tp_dev.x,tp_dev.y,tp_dev.x+50,tp_dev.x+50,16,"CW");
//				}	  			   
//			}
//		}else delay_ms(10);	//û�а������µ�ʱ�� 	    
//		if(key==KEY_RIGHT)	//KEY_RIGHT����,��ִ��У׼����
//		{
//			LCD_Clear(WHITE);//����
//		    TP_Adjust();  //��ĻУ׼ 
//			TP_Save_Adjdata();	 
//			Load_Drow_Dialog();
//		}
//		i++;
//		if(i==20)
//		{
//			i=0;
//			LED0=!LED0;
//		}
//	}
//	imageGroup[0] = (u16*)&gImage_imageMain1[0];
//	LCD_Color_Fill(0,0,240-1,320-1,imageGroup[0]);//������ǿ��ת��Ϊu16*,ע��ͼ���С���ܳ�����,������ܻ��ܷ� 
	DLG_Init();
	MainCircle();

}


void MainCircle()
{
	u8 key;
	int j;
	curFrame = &totalFrame[FRAME_MAIN];
	LCD_Color_Fill(0,0,240-1,320-1,curFrame->background);//������ǿ��ת��Ϊu16*,ע��ͼ���С���ܳ�����,������ܻ��ܷ�
	i = 99;
//		while(1)
//	{
//	 	key=KEY_Scan(0);
//		tp_dev.scan(0); 		 
//		if(tp_dev.sta&TP_PRES_DOWN)			//������������
//		{	
//		 	if(tp_dev.x<lcddev.width&&tp_dev.y<lcddev.height)
//			{				
//  			   Click_Frame(curFrame,tp_dev.x,tp_dev.y);
//			}
//		}else {
//				NClick_Frame(curFrame);	
//		} 

//		if(key>0&&key<5)
//		{
//				KEY_Frame(curFrame,key);
//		}
//		else
//		{
//				NKEY_Frame(curFrame);
//		}
//		
//		//��ʱˢ������
//		i++;
//		if(i>40000)
//		{
//			i=0;
//			for(j =0 ; j < curFrame->numOfData;j++)
//				DrawData(curFrame->m_data[j]);
//		}
//		if(curFrame->m_bpwm == 1){
//			PBout(2) = 1;
//			delay_us(curFrame->m_data[FRAME1_DATA0_LTIME]->num);
//			PBout(2) = 0;
//			delay_us(curFrame->m_data[FRAME1_DATA1_LTIME]->num);
//			i += 10000;
//		}
//	}
}

//				if(tp_dev.x>(lcddev.width-24)&&tp_dev.y<16)Load_Drow_Dialog();//���
//				else {
//					TP_Draw_Big_Point(tp_dev.x,tp_dev.y,RED);		//��ͼ
//					LCD_ShowString(tp_dev.x,tp_dev.y,tp_dev.x+50,tp_dev.x+50,16,"CW");
//				}	
//if(key==KEY_RIGHT)	//KEY_RIGHT����,��ִ��У׼����
//		{
//			LCD_Clear(WHITE);//����
//		    TP_Adjust();  //��ĻУ׼ 
//			TP_Save_Adjdata();	 
//			Load_Drow_Dialog();
//		}