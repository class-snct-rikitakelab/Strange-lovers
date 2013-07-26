#ifndef STRATEGYPART_SECTION_H
#define STRATEGYPART_SECTION_H

#include "../StrategyPart/RunningStrategy.h"
#include "../StrategyPart/changeTerm.h"


/**
 * ���
 */

typedef struct {
	/**
	 * �ڕW�O�i���x
	 */
	int targetSpeed;

	/**
	 * �ȗ����a
	 */
	float target_curvature;
	int target_brightness;
	struct Section *nextSection;
	RunningStrategy runningStrategy[];
	
}Section;

	/**
	 * ����Ԑؑ֏����擾
	 */
	changeTerm Section_getChangeTermOfNextSection();

	/**
	 * ����Ԃ��擾����
	 */
	Section Section_getNextSection();

	/**
	 * ���j����
	 */
	int Section_clearSection();

	void Section_run();

#endif
