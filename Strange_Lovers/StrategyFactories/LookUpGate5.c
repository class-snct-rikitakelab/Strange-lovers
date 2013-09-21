#include "LookUpGate5.h"
//#include "LookUpGate3.h"
#include "GarageIn.h"

void look_up5_factory_init(){
	ControllerWeight use_controller;
	SwitchTerm switch_term;
	int balancing_requrement =0;
	int target_tail_angle=0;
	int gyroOffsetRevise=0;
	int request_forced_stop = 0;
	MovementDirection movementDirection = FORWARD;

	int (*fp_SwitchJudge)(SwitchTerm);


	//beforelookupMethod
	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 0.0;
	switch_term.distance =	300;
	switch_term.inclination = 0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time =0;
	switch_term.distance_obstacle = 0;
	balancing_requrement = 0;
	target_tail_angle=65;
	gyroOffsetRevise=0;
	request_forced_stop =0; 
	movementDirection = FORWARD;
	fp_SwitchJudge = DistanceSwitch_judge_switch_method;
	RunningMethod_init(&doublelookupMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);



	look_up5_running_method_array[0] = doublelookupMethod;

	int number_of_running_method=1;
	TargetValues target_values; 
	target_values.target_brightness = 0.6;
	target_values.target_curvature = 0.0;
	target_values.target_speed = 180;
	Section *nextSection = &garageIn;
	Section_init(&lookup5,nextSection,number_of_running_method,look_up5_running_method_array,target_values);
}
