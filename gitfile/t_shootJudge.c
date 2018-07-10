#include "t_shootJudge.h"
#include "t_heatControl.h"
#include "t_judgeInformationProcessing.h"
//shootState_t state_shootFunction = ok;
//shootState_t state_shootErrorFunction = ok;
//short shootWaitTime;
//extern short addingHeat;

shootState_t shootState = available;
shootState_t shootJudge(shootState_t shootState, short shootWaitTime)
{
	if(shootState != error)
	{
		if(shootState != busy)
		{
			if(allowShootNum == 0)
				shootState = unavailable;
			else{
				shootState = busy;
				allowShootNum --;
			}
		}
		else{
			if(state_shootFunction == ok)
			{
				shootState = available;
				nowHeat += addingHeat;
			}
			else{
				if(shootWaitTime > limitShootWaitTime)
				{
					shootState = error;
					shootWaitTime = 0;
				}
			}
		}
	}
    else{
		if(state_shootErrorFunction == ok)
			shootState = busy;
		else
			shootState = error;
	}

	return shootState;
}
