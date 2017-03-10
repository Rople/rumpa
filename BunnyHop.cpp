#include "BunnyHop.h"

void CBunnyHop::Do() {
	if (G::pLocalPlayer->GetFlags() & FL_ONGROUND)
		G::Cmd->buttons |= IN_JUMP;
	else
		G::Cmd->buttons &= ~IN_JUMP;
}