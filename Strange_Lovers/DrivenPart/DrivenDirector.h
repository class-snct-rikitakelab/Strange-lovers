#ifndef DRIVENPART_DRIVEN_DIRECTOR_H
#define DRIVENPART_DRIVEN_DIRECTOR_H

#include "../DrivenPart/ControllerWeight.h"
#include "../DrivenPart/PID_Brightness.h"
#include "../DrivenPart/WheelActuator.h"
#include "../DrivenPart/TargetCurvatureControl/CurvatureCtrl.h"
#include "../DrivenPart/PID_Tail.h"
#include "../DrivenPart/TargetSpeedControl/SpeedCtrl.h"
#include "../DrivenPart/TargetLightValueControl/LightValCtrl.h"

#include "../logSend.h"

/**
 * �쓮�w����
 */
typedef struct{

}DrivenDirector;
	
	

void DrivenDirector_init(DrivenDirector *this_DrivenDirector);

/**
 * ����ʂ��v�Z����
 */
int DrivenDirector_calc_turn_value(DrivenDirector *this_DrivenDirector,float target_brightness, float target_curvature,ControllerWeight use_controller);

/**
 * �쓮�v��������
 */
void DrivenDirector_request_drive(DrivenDirector *this_DrivenDirector,float target_brightness, float target_curvature,int target_speed,int target_tail_angle,int self_balancing_requirement,ControllerWeight use_controller,int gyro_offset_revise);


#endif
