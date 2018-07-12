#ifndef _t_shootJudge_function_
#define _t_shootJudge_function_

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
#define limitShootWaitTime 200
#define limitShootErrorWaitTime 500
extern shootState_t shootJudge(shootState_t shootState, int* shootWaitTime, int* shootErrorWaitTime);

#endif
