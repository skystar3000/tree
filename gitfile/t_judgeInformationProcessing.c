#include "DJ_Protocol.h"
#include "t_judgeInformationProcessing.h"
short addingHeat=250;//waiting for measurement
short coolingHeat;
short limitHeat;
short judgeHeat;
void judgeInformationProcessing(uint8_t robot_level,uint16_t robot_remainHP,uint16_t robot_maxHP,uint16_t shoot_heat17)
{
  switch(robot_level)
	{
		case 0:
			limitHeat = 1200;
			coolingHeat = 18;//10hz
		break;
		case 1:
			limitHeat = 2400;
			coolingHeat = 36;//10hz
		break;
		case 2:
			limitHeat = 4800;
			coolingHeat = 72;//10hz
		break;
		default:break;
	}
	judgeHeat = shoot_heat17;
	if(robot_remainHP*5 < robot_maxHP)
		coolingHeat *= 2;
}
