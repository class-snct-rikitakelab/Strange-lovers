#ifndef _WheelActuator_H_
#define _WheelActuator_H_

#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"
//#include "balancer.h"
#include "/cygdrive/c/cygwin/nxtOSEK/ecrobot/nxtway_gs_balancer/balancer.h"
#include "WheelMotor.h"
#include "../EncoderPart/InclinationEncoder.h"


typedef struct{
	S8 forward;
	S8 turn;
	U32	gyro_offset;
	int self_balancing_requirment;
}WheelActuator;


extern void WheelActuator_init(WheelActuator *this_WheelActuator);
extern void WheelActuator_balance_running(WheelActuator *this_WheelActuator,S8 *pwm_l,S8 *pwm_r);
extern void WheelActuator_set_forward(WheelActuator *this_WheelActuator , S8 forward);
extern void WheelActuator_set_turn(WheelActuator *this_WheelActuator , S8 turn);
extern void WheelActuator_tail_running(WheelActuator *this_WheelActuator,S8 *pwm_l,S8 *pwm_r);
extern void WheelActuator_dirve_motors(WheelActuator *this_WheelActuator);
void WheelActuator_set_self_balancing_requirement(WheelActuator *this_WheelActuator,int self_balancing_requirment);

#endif
