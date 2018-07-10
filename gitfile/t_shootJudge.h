#ifndef _t_shootJudge_function_
#define _t_shootJudge_function_

typedef enum shootJudgeState
{
	error=0,
	busy=1,
	available=2,
	unavailable=3,
	ok=4
}shootState_t;
extern shootState_t shootState;
#define limitShootWaitTime 100
extern shootState_t shootJudge(shootState_t shootState, short shootWaitTime);

#endif
