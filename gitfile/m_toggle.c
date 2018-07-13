#include  "m_toggle.h"
#include "t_remote.h"
#include "pid.h"
#include "t_shootJudge.h"
float Toggler_ang_set = 0;
float speedtest=0;

int Toggler_working_time;
float Backangle=0;
float error1=0;
float error2=0;


#define error1_limit 1*8192/360*36
void Toggler_ctr(void)
{
	if(shootState == busy)
	{
		if(0 == Toggler_ang_set)
			Toggler_ang_set += Toggler_angle_one;
		pid_calc(&pid_Toggler_ang, moto_toggle.total_angle-moto_toggle.offset_angle, Toggler_ang_set);
		pid_calc(&pid_Toggler_spd, moto_toggle.speed_rpm, pid_Toggler_ang.pos_out);
		if( pid_Toggler_ang.err[NOW]<error1_limit && pid_Toggler_ang.err[NOW]>-error1_limit)
			state_shootFunction = ok;
		else
			state_shootFunction = unavailable;
	}
	else{
		state_shootFunction = unavailable;
		if(shootState != error)
		{
			pid_calc(&pid_Toggler_ang, 0, 0);
		  pid_calc(&pid_Toggler_spd, moto_toggle.speed_rpm, 0);
		}
	}
}

#define error2_limit 1*8192/360*36
void Toggler_error_ctr(void)
{
	if(shootState == error)
	{
		if(0 == Toggler_ang_set)
			Toggler_ang_set -= Toggler_angle_one;//反转
		pid_calc(&pid_Toggler_ang, moto_toggle.total_angle-moto_toggle.offset_angle, Toggler_ang_set);
		pid_calc(&pid_Toggler_spd, moto_toggle.speed_rpm, pid_Toggler_ang.pos_out);
		if( pid_Toggler_ang.err[NOW]<error2_limit && pid_Toggler_ang.err[NOW]>-error2_limit)
		{
			state_shootErrorFunction = ok;
			Toggler_ang_set += Toggler_angle_one;//错误解决重新进入射击状态
		}
		else
			state_shootErrorFunction = unavailable;
	}
	else{
		state_shootErrorFunction = state_shootErrorFunction;
	  if(shootState != busy)
		{
			pid_calc(&pid_Toggler_ang, 0, 0);
		  pid_calc(&pid_Toggler_spd, moto_toggle.speed_rpm, 0);
		}
	}
}

