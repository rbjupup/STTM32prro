#include "data.h"
#include "LcdApi.h"
#include "lcdBsp.h"
u16* imgnum[10];
void splitToNUM(int num,int* res){
	res[0] = num%100000/10000;
	res[1] = num%10000/1000;
	res[2] = num%1000/100;
	res[3] = num%100/10;
	res[4] = num%10/1;
}
void DrawData(data* cwdata){
	int res[5];
	splitToNUM(cwdata->num,res);
	switch(cwdata->type){
		case 0: //¼ÙÈçÊÇÊý×Ö
			LCD_Color_Fill(cwdata->x,cwdata->y,cwdata->x + NUMW - 1 ,cwdata->y + NUMH - 1,imgnum[res[0]]);
			LCD_Color_Fill(cwdata->x,cwdata->y + NUMH  ,cwdata->x + NUMW - 1 ,cwdata->y + 2 * NUMH - 1,imgnum[res[1]]);
			LCD_Color_Fill(cwdata->x,cwdata->y + 2*NUMH,cwdata->x + NUMW - 1 ,cwdata->y + 3 * NUMH - 1,imgnum[res[2]]);
			LCD_Color_Fill(cwdata->x,cwdata->y + 3*NUMH,cwdata->x + NUMW - 1 ,cwdata->y + 4 * NUMH - 1,imgnum[res[3]]);
			LCD_Color_Fill(cwdata->x,cwdata->y + 4*NUMH,cwdata->x + NUMW - 1 ,cwdata->y + 5 * NUMH - 1,imgnum[res[4]]);
			break;
		case 1:
			break;
	}
}