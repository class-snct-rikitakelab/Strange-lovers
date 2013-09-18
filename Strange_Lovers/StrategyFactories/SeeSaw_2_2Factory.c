#include "SeeSaw_2_2Factory.h"


void seesaw_2_2factory_init(){

	ControllerWeight use_controller;
	SwitchTerm switch_term;
	int balancing_requrement =0;
	int target_tail_angle=0;
	int gyroOffsetRevise=0;
	int request_forced_stop;
	MovementDirection movementDirection = FORWARD;
	int (*fp_SwitchJudge)(SwitchTerm);

	/*�ł��Ȃ�����

	use_controller.target_curvature_controller_weight =0.0; //�ȗ�����̏d�ݕt��
	use_controller.target_light_controller_weight =1.0;	//�P�x����̏d�ݕt��
	switch_term.distance = 50; //�����ؑւ��̗p�����ۂ̐ؑ֏��� [mm]
	switch_term.inclination = 0; //�X���ؑւ��̗p�����ۂ̐ؑ֏���
	switch_term.speed = 40; //���x�ؑ֏��� [mm/s]
	switch_term.time =2000; //���Ԑؑ֏��� [ms]
	balancing_requrement = 0; //�|������̗L�� 1:�|�����s 0:�K�����s ���킹�ĐK���p�x���X�T�x���x�ɂ���K�v����
	target_tail_angle=100; //�K���̖ڕW�p�x
	gyroOffsetRevise=0; //�W���C���I�t�Z�b�g�ύX�ʁ@+�����ɑ��₷�Ƌ}���� -�����ɑ��₷�Ƌ}�����@���������Z���`���x�i�񂾒i�K�ŃI�t�Z�b�g��߂��Ȃ��ƃo�����X������ē]�|����
	request_forced_stop= 0; //���S�ɒ�~�������ꍇ��1 �ʏ�̐�����|����ꍇ��0
	movementDirection = FORWARD; //�i�s�����ɏ]���Đݒ肷��@�O�i FORWARD ���BACKWARD
	fp_SwitchJudge = DistanceSwitch_judge_switch_method; //�ؑւ𔻒肷��֐������w��@
	/*
	�����ؑ� DistanceSwitch_judge_switch_method
	���Ԑؑ� TTimeSwitch_judge_switch_method
	�Ȃ�
	*/

	//RunningMethod_init(&runningforwardMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);

	//�q�V����̂����R�s�y
	
	//tailMoveRunningMethod
	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 0.0;
	switch_term.distance =0 ;
	switch_term.inclination = 0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time =250;
	//switch_term.tail_angle=130;		//119;
	balancing_requrement = 0;
	target_tail_angle=125;

	gyroOffsetRevise=0;
	request_forced_stop = 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = TimeSwitch_judge_switch_method;
	RunningMethod_init(&tailplusmovingMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	

	//tailBackRunningMethod

	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 0.0;
	switch_term.distance =0 ;
	switch_term.inclination = 0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time = 200;
	//switch_term.tail_angle=0;
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;		
	request_forced_stop = 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = TimeSwitch_judge_switch_method;
	RunningMethod_init(&tailbackMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	

/*
	
	//tailplusmovingMethod
	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 0.0;
	switch_term.distance = 0;
	switch_term.inclination = 0;
	switch_term.inPushed = 1;
	switch_term.speed = 0;
	switch_term.time =200;
	switch_term.tail_angle =119;
	balancing_requrement = 0;
	target_tail_angle=119;
	gyroOffsetRevise=0;
	request_forced_stop= 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = TimeSwitch_judge_switch_method;
	RunningMethod_init(&tailplusmovingMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	
	//tailbackMethod
	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 0.0;
	switch_term.distance = 0;
	switch_term.inclination = 0;
	switch_term.inPushed = 1;
	switch_term.speed = 0;
	switch_term.time =200;
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;
	request_forced_stop= 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = TimeSwitch_judge_switch_method;
	RunningMethod_init(&tailbackMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	
	*/

	//seesaw_2_2running_method_array[0]=runningforwardMethod;
	seesaw_2_2running_method_array[0]=tailplusmovingMethod;
	seesaw_2_2running_method_array[1]=tailbackMethod;


	int number_of_running_method=2;
	TargetValues target_values; 
	target_values.target_brightness = 0.5;
	target_values.target_curvature = 0.0;
	target_values.target_speed = 0;
	Section *nextSection = &seesaw_5;
	RunningMethod *runningMethod = seesaw_2_2running_method_array;
	Section_init(&seesaw_2_2,nextSection,number_of_running_method,runningMethod,target_values);
	
}
