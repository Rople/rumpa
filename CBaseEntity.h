#pragma once

#ifndef CBASEENTITY_H
#define CBASEENTITY_H

#include "Vector.h"
#include "QAngle.h"

struct player_info_t;

class CBaseEntity {
public:
	int GetHealth();
	int GetTeam();
	int GetFlags();
	int GetMoveType();
	Vector3D GetPos();
	QAngle GetAngles();
	int GetIndex();
};

struct player_info_t {
	char name[32]; //0x0000 
	char _0x0020[4];
	char steamid[32]; //0x0024 
	char _0x0044[1020];
};//Size=0x0440

#endif