#ifndef STRATEGYPART_RUNNING_METHOD_H
#define STRATEGYPART_RUNNING_METHOD_H


#include "../DrivenPart/DrivenDirector.h"
#include "SwitchTerm.h"
#include "TargetValues.h"
#include "../DrivenPart/ControllerWeight.h"

#include "../StrategyPart/RunningMethodSwitchJudge/SwitchJudge.h"


typedef struct {
	
	/**
	 * �|������̗L��
	 */
	int balancing_requrement;

	/**
	 * �g�p�����
	 */
	ControllerWeight use_controller;

	/**
	 * �K���p�x
	 */
	int target_tail_angle;

	/**
	 * �W���C���I�t�Z�b�g�␳�l
	 */
	int gyroOffsetRevise;

	/**
	 * ���@�؂�ւ�����l
	 */
	SwitchTerm switch_term;

	//���@�؂�ւ��̊֐��ւ̃|�C���^
	 int (*fp_SwitchJudge)(SwitchTerm);

}RunningMethod;



	/**
	 * ���@�؂�ւ����f
	 */
	int  RunningMethod_check_executed(RunningMethod *this_RunningMethod);

	/**
	 * ���@�����s����
	 */
	void RunningMethod_execute_method(RunningMethod *this_RunningMethod,TargetValues target_value);


#endif
