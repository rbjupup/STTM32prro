#ifndef  __CW_Dlg_H_
#define  __CW_Dlg_H_
#include "sys.h"
#include "data.h"
#define TOTAL_FRAME 2
#define FRAME_MAIN 0
#define FRAME_CAL 1

#define TOTAL_CTL 21
#define BUTTON_LIGHTPRESS 0
#define BUTTON_LIGHTLONG 1
#define BUTTON_JUMP 2
#define BUTTON_OPEN3 3
#define BUTTON_OPEN4 4
#define BUTTON_OPEN5 5
#define BUTTON_HIGHTIME 6
#define BUTTON_LOWTIME 7
#define CAL_BUTTON_0 8
#define CAL_BUTTON_BACK 18
#define CAL_BUTTON_OK 19
#define BUTTON_MODE 20


#define Frame1_CtrlNum 6
#define FC_PRESS 0
#define FC_LONG 1
#define FC_JUMP 2
#define FC_HIGHTIME 3
#define FC_LOWTIME 4
#define FC_MODE 5

#define Frame2_CtrlNum 12
#define Frame2_BUTTON_0 0
#define Frame2_BUTTON_BACK 10
#define Frame2_BUTTON_OK 11

#define MAX_CTL_ONFRAME TOTAL_CTL



#define TOTAL_DATA 4
#define DATA0_LTIME 0
#define DATA1_LTIME 1
#define DATA3_CALRES 2
#define DATA3_MODE 3

#define FRAME1_DATA 3
#define FRAME1_DATA0_LTIME 0      
#define FRAME1_DATA1_LTIME 1    
#define FRAME1_DATA2_MODE 2


#define FRAME2_DATA 1
#define FRAME2_DATA0_RES 0


typedef struct CONTROL{
	int min[2];
	int max[2];
	int m_INDEX;
} control;
//定义一个界面类
typedef struct Frame{
	//一个指向背景图片的指针
	u16* background;
	//判断是否在等待移走时间
	int hadClick;
	//判断是否按键
	int hadKeyClick;
	int clickx;
	int clicky;
	int hadKey;
	int KeyVal;
	
	//控件相关,用来处理一点击事件
	int numOfCtrl;
	control *m_ctrl[MAX_CTL_ONFRAME];
	
	//数据相关,用来保存数据
	int numOfData;
	data *m_data[FRAME1_DATA];
	//是否输出PWM
	int m_bpwm;
	int m_pwmMode;
	//跳一跳外挂相关
	int m_bJump;
	int m_ndelayTime;
	int m_bStartAJump;
} frame;
//一个控件

void Click_Frame(frame* myframe,int x,int y );
void NClick_Frame(frame* myframe);
void KEY_Frame(frame* myframe,int key );
void NKEY_Frame(frame* myframe);
void DrawPic(frame *aframe);
void DLG_Init();
#endif