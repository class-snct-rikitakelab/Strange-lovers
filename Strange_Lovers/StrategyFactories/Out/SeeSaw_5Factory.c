#include "SeeSaw_5Factory.h"


void seesaw_5_factory_init(){
	ControllerWeight use_controller;
	SwitchTerm switch_term;
	int balancing_requrement =0;
	int target_tail_angle=0;
	int gyroOffsetRevise=0;
	int request_forced_stop;
	MovementDirection movementDirection = FORWARD;
	int (*fp_SwitchJudge)(SwitchTerm);

	use_controller.target_curvature_controller_weight =0.85;
	use_controller.target_light_controller_weight =0.15;
	switch_term.inclination = 0;
	switch_term.speed = 40;
	switch_term.time =100000;
	balancing_requrement = 0;
	target_tail_angle=100;
	gyroOffsetRevise=0;
	request_forced_stop= 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = TimeSwitch_judge_switch_method;
	/*
	距離切替 DistanceSwitch_judge_switch_method
	時間切替 TimeSwitch_judge_switch_method
	など
	*/

	RunningMethod_init(&SeesawFinalStopMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);


	seesaw_5_running_method_array[0]=SeesawFirstLineTraceMethod; //実施する走法を配列順番に格納

	int number_of_running_method=1; //区間で実施する走法の個数
	TargetValues target_values;  
	target_values.target_brightness = 0.4; //目標輝度
	target_values.target_curvature = 0.0; //目標曲率 [1/mm]
	target_values.target_speed = -5;  //目標速度 [mm/s]
	Section *nextSection = &startUp; //次の区間
	RunningMethod *runningMethod = seesaw_1_running_method_array;
	Section_init(&seesaw_5,nextSection,number_of_running_method,runningMethod,target_values);
}
