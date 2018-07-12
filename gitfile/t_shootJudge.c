#include "t_shootJudge.h"
#include "t_heatControl.h"
#include "t_judgeInformationProcessing.h" 
#include "m_moto.h"

//extern short addingHeat;
extern float Toggler_ang_set;
int shootWaitTime = 0;
int shootErrorWaitTime = 0;
shootState_t state_shootFunction = unavailable;
shootState_t state_shootErrorFunction = unavailable;
shootState_t shootState = unavailable;
shootState_t shootJudge(shootState_t shootState, int* shootWaitTime, int* shootErrorWaitTime)
{
	if(shootState != error)
	{
		if(shootState != busy)
		{
			if(allowShootNum == 0)
				shootState = unavailable;//��������
		}
		else{
			if(state_shootFunction == ok)//�����ɹ�
			{
				shootState = ok;
				allowShootNum --;
				nowHeat += addingHeat;
				moto_toggle.offset_angle = moto_toggle.total_angle;//����λ��
				Toggler_ang_set = 0;
				*shootWaitTime = 0;
			}
			else{
				if(*shootWaitTime > limitShootWaitTime)//ms
				{
					shootState = error;//��������
					moto_toggle.offset_angle = moto_toggle.total_angle;//����λ��
					Toggler_ang_set = 0;
					*shootWaitTime = 0;
				}
				else
					shootState = busy;
			}
		}
	}
  else{
		if(state_shootErrorFunction == ok)//�����������ɹ�
		{
			shootState = busy;
			moto_toggle.offset_angle = moto_toggle.total_angle;//����λ��
			Toggler_ang_set = 0;
			*shootErrorWaitTime = 0;
		}
		else{
			if(*shootErrorWaitTime > limitShootErrorWaitTime)//ms
			{
				shootState = unavailable;//���������޷����
				moto_toggle.offset_angle = moto_toggle.total_angle;//����λ��
				Toggler_ang_set = 0;
				*shootErrorWaitTime = 0;
			}
			else
				shootState = error;
		}
	}

	return shootState;
}
