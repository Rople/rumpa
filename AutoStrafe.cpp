#include "AutoStrafe.h"

void CAutoStrafe::Do() {
	if (!(G::pLocalPlayer->GetFlags() & FL_ONGROUND)) {
		if (G::Cmd->mousedx > 0)
			G::Cmd->sidemove = 10000.0f;
		else if (G::Cmd->mousedx < 0)
			G::Cmd->sidemove = -10000.0f;
	}
}