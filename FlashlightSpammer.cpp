#include "FlashlightSpammer.h"


void CFlashlightSpammer::Do() {
	G::pEngineClient->ClientCmd("impulse 100");
}
