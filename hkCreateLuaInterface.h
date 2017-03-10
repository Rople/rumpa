#pragma once

#ifndef CREATELUAINTERFACE_H
#define CREATELUAINTERFACE_H

#include "ILuaInterface.h"
#include <iostream>

typedef ILuaInterface*(__fastcall* CreateLuaInterfaceFn)(void* pThis, void* edx, unsigned char, bool);
CreateLuaInterfaceFn origCreateLuaInterface;

ILuaInterface* __fastcall hkCreateLuaInterface(void* pThis, void* edx, unsigned char interfaceType, bool bUnkwn) {
	G::pClientLuaInterface = origCreateLuaInterface(pThis, edx, interfaceType, bUnkwn);
	std::cout << "Grabbed client lua interface at " << G::pClientLuaInterface << " interfaceType = " << interfaceType << " bUnkwn = " << bUnkwn << std::endl;
	G::pEngineClient->ClientCmd("clear");

	return G::pClientLuaInterface;
}

#endif // !CREATELUAINTERFACE_H