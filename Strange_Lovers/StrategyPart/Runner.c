#include "Runner.h"
#include "../Factory.h"

#define CYCLE_TIME 0.004


void Runner_init(Runner *this_Runner,Section *start_section){

}
void Runner_run(Runner *this_Runner){
	Section_run(this_Runner->current_section);

	if(Section_clear_section(this_Runner->current_section)){
		this_Runner->current_section = Section_get_next_section(this_Runner->current_section);
	}
}


