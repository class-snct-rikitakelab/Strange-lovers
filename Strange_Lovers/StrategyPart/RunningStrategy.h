#ifndef STRATEGYPART_RUNNING_STRATEGY_H
#define STRATEGYPART_RUNNING_STRATEGY_H

#include "../DrivenPart/DrivenDirector.h"
//#include "../StrategyPart/StrategySwitchJudge/SwitchJudge.h"

typedef struct {
	
	/**
	 * �|������̗L��
	 */
	int selfBalancingRequrement;

	/**
	 * �g�p�����
	 */
	int usedController;

	/**
	 * �K���p�x
	 */
	int tailAngle;

	/**
	 * �W���C���I�t�Z�b�g�␳�l
	 */
	int gyroOffsetRevise;

	/**
	 * �헪�؂�ւ�����l
	 */
	int strategyChangeDecideValue;

}RunningStrategy;

/**
 * ���s�헪
 */

	/**
	 * �헪�؂�ւ�
	 */
	void RunningStrategy_change_strategy(RunningStrategy *this_RunningStrategy);

	/**
	 * �헪�����s����
	 */
	void RunningStrategy_execute_strategy(RunningStrategy *this_RunningStrategy);

#endif
