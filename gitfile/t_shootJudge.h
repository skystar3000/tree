#ifndef _t_shootJudge_function_
#define _t_shootJudge_function_
#include "m_moto.h"
typedef enum shootJudgeState
{
	error=0,
	busy=1,
	ok=2,
	unavailable=3
}shootState_t;
extern shootState_t shootState;
extern shootState_t state_shootFunction;
extern shootState_t state_shootErrorFunction;
extern int shootWaitTime;
extern int shootErrorWaitTime;
#define limitShootWaitTime 500
#define limitShootErrorWaitTime 700
extern shootState_t shootJudge(shootState_t shootState, int* shootWaitTime, int* shootErrorWaitTime, float* Toggler_ang_set, moto_measure_t* moto_toggle);

#endif
