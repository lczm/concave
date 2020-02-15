#include "fsmSystem.h"

void updateFSMArray(Level* level, int size, vector<FSM> fsmArray)
{
	for (int i = 0; i < size; i++) {
		fsmArray[i](level, i);
	}
}