#pragma once

#ifndef LUAWRAPPER_H
#define LUAWRAPPER_H

#include "Globals.h"

class CLuaWrapper {
public:
	void GetEntity(int iEntityIndex);			// leaves entity at -1 on stack
	const char* GetNick(int iEntityIndex);
	const wchar_t* wGetNick(int iEntityIndex);
	int GetPlayerTeam(int iEntityIndex);
	Color GetTeamColorFromEntityIndex(int iEntityIndex);
	Color GetTeamColorFromTeamIndex(int iTeamIndex);
	Vector3D GetBonePosition(int iEntIndex, const char* boneName);
	Vector3D GetShootPos(int iEntIndex);
	bool IsVisible(int iEntIndex, const char* bone);
};

#endif // !LUAWRAPPER_H