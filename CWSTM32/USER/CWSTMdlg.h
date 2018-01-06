#ifndef  __CW_Dlg_H_
#define  __CW_Dlg_H_
#include "sys.h"
#include "data.h"
#define TOTAL_FRAME 2
#define FRAME_MAIN 0
#define FRAME_CAL 1

#define TOTAL_CTL 20
#define BUTTON_LIGHTPRESS 0
#define BUTTON_LIGHTLONG 1
#define BUTTON_OPEN2 2
#define BUTTON_OPEN3 3
#define BUTTON_OPEN4 4
#define BUTTON_OPEN5 5
#define BUTTON_HIGHTIME 6
#define BUTTON_LOWTIME 7
#define CAL_BUTTON_0 8
#define CAL_BUTTON_BACK 18
#define CAL_BUTTON_OK 19


#define Frame1_CtrlNum 4
#define FC_PRESS 0
#define FC_LONG 1
#define FC_HIGHTIME 2
#define FC_LOWTIME 3

#define Frame2_CtrlNum 12
#define Frame2_BUTTON_0 0
#define Frame2_BUTTON_BACK 10
#define Frame2_BUTTON_OK 11

#define MAX_CTL_ONFRAME 6



#define TOTAL_DATA 2
#define DATA0_LTIME 0
#define DATA1_LTIME 1
#define DATA3_CALRES 1

#define FRAME1_DATA 2
#define FRAME1_DATA0_LTIME 0
#define FRAME1_DATA1_LTIME 1


#define FRAME2_DATA 1
#define FRAME2_DATA0_RES 0


typedef struct CONTROL{
	int min[2];
	int max[2];
	int m_INDEX;
} control;
//����һ��������
typedef struct Frame{
	//һ��ָ�򱳾�ͼƬ��ָ��
	u16* background;
	//�ж��Ƿ��ڵȴ�����ʱ��
	int hadClick;
	int clickx;
	int clicky;
	int hadKey;
	//�ؼ����,��������һ����¼�
	int numOfCtrl;
	control *m_ctrl[MAX_CTL_ONFRAME];
	
	//�������,������������
	int numOfData;
	data *m_data[FRAME1_DATA];
	//�Ƿ����PWM
	int m_bpwm;
} frame;
//һ���ؼ�

void Click_Frame(frame* myframe,int x,int y );
void NClick_Frame(frame* myframe);
void KEY_Frame(frame* myframe,int key );
void NKEY_Frame(frame* myframe);
void DrawPic(frame *aframe);
void DLG_Init();
#endif