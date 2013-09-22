#ifndef _SeesawBalanceStop_
#define _SeesawBalanceStop_

#include "../../StrategyFactories/StrategyFactories_inculude.h"
#include "SeeSaw_0Factory.h"

//StarategyPart

Section seesawbalancestop;
RunningMethod StopBalanceMethod;
RunningMethod downTailUpMethod;

RunningMethod seesaw_balancestop_method_array[2];


//Section firstCurve;


//StrategyPart/RunningMethodSwitchJudge


extern void seesaw_balance_stop_factory_init();

#endif
