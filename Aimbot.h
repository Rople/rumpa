#pragma once

#ifndef AIMBOT_H
#define AIMBOT_H

#include "Globals.h"

enum TargetType {
	AIMBOT_TARGET_TYPE_CLOSEST,
	AIMBOT_TARGET_TYPE_FOV
};

class CAimbot {
public:
	void Do();
	bool m_bEnabled = false;
	int targetType = AIMBOT_TARGET_TYPE_CLOSEST;
	QAngle aimAngle;
	bool m_bIsAimbotting = false;
private:
	CBaseEntity* GetBestTarget();
};

#endif // !AIMBOT_H