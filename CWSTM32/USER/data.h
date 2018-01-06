#ifndef  __CW_DATA_H_
#define  __CW_DATA_H_
//其它定义
#define CWX 0
#define CWY 1
#define NUMW 16
#define NUMH 11

typedef struct DATA{
	int type;
	int x;
	int y;
	int ID;
	int num;
	int numType;
}data;
void DrawData(data* cwdata);
#endif