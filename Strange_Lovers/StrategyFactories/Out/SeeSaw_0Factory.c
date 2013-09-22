#include "SeeSaw_0Factory.h"


void seesaw_0_factory_init(){
	ControllerWeight use_controller;
	SwitchTerm switch_term;
	int balancing_requrement =0;
	int target_tail_angle=0;
	int gyroOffsetRevise=0;
	int request_forced_stop;
	MovementDirection movementDirection = FORWARD;
	int (*fp_SwitchJudge)(SwitchTerm);

	use_controller.target_curvature_controller_weight = 0.5;
	use_controller.target_light_controller_weight = 0.5;
	switch_term.distance = 1200.0619;
	switch_term.inclination = 100;
	balancing_requrement = 0;
	target_tail_angle=100;
	gyroOffsetRevise=0;
	request_forced_stop = 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = DistanceSwitch_judge_switch_method;
	RunningMethod_init(&Magaru_curveMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	
	seesaw_0_running_method_array[0]=Magaru_curveMethod; //À{‚·‚é‘––@‚ğ”z—ñ‡”Ô‚ÉŠi”[

	int number_of_running_method=1; //‹æŠÔ‚ÅÀ{‚·‚é‘––@‚ÌŒÂ”
	TargetValues target_values;  
	target_values.target_brightness = 0.5; //–Ú•W‹P“x
	target_values.target_curvature = 0.0; //–Ú•W‹È—¦ [1/mm]
	target_values.target_speed = 100;  //–Ú•W‘¬“x [mm/s]
	Section *nextSection = &seesaw_Upslope; //Ÿ‚Ì‹æŠÔ
	RunningMethod *runningMethod = seesaw_0_running_method_array;

	Section_init(&seesaw_0,nextSection,number_of_running_method,runningMethod,target_values);
}
