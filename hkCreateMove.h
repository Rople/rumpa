#pragma once

#ifndef HKCREATEMOVE
#define HKCREATEMOVE

#include "QAngle.h"
#include "Misc.h"
#include "Globals.h"

typedef bool(__stdcall* CreateMoveFn)(float, CUserCmd*);
CreateMoveFn origCreateMove;


QAngle realView;

bool __stdcall hkCreateMove(float flTime, CUserCmd* cmd) {
	if (!G::pEngineClient->IsConnected() || !G::pEngineClient->IsInGame())
		return false;

	G::Cmd = cmd;
	G::pLocalPlayer = G::pClientEntityList->GetClientEntity(G::pEngineClient->GetLocalPlayer());
	G::pAimbot->m_bIsAimbotting = false;

	realView.p = realView.p + (float)(G::Cmd->mousedy * 0.022f);
	realView.y = realView.y - (float)(G::Cmd->mousedx * 0.022f);
	realView.r = 0.0f;

	realView.p = Misc::flClamp(realView.p, -89.0f, 89.0f);
	realView.y = Misc::NormalizeAngle(realView.y);

	if (G::pBunnyHop->m_bEnabled && GetAsyncKeyState(VK_SPACE))
		G::pBunnyHop->Do();

	if (G::pAutoStrafe->m_bEnabled && G::pLocalPlayer->GetMoveType() != MOVETYPE_NOCLIP && G::pLocalPlayer->GetMoveType() != MOVETYPE_LADDER)
		G::pAutoStrafe->Do();

	if (G::pFlashlightSpammer->m_bEnabled)
		G::pFlashlightSpammer->Do();

	if (G::pAimbot->m_bEnabled && GetAsyncKeyState(0x46))
		G::pAimbot->Do();

	if (!G::Cmd->command_number) {
		if (!G::pAimbot->m_bIsAimbotting)
			G::pEngineClient->SetViewAngles(realView);
		else
			realView = G::pAimbot->aimAngle;

		return false;
	}

	if (G::pAntiAim->m_bEnabled && (G::pLocalPlayer->GetMoveType() != MOVETYPE_NOCLIP &&
		G::pLocalPlayer->GetMoveType() != MOVETYPE_LADDER))
		G::pAntiAim->Do(realView);


	if (G::pLocalPlayer->GetMoveType() != MOVETYPE_NOCLIP && G::pLocalPlayer->GetMoveType() != MOVETYPE_LADDER && !G::pAimbot->m_bIsAimbotting)
		Misc::FixMovement(realView);

	return false;
}

#endif //!HKCREATEMOVE