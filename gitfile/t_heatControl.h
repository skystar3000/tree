#ifndef _t_heatControl_function_
#define _t_heatControl_function_
extern int coolingWaitTime;
extern short nowHeat;
extern short allowShootNum;
extern short heatControl(short addingHeat, short coolingHeat, short limitHeat, short judgeHeat, int* coolingWaitTime);

#endif
