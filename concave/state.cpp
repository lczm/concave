#include "state.h"

void State::updateFrameNo(float frameTime)
{
	timer += frameTime;
	if (timer >= delay) {
		timer -= delay;
		frameNo++;
		if (frameNo >= endFrame) {
			frameNo = 0;
		}
	}
}
