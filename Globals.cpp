#include "Globals.h"

IEngineClient* G::pEngineClient;
IClientEntityList* G::pClientEntityList;
IBaseClientDll* G::pBaseClientDll;
IPanel* G::pPanel;
ISurface* G::pSurface;
ILuaShared* G::pLuaShared;
ILuaInterface* G::pClientLuaInterface;

VTHook* G::ClientModeVT;
VTHook* G::PanelVT;
VTHook* G::CHLClientVT;
VTHook* G::InputInternalVT;
VTHook* G::LuaSharedVT;

CBaseEntity* G::pLocalPlayer;
CUserCmd* G::Cmd;
CLuaWrapper* G::pLuaWrapper;
int G::scrW, G::scrH;
bool G::IsInGame = false;
GM G::Gamemode = GM_NOTSET;
bool G::bBeingScreengrabbed = false;

CRumpaMenu* G::pMenu;
CBunnyHop* G::pBunnyHop;
CAutoStrafe* G::pAutoStrafe;
CAntiAim* G::pAntiAim;
CFlashlightSpammer* G::pFlashlightSpammer;
CPlayerEsp* G::pPlayerEsp;
CNameChanger* G::pNameChanger;
CAimbot* G::pAimbot;
CCrosshair* G::pCrosshair;
CAntiScreengrab* G::pAntiScreengrab;