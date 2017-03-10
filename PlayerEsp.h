#pragma once

#ifndef PLAYERESP_H
#define PLAYERESP_H

#include "Globals.h"
#include "Misc.h"
#include <iostream>

class Color;

class CPlayerEsp {
public:
	void Do(int iEntIndex);
	bool m_bEnabled = true;
};

#endif // !PLAYERESP_H