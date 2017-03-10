#pragma once

#ifndef CROSSHAIR_H
#define CROSSHAIR_H

#include "Globals.h"

enum CrosshairType {
	CROSSHAIR_CROSS_COMPACT,
	CROSSHAIR_CROSS_SEPERATED,
	CROSSHAIR_DOT,
	CROSSHAIR_X
};

class CCrosshair {
public:
	void DrawCrosshair();
	bool m_bEnabled = false;
	int crosshairType = CROSSHAIR_CROSS_COMPACT;
};

#endif // !CROSSHAIR_H