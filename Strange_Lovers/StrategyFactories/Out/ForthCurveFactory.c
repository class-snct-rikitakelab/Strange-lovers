#include "ForthCurveFactory.h"


void forth_curve_factory_init(){
	//Section Local variables
	TargetValues target_values; 
	Section *nextSection;

	//RunningMethod Local Variables
	ControllerWeight use_controller;
	SwitchTerm switch_term={0,0,0,0,0};
	int number_of_running_method=0;
	int balancing_requrement =1;
	int target_tail_angle=0;
	int gyroOffsetRevise=0;
	int request_forced_stop = 0;
	int (*fp_SwitchJudge)(SwitchTerm);
	MovementDirection movementDirection = FORWARD;
	

	//forthCurve_1_LineTraceRunningMethod
	use_controller.target_curvature_controller_weight = 0.5;
	use_controller.target_light_controller_weight = 0.5;
	switch_term.distance =461.0737;
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;
	request_forced_stop = 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = DistanceSwitch_judge_switch_method;
	RunningMethod_init(&forthCurve_1_LineTraceRunningMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	

	//forthCurve_1 Section
	forth_curve_1_running_method_array[0]=forthCurve_1_LineTraceRunningMethod;
	number_of_running_method=1;
	target_values.target_brightness = 0.5;
	target_values.target_curvature = -1.0/700.0;
	target_values.target_speed = 400;
	nextSection= &forthCurve_2;
	Section_init(&forthCurve_1,nextSection,number_of_running_method,forth_curve_1_running_method_array,target_values);


	//forthCurve_2_LineTraceRunningMethod
	use_controller.target_curvature_controller_weight = 0.5;
	use_controller.target_light_controller_weight = 0.5;
	//switch_term.distance = 750.2846;
	switch_term.distance =900.2846;
	
	balancing_requrement = 1;
	target_tail_angle=0;
	switch_term.direction = 180;
	gyroOffsetRevise=0;
	request_forced_stop = 0;
	movementDirection = FORWARD;

	fp_SwitchJudge = DistanceSwitch_judge_switch_method;
	//fp_SwitchJudge = DirectionDistanceMultipleSwitch_judge_switch_method;
	RunningMethod_init(&forthCurve_2_LineTraceRunningMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	

	//forthCurve_2 Section
	forth_curve_2_running_method_array[0]=forthCurve_2_LineTraceRunningMethod;
	number_of_running_method=1;
	target_values.target_brightness = 0.3;
	//target_values.target_curvature = -1.0/650.0;
	target_values.target_curvature = -1.0/550.0;
	
	target_values.target_speed = 400;
	nextSection = &outFifthStraight;
	Section_init(&forthCurve_2,nextSection,number_of_running_method,forth_curve_2_running_method_array,target_values);


}
