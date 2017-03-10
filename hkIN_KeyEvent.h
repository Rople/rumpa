#pragma once

#ifndef HKIN_KEYEVENT
#define HKIN_KEYEVENT

#include "Misc.h"
#include "Globals.h"

typedef	void(__stdcall* IN_KeyEventFn)(int, ButtonCode_t, const char*);
IN_KeyEventFn origIN_KeyEvent;

extern void RumpaExit();

void __stdcall hkIN_KeyEvent(int eventCode, ButtonCode_t keyNum, const char* pszCurrentBinding) {
	origIN_KeyEvent(eventCode, keyNum, pszCurrentBinding);

	if (keyNum == KEY_F8 && eventCode == 1)
		G::pMenu->m_bIsOpen = !G::pMenu->m_bIsOpen;
	else if (keyNum == KEY_F11 && eventCode == 1)
		RumpaExit();

	// testing shit
	if (keyNum == KEY_F10 && eventCode == 1) {

	}
}

#endif // !HKIN_KEYEVENT