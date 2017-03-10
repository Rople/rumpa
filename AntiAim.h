#pragma once

#ifndef	ANTIAIM_H
#define ANTIAIM_H

#include "QAngle.h"
#include "Globals.h"
#include "Misc.h"
#include <iostream> // remove

enum YawAntiAim {
	YAW_NONE,
	YAW_SLOWSPIN,
	YAW_FASTSPIN,
	YAW_JITTER,
	YAW_RANDOM,
	YAW_BACKWARDS,
	YAW_SIDEWAYS
};

enum PitchAntiAim {
	PITCH_NONE,
	PITCH_UP,
	PITCH_DOWN,
	PITCH_JITTER
};

class CAntiAim {
public:
	void Do(QAngle realView);
	int yawAntiAim = YAW_NONE;
	int pitchAntiAim = PITCH_NONE;
	bool m_bEnabled = false;
private:
	QAngle fakeView;
	bool flip = false;
};

#endif // !ANTIAIM_H

