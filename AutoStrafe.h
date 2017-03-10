#pragma once

#ifndef AUTOSTRAFE_H
#define AUTOSTRAFE_H

#include "Globals.h"

class CAutoStrafe {
public:
	void Do();
	bool m_bEnabled = false;
};

#endif // !AUTOSTRAFE_H