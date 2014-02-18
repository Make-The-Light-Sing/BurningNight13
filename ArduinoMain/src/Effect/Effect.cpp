#include "Effect.h"

/**
 * Start of step
 */
void Effect::preStep()
{
	_preStep();
}


/**
 * End of step
 */
void Effect::postStep() {
	_postStep();
	step_index ++;
	if (step_index >= step_loop) {
		step_index = 0;
		_endLoop();
	}
}

