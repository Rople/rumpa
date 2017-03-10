#pragma once

#ifndef NAMECHANGER_H
#define NAMECHANGER_H

#include "ILuaInterface.h"
#include "Globals.h"
#include <random>
#include <ctime>

class CNameChanger {
public:
	void Do();
private:
	int GetValidEnt();
	const char* GetNick(int entIndex);
	int lastIndex = 0;
	bool LuaIsValid();
};

#endif // !NAMECHANGER_H