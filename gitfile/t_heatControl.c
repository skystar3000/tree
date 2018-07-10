#include "t_heatControl.h"
#include "t_shootJudge.h"
//short addingHeat;
//short coolingHeat;
//short limitHeat;
//short judgeHeat;
//short coolingWaitTime;

short nowHeat=0;
short allowShootNum=0;
short heatControl(short addingHeat, short coolingHeat, short limitHeat, short judgeHeat, short coolingWaitTime)
{
	if(coolingWaitTime == 100)//ms;10hz heatCooling
	{
		coolingWaitTime = 0;
		if(nowHeat>0)
			nowHeat -= coolingHeat;
	}
	if(judgeHeat > limitHeat)//此时可能出现滑弹现象
	{
		allowShootNum = 0;
		nowHeat = judgeHeat;
		shootState = unavailable;//终止射击
	}
	else{
		if(nowHeat > limitHeat)
			allowShootNum = 0;
		else
			allowShootNum = (limitHeat - nowHeat)/addingHeat;
	}
	return allowShootNum;
}
