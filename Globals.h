#pragma once

#ifndef GLOBALS_H
#define GLOBALS_H

#include "IEngineClient.h"
#include "IClientEntityList.h"
#include "IBaseClientDll.h"
#include "IPanel.h"
#include "ISurface.h"
#include "ILuaInterface.h"
#include "RumpaMenu.h"
#include "CUserCmd.h"
#include "BunnyHop.h"
#include "AutoStrafe.h"
#include "AntiAim.h"
#include "FlashlightSpammer.h"
#include "PlayerEsp.h"
#include "NameChanger.h"
#include "Aimbot.h"
#include "Crosshair.h"
#include "AntiScreengrab.h"
#include "VTHook.h"
#include "Misc.h"
#include "LuaWrapper.h"

enum GM;

class CRumpaMenu;
class CLuaWrapper;
class CBunnyHop;
class CAutoStrafe;
class CAntiAim;
class CFlashlightSpammer;
class CPlayerEsp;
class CNameChanger;
class CAimbot;
class CCrosshair;
class CAntiScreengrab;
class IPanel;
class ISurface;
class IEngineClient;
class ILuaShared;
class ILuaInterface;

namespace G {
	extern IEngineClient* pEngineClient;
	extern IClientEntityList* pClientEntityList;
	extern IBaseClientDll* pBaseClientDll;
	extern IPanel* pPanel;
	extern ISurface* pSurface;
	extern ILuaShared* pLuaShared;
	extern ILuaInterface* pClientLuaInterface;

	extern VTHook* ClientModeVT;
	extern VTHook* PanelVT;
	extern VTHook* CHLClientVT;
	extern VTHook* InputInternalVT;
	extern VTHook* LuaSharedVT;

	extern CBaseEntity* pLocalPlayer;
	extern CUserCmd* Cmd;
	extern CLuaWrapper* pLuaWrapper;
	extern int scrW, scrH;
	extern bool IsInGame;
	extern GM Gamemode;
	extern bool bBeingScreengrabbed;

	extern CRumpaMenu* pMenu;
	extern CBunnyHop* pBunnyHop;
	extern CAutoStrafe* pAutoStrafe;
	extern CAntiAim* pAntiAim;
	extern CFlashlightSpammer* pFlashlightSpammer;
	extern CPlayerEsp* pPlayerEsp;
	extern CNameChanger* pNameChanger;
	extern CAimbot* pAimbot;
	extern CCrosshair* pCrosshair;
	extern CAntiScreengrab* pAntiScreengrab;
}

#endif // !GLOBALS_H