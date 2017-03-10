#pragma once

#ifndef USERCMD_H
#define USERCMD_H

#include <Windows.h>
#include "QAngle.h"
#include "Vector.h"

class CUserCmd {
public:
	char _0x0000[4];
	float command_number; //0x0004 
	float tick_count; //0x0008 
	QAngle viewangles; //0x000C 
	float forwardmove; //0x0018 
	float sidemove; //0x001C 
	float upmove; //0x0020 
	int buttons; //0x0024 
	char _0x0028[12];
	int random_seed; //0x0034 
	__int16 mousedx; //0x0038 
	__int16 mousedy; //0x003A 
	char _0x003C[288];
};

#endif // !USERCMD_H
