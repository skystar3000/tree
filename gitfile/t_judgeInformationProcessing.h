#ifndef _t_judgeInformationProcessing_function_
#define _t_judgeInformationProcessing_function_

#include <stdint.h>
extern short addingHeat;//or #define
extern short coolingHeat;
extern short limitHeat;
extern short judgeHeat;
extern void judgeInformationProcessing(uint8_t robot_level,uint16_t robot_remainHP,uint16_t robot_maxHP,uint16_t shoot_heat17);

#endif
