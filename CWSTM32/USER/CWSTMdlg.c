#include "CWSTMdlg.h"
#include "imageMain.h"
#include "led.h"
#include "lcdBsp.h"
#include <stdio.h>
#include "NUM0.h"
#include "NUM1.h"
#include "NUM2.h"
#include "NUM3.h"
#include "NUM4.h"
#include "NUM5.h"
#include "NUM6.h"
#include "NUM7.h"
#include "NUM8.h"
#include "NUM9.h"
#include "CALMain.h"
#include "key.h"
frame totalFrame[TOTAL_FRAME];
control totalCTL[TOTAL_CTL];
data totaldata[TOTAL_DATA];
frame *curFrame;
int dataindex = 0;
extern u16* imgnum[10];
char showstr[104];
int min(int x,int y){
	return x<y? x: y;
}
int max(int x,int y){
	return x<y? y: x;
}

void DrawPic(frame *aframe){
	u16* i =0;
}
void DEALConTrolDOWN(int index){
		switch(index){
			case BUTTON_LIGHTPRESS: 
				//假如点击了NEXT
				LED1 = !LED1;
				break;
			default : 
				break;
		}
}
void DEALConTrolUP(int index){
	int tmp ;
		switch(index){
			case BUTTON_LIGHTPRESS: 
				//假如点击了NEXT
				LED1 = !LED1;
				//交换PWM
				tmp = totaldata[0].num;
				totaldata[0].num = totaldata[1].num;
				totaldata[1].num = tmp;
				break;
			case BUTTON_LIGHTLONG: 
				//假如点击了NEXT
				totalFrame[0].m_bpwm = !totalFrame[0].m_bpwm;
				break;
			case BUTTON_JUMP: 
				//假如点了跳一跳
				LED0 = !LED0;
				curFrame = &totalFrame[FRAME_CAL];
				LCD_Color_Fill(0,0,240-1,320-1,curFrame->background);
				curFrame->m_bJump = 1;
				curFrame->m_bpwm = 1;
				curFrame->m_bStartAJump = 0;
				break;
			case BUTTON_HIGHTIME: 
				//假如点击了高电平时间
				LED0 = !LED0;
				curFrame = &totalFrame[FRAME_CAL];
				LCD_Color_Fill(0,0,240-1,320-1,curFrame->background);
				dataindex = DATA0_LTIME;
				totalFrame[FRAME_CAL].m_data[FRAME2_DATA0_RES]->num = totaldata[dataindex].num;
				break;
			case BUTTON_LOWTIME: 
				//假如点击了低电平时间
				LED0 = !LED0;
				curFrame = &totalFrame[FRAME_CAL];
				LCD_Color_Fill(0,0,240-1,320-1,curFrame->background);
				dataindex = DATA1_LTIME;
				totalFrame[FRAME_CAL].m_data[FRAME2_DATA0_RES]->num = totaldata[dataindex].num;
				break;
			case CAL_BUTTON_0:
				LED0 = !LED0;
				totalFrame[FRAME_CAL].m_data[FRAME2_DATA0_RES]->num = totalFrame[FRAME_CAL].m_data[FRAME2_DATA0_RES]->num*10 + 0;
				break;
			case CAL_BUTTON_0+1:
				LED0 = !LED0;
				totalFrame[FRAME_CAL].m_data[FRAME2_DATA0_RES]->num = totalFrame[FRAME_CAL].m_data[FRAME2_DATA0_RES]->num*10 + 1;
				break;
			case CAL_BUTTON_0+2:
				LED0 = !LED0;
				totalFrame[FRAME_CAL].m_data[FRAME2_DATA0_RES]->num = totalFrame[FRAME_CAL].m_data[FRAME2_DATA0_RES]->num*10 + 2;
				break;
			case CAL_BUTTON_0+3:
				LED0 = !LED0;
				totalFrame[FRAME_CAL].m_data[FRAME2_DATA0_RES]->num = totalFrame[FRAME_CAL].m_data[FRAME2_DATA0_RES]->num*10 + 3;
				break;
			case CAL_BUTTON_0+4:
				LED0 = !LED0;
				totalFrame[FRAME_CAL].m_data[FRAME2_DATA0_RES]->num = totalFrame[FRAME_CAL].m_data[FRAME2_DATA0_RES]->num*10 + 4;
				break;
			case CAL_BUTTON_0+5:
				LED0 = !LED0;
				totalFrame[FRAME_CAL].m_data[FRAME2_DATA0_RES]->num = totalFrame[FRAME_CAL].m_data[FRAME2_DATA0_RES]->num*10 + 5;
				break;
			case CAL_BUTTON_0+6:
				LED0 = !LED0;
				totalFrame[FRAME_CAL].m_data[FRAME2_DATA0_RES]->num = totalFrame[FRAME_CAL].m_data[FRAME2_DATA0_RES]->num*10 + 6;
				break;
			case CAL_BUTTON_0+7:
				LED0 = !LED0;
				totalFrame[FRAME_CAL].m_data[FRAME2_DATA0_RES]->num = totalFrame[FRAME_CAL].m_data[FRAME2_DATA0_RES]->num*10 + 7;
				break;
			case CAL_BUTTON_0+8:
				LED0 = !LED0;
				totalFrame[FRAME_CAL].m_data[FRAME2_DATA0_RES]->num = totalFrame[FRAME_CAL].m_data[FRAME2_DATA0_RES]->num*10 + 8;
				break;
			case CAL_BUTTON_0+9:
				LED0 = !LED0;
				totalFrame[FRAME_CAL].m_data[FRAME2_DATA0_RES]->num = totalFrame[FRAME_CAL].m_data[FRAME2_DATA0_RES]->num*10 + 9;
				break;
			case CAL_BUTTON_BACK:
				LED0 = !LED0;
				totalFrame[FRAME_CAL].m_data[FRAME2_DATA0_RES]->num = totalFrame[FRAME_CAL].m_data[FRAME2_DATA0_RES]->num/10;
				break;
			case CAL_BUTTON_OK:
				LED0 = !LED0;
				curFrame = &totalFrame[FRAME_MAIN];
				LCD_Color_Fill(0,0,240-1,320-1,curFrame->background);
				if(curFrame->m_bJump == 1){
					curFrame->m_bJump = 0;
					break;
				}
				totaldata[dataindex].num = totalFrame[FRAME_CAL].m_data[FRAME2_DATA0_RES]->num;
				break;
			default : 
				break;
		}
}
int overlap(int *min,int *max,int x,int y){
	if(min[0]>x||max[0]<x||min[1]>y||max[1]<y)
		return 0;
	return 1;
}
void Click_Frame(frame* myframe,int x,int y ){
int cw1;
	if(myframe->hadClick == 1)
		return;
	myframe->hadClick = 1;
	myframe->clickx = x;
	myframe->clicky = y;
	for( cw1 = 0 ; cw1 < myframe->numOfCtrl;cw1++){
		if(overlap(myframe->m_ctrl[cw1]->min,myframe->m_ctrl[cw1]->max,myframe->clickx,myframe->clicky)==1)
			DEALConTrolDOWN(myframe->m_ctrl[cw1]->m_INDEX);
	}
}
void NClick_Frame(frame* myframe){
			int cw;
		if(myframe->hadClick == 0)
			return;
			myframe->hadClick = 0;
			//sprintf(showstr,"UP(%d,%d)",myframe->clickx,myframe->clicky);
			//LCD_ShowString(myframe->clickx,myframe->clicky,myframe->clickx+50,myframe->clicky+50,16,(u8*)showstr);
			for( cw = 0 ; cw < myframe->numOfCtrl;cw++){
				if(overlap(myframe->m_ctrl[cw]->min,myframe->m_ctrl[cw]->max,myframe->clickx,myframe->clicky))
					DEALConTrolUP(myframe->m_ctrl[cw]->m_INDEX);
			}
			
}
void KEY_Frame(frame* myframe,int key ){
	int tmp = 0;
		if(myframe->hadKeyClick == 1)
			return;
		myframe->hadKeyClick = 1;
		if(myframe == &totalFrame[FRAME_CAL])
		{
			switch(key){
				case KEY_RIGHT:
					LED1 = !LED1;
					tmp = totaldata[0].num;
					totaldata[0].num = totaldata[1].num;
					totaldata[1].num = tmp;
					curFrame->m_ndelayTime = totalFrame[FRAME_CAL].m_data[FRAME2_DATA0_RES]->num*0.0233*1000000 ;
					curFrame->m_bpwm = 1;
					curFrame->m_bStartAJump = 1;
					break;
			}

		}
}
void NKEY_Frame(frame* myframe){
		if(myframe->hadKeyClick == 0)
			return;
		myframe->hadKeyClick = 0;
}

void InitControl(int x1, int y1, int x2, int y2,control *ctrl,int ID){
	ctrl->min[0] = min(x1,x2);
	ctrl->min[1] = min(y1,y2);
	ctrl->max[0] = max(x1,x2);
	ctrl->max[1] = max(y1,y2);
	ctrl->m_INDEX = ID;
}
void InitData(int x, int y ,float num,data* cwdata,int ID,int numtype){
	cwdata->ID = ID;
	cwdata->x = x;
	cwdata->y = y;
	cwdata->type = 0;
	cwdata->num = num;
	cwdata->numType = numtype;
}
void Init_Num(){
	imgnum[0] = (u16*)&gImage_NUM0[0];
	imgnum[1] = (u16*)&gImage_NUM1[0];
	imgnum[2] = (u16*)&gImage_NUM2[0];
	imgnum[3] = (u16*)&gImage_NUM3[0];
	imgnum[4] = (u16*)&gImage_NUM4[0];
	imgnum[5] = (u16*)&gImage_NUM5[0];
	imgnum[6] = (u16*)&gImage_NUM6[0];
	imgnum[7] = (u16*)&gImage_NUM7[0];
	imgnum[8] = (u16*)&gImage_NUM8[0];
	imgnum[9] = (u16*)&gImage_NUM9[0];
}
void InitGroup(int* group,int x,int y,int x2, int y2){
	group[0] = x;
	group[1] = y;
	group[2] = x2;
	group[3] = y2;
	
}
void InitFrame(int i){
	totalFrame[i].hadClick = 0;
	totalFrame[i].hadKeyClick = 0;
	totalFrame[i].hadKey = 0;
	totalFrame[i].m_bpwm = 0;
	totalFrame[i].m_bJump = 0;
	totalFrame[i].m_ndelayTime = 0;
	totalFrame[i].m_bStartAJump = 0;
}
void DLG_Init(){
	//初始化全部对话框
	int i;	
	int pos[12][4];
	int index[12];
	Init_Num();
	for(i = 0 ; i < TOTAL_CTL;i++){
		totalCTL[i].m_INDEX = i;
	}
	InitFrame(FRAME_MAIN);
	totalFrame[FRAME_MAIN].background = (u16*)&gImage_imageMain[0];
	totalFrame[FRAME_MAIN].numOfData = FRAME1_DATA;
	totalFrame[FRAME_MAIN].numOfCtrl = Frame1_CtrlNum;
	//控件初始化
	totalFrame[FRAME_MAIN].m_ctrl[FC_PRESS] = &totalCTL[BUTTON_LIGHTPRESS];
	InitControl(30,105,59,133,totalFrame[FRAME_MAIN].m_ctrl[FC_PRESS],BUTTON_LIGHTPRESS);
	totalFrame[FRAME_MAIN].m_ctrl[FC_LONG] = &totalCTL[BUTTON_LIGHTLONG];
	InitControl(30,148,59,176,totalFrame[FRAME_MAIN].m_ctrl[FC_LONG],BUTTON_LIGHTLONG);
	
	totalFrame[FRAME_MAIN].m_ctrl[FC_JUMP] = &totalCTL[BUTTON_JUMP];
	InitControl(28,190,59,220,totalFrame[FRAME_MAIN].m_ctrl[FC_JUMP],BUTTON_JUMP);
	
	totalFrame[FRAME_MAIN].m_ctrl[FC_HIGHTIME] = &totalCTL[BUTTON_HIGHTIME];
	InitControl(77,109,114,179,totalFrame[FRAME_MAIN].m_ctrl[FC_HIGHTIME],BUTTON_HIGHTIME);
	totalFrame[FRAME_MAIN].m_ctrl[FC_LOWTIME] = &totalCTL[BUTTON_LOWTIME];
	InitControl(70,200,114,268,totalFrame[FRAME_MAIN].m_ctrl[FC_LOWTIME],BUTTON_LOWTIME);
	
	
	//数据初始化
	totalFrame[FRAME_MAIN].m_data[FRAME1_DATA0_LTIME] = &totaldata[DATA0_LTIME];
	InitData(81,114 ,1000,totalFrame[FRAME_MAIN].m_data[FRAME1_DATA0_LTIME],DATA0_LTIME,0);
	totalFrame[FRAME_MAIN].m_data[FRAME1_DATA1_LTIME] = &totaldata[DATA1_LTIME];
	InitData(83,207 ,1500,totalFrame[FRAME_MAIN].m_data[FRAME1_DATA1_LTIME],DATA1_LTIME,0);
	
	InitFrame(FRAME_CAL);
	totalFrame[FRAME_CAL].background = (u16*)&gImage_CALMain[0];
	totalFrame[FRAME_CAL].numOfData = FRAME2_DATA;
	totalFrame[FRAME_CAL].numOfCtrl = Frame2_CtrlNum;
	
	//初始化12个按钮的位置
	InitGroup(pos[0],88,257,124,315); InitGroup(pos[1],150,12,186,71);
	InitGroup(pos[2],151,99,186,158); InitGroup(pos[3],151,182,185,240);
	InitGroup(pos[4],88,11,124,70); InitGroup(pos[5],89,100,124,158);
	InitGroup(pos[6],89,184,124,242); InitGroup(pos[7],24,11,59,70);
	InitGroup(pos[8],25,99,61,156); InitGroup(pos[9],24,184,60,240);
	InitGroup(pos[10],150,258,185,316); InitGroup(pos[11],25,257,63,317);
	
	for(i = 0 ; i < 12;i++){
		index[i] = i + CAL_BUTTON_0;
	}
	for(i = 0 ; i < 12;i++){
		totalFrame[FRAME_CAL].m_ctrl[i] = &totalCTL[index[i]];
		InitControl(pos[i][0],pos[i][1],pos[i][2],pos[i][3],totalFrame[FRAME_CAL].m_ctrl[i],index[i]);
	}	
	
	totalFrame[FRAME_CAL].m_data[FRAME2_DATA0_RES] = &totaldata[DATA3_CALRES];
	InitData(202,25 ,0,totalFrame[FRAME_CAL].m_data[FRAME2_DATA0_RES],DATA3_CALRES,1);
}