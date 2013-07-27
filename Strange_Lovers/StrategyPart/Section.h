#ifndef STRATEGYPART_SECTION_H
#define STRATEGYPART_SECTION_H

#include "../StrategyPart/RunningMethod.h"
#include "../StrategyPart/TargetValues.h"

/**
 * ���
 */

typedef struct {
	struct Section *nextSection;
	int current_running_method_number;
	int number_of_running_method;
	RunningMethod *running_methods;
	TargetValues target_value;
}Section;

	/**
	 * ����Ԃ��擾����
	 */
	struct Section* Section_get_next_section(Section *this_Section);

	/**
	 * ���j����
	 */
	int Section_clear_section(Section *this_Section,int executed_flag);

	int Section_run(Section *this_Section);

#endif
