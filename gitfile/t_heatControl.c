#include "t_heatControl.h"
#include "t_shootJudge.h"
//short addingHeat;
//short coolingHeat;
//short limitHeat;
//short judgeHeat;
int coolingWaitTime = 0;
short nowHeat=0;
short allowShootNum=0;
short heatControl(short addingHeat, short coolingHeat, short limitHeat, short judgeHeat,
	                int* coolingWaitTime, short* nowHeat, shootState_t* shootState) 
{
	if(*coolingWaitTime > 100)//ms;10hz heatCooling
	{
		*coolingWaitTime = 0;
		if(*nowHeat>0)
			*nowHeat -= coolingHeat;
		else
			*nowHeat = 0;
	}
	if(judgeHeat > limitHeat)//此时可能出现滑弹现象
	{
		allowShootNum = 0;
		*nowHeat = judgeHeat;//更新本地数据
		*shootState = unavailable;//终止射击
	}
	else{
		if(*nowHeat > limitHeat)
			allowShootNum = 0;
		else
			allowShootNum = (limitHeat - *nowHeat)/addingHeat;
	}
	return allowShootNum;
}
