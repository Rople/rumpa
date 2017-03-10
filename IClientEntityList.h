#pragma once

#ifndef CLIENTENTITYLIST_H
#define CLIENTENTITYLIST_H

#include "CBaseEntity.h"

class IClientEntityList {
public:
	virtual void pad0() = 0;
	virtual void pad1() = 0;
	virtual CBaseEntity* GetClientNetworkable(int) = 0;
	virtual CBaseEntity* GetClientEntity(int) = 0;
};  

#endif // !CLIENTENTITYLIST_H
