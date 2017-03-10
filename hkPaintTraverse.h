#pragma once

#ifndef HKPAINTTRAVERSE
#define HKPAINTTRAVERSE

#include "Globals.h"

typedef void(__fastcall* PaintTraverseFn)(void*, void*, unsigned int, bool, bool);
PaintTraverseFn origPaintTraverse;


void __fastcall hkPaintTraverse(void* pThis, void* edx, unsigned int iPanel, bool forceRepaint, bool allowForce) {
	origPaintTraverse(pThis, edx, iPanel, forceRepaint, allowForce);

	const char* panelName = G::pPanel->GetName(iPanel);

	if (strcmp(panelName, "FocusOverlayPanel"))
		return;

	Misc::GetScreenSize();

	if (G::bBeingScreengrabbed)
		return;

	int maxClients = G::pEngineClient->GetMaxClients();
	int localPlayerIndex = G::pEngineClient->GetLocalPlayer();

	for (int i = 1; i < maxClients; i++) {
		if (i != localPlayerIndex) {
			if (G::pPlayerEsp->m_bEnabled)
				G::pPlayerEsp->Do(i);
		}
	}

	if (G::pCrosshair->m_bEnabled && G::pEngineClient->IsInGame())
		G::pCrosshair->DrawCrosshair();

	if (G::pMenu->m_bIsOpen)
		G::pMenu->Draw();
}

#endif // !HKPAINTTRAVERSE