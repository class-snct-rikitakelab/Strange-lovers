#include "Slope2Factory.h"


void slope2_factory_init(){
	
	//RunningMethod


	//slopeDownRunningMethod
	slopeDownRunningMethod.balancing_requrement = 1;
	slopeDownRunningMethod.fp_SwitchJudge= DistanceSwitch_judge_switch_method;
	slopeDownRunningMethod.gyroOffsetRevise = 0;
	
	slopeDownRunningMethod.switch_term.distance = 150;
	slopeDownRunningMethod.switch_term.inclination = 0;
	slopeDownRunningMethod.switch_term.time = 0;
	
	slopeDownRunningMethod.target_tail_angle=0;
	slopeDownRunningMethod.use_controller.target_curvature_controller_weight= 0.5;
	slopeDownRunningMethod.use_controller.target_light_controller_weight = 0.5;
	slopeDownRunningMethod.movementDirection = FORWARD;

	//slopeDown2RunningMethod
	slopeDown2RunningMethod.balancing_requrement = 1;
	slopeDown2RunningMethod.fp_SwitchJudge= DistanceSwitch_judge_switch_method;
	slopeDown2RunningMethod.gyroOffsetRevise = 9;
	
	slopeDown2RunningMethod.switch_term.distance = 1050;
	slopeDown2RunningMethod.switch_term.inclination = 0;
	slopeDown2RunningMethod.switch_term.time = 0;
	
	slopeDown2RunningMethod.target_tail_angle=0;
	slopeDown2RunningMethod.use_controller.target_curvature_controller_weight= 0.5;
	slopeDown2RunningMethod.use_controller.target_light_controller_weight = 0.5;
	slopeDown2RunningMethod.movementDirection = FORWARD;

	
	slope2_running_method_array[0]=slopeDownRunningMethod;
	slope2_running_method_array[1]=slopeDown2RunningMethod;
	
	slope2.current_running_method_number=0;
	slope2.number_of_running_method=2;
	slope2.running_methods=slope2_running_method_array;

	slope2.target_values.target_brightness=0.5;
	slope2.target_values.target_curvature=0.0;
	slope2.target_values.target_speed=300;
	
	slope2.nextSection = &afterSlopeStraight;

}
