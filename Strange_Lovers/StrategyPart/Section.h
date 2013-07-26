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
	
	struct Section *nextSection;
	RunningStrategy current_strategy;
	
}Section;

	/**
	 * ����Ԑؑ֏����擾
	 */
	changeTerm Section_getChangeTermOfNextSection(Section *this_Section);

	/**
	 * ����Ԃ��擾����
	 */
	Section Section_getNextSection(Section *this_Section);

	/**
	 * ���j����
	 */
	int Section_clearSection(Section *this_Section);

	void Section_run(Section *this_Section);

#endif
