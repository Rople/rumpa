#pragma once

#ifndef HKINTERNALMOUSE
#define HKINTERNALMOUSE

#include "Misc.h"

typedef	bool(__fastcall* InternalMousePressedFn)(void*, void*, ButtonCode_t);
InternalMousePressedFn origInternalMousePressed;

bool __fastcall hkInternalMousePressed(void* pThis, void* edx, ButtonCode_t keyNum) {
	if (G::pMenu->m_bIsOpen && G::pMenu->m_bIsReady && keyNum == MOUSE_LEFT) {
		int mouseX, mouseY;
		G::pSurface->SurfaceGetCursorPos(mouseX, mouseY);

		if ((G::pMenu->m_bIsOpen && G::pMenu->m_bIsReady) && (mouseX > G::pMenu->x0 && mouseX < G::pMenu->x1 && mouseY > G::pMenu->y0 && mouseY < G::pMenu->y1))
			G::pMenu->OnClick(mouseX, mouseY);
	}

	return origInternalMousePressed(pThis, edx, keyNum);
}

#endif // !HKINTERNALMOUSE