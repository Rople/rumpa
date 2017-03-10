#include <Windows.h>
#include <iostream>
#include <vector>
#include <ctime>

#include "IEngineClient.h"
#include "IClientEntityList.h"
#include "IBaseClientDll.h"
#include "IPanel.h"

#include "Globals.h"
#include "VTHook.h"

#include "hkIN_KeyEvent.h"
#include "hkCreateMove.h"
#include "hkPaintTraverse.h"
#include "hkInternalMouse.h"
#include "hkCreateLuaInterface.h"
#include "hkOverrideView.h"
#include "hkShouldDrawLocalPlayer.h"

BOOL APIENTRY DllMain(HMODULE hDll, DWORD dwReason, LPVOID lpReserved);
void RumpaInit();
bool RumpaAuth();
void Loop();

void RumpaInit() {
	G::pEngineClient = Misc::CaptureInterface<IEngineClient>("engine.dll", "VEngineClient013");
	G::pClientEntityList = Misc::CaptureInterface<IClientEntityList>("client.dll", "VClientEntityList003");
	G::pBaseClientDll = Misc::CaptureInterface<IBaseClientDll>("client.dll", "VClient017");
	G::pPanel = Misc::CaptureInterface<IPanel>("vgui2.dll", "VGUI_Panel009");
	G::pSurface = Misc::CaptureInterface<ISurface>("vguimatsurface.dll", "VGUI_Surface030");
	DWORD* pInputInternal = Misc::CaptureInterface<DWORD>("vgui2.dll", "VGUI_InputInternal001");
	G::pLuaShared = Misc::CaptureInterface<ILuaShared>("lua_shared.dll", "LUASHARED003");

	Misc::GetScreenSize();

	G::pMenu = new CRumpaMenu;
	G::pLuaWrapper = new CLuaWrapper;

	G::pBunnyHop = new CBunnyHop;
	G::pAutoStrafe = new CAutoStrafe;
	G::pAntiAim = new CAntiAim;
	G::pFlashlightSpammer = new CFlashlightSpammer;
	G::pPlayerEsp = new CPlayerEsp;
	G::pNameChanger = new CNameChanger;
	G::pAimbot = new CAimbot;
	G::pCrosshair = new CCrosshair;

	G::ClientModeVT = new VTHook(**(DWORD****)((*(DWORD**)G::pBaseClientDll)[10] + 0x5));
	origCreateMove = (CreateMoveFn)G::ClientModeVT->HookFunction((DWORD)hkCreateMove, 21);
	origOverrideView = (OverrideViewFn)G::ClientModeVT->HookFunction((DWORD)hkOverrideView, 16);
	origShouldDrawLocalPlayer = (ShouldDrawLocalPlayerFn)G::ClientModeVT->HookFunction((DWORD)hkShouldDrawLocalPlayer, 13);

	G::PanelVT = new VTHook((DWORD**)G::pPanel);
	origPaintTraverse = (PaintTraverseFn)G::PanelVT->HookFunction((DWORD)hkPaintTraverse, 41);

	G::CHLClientVT = new VTHook((DWORD**)G::pBaseClientDll);
	origIN_KeyEvent = (IN_KeyEventFn)G::CHLClientVT->HookFunction((DWORD)hkIN_KeyEvent, 20);

	G::InputInternalVT = new VTHook((DWORD**)pInputInternal);
	origInternalMousePressed = (InternalMousePressedFn)G::InputInternalVT->HookFunction((DWORD)hkInternalMousePressed, 68);

	G::LuaSharedVT = new VTHook((DWORD**)G::pLuaShared);
	origCreateLuaInterface = (CreateLuaInterfaceFn)G::LuaSharedVT->HookFunction((DWORD)hkCreateLuaInterface, 4);

	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Loop, NULL, NULL, NULL);

	/* Debug stuff */

	std::cout << "Found VEngineClient013 at " << G::pEngineClient << std::endl;
	std::cout << "Found VClientEntityList003 at " << G::pClientEntityList << std::endl;
	std::cout << "Found VClient017 at " << G::pBaseClientDll << std::endl;
	std::cout << "Found VGUI_Panel009 at " << G::pPanel << std::endl;
	std::cout << "Found VGUI_Surface030 at " << G::pSurface << std::endl;
	std::cout << "Found VGUI_InputInternal001 at " << pInputInternal << std::endl;
	std::cout << "Found LUASHARED003 at " << G::pLuaShared << std::endl << std::endl;

	std::cout << "Hooked ClientModeShared VTable at " << G::ClientModeVT << std::endl;
	std::cout << "Hooked Panel VTable at " << G::PanelVT << std::endl;
	std::cout << "Hooked CHLClient VTable at " << G::CHLClientVT << std::endl;
	std::cout << "Hooked InputInteral VTable at " << G::InputInternalVT << std::endl;
	std::cout << "Hooked LuaShared VTable at " << G::LuaSharedVT << std::endl << std::endl;

	std::cout << "Hooked CreateMove fn at " << origCreateMove << std::endl;
	std::cout << "Hooked OverrideView fn at " << origOverrideView << std::endl;
	std::cout << "Hooked PaintTraverse fn at " << origPaintTraverse << std::endl;
	std::cout << "Hooked IN_KeyEvent fn at " << origIN_KeyEvent << std::endl;
	std::cout << "Hooked InternalMousePressed fn at " << origInternalMousePressed << std::endl;
	std::cout << "Hooked CreateLuaInterface fn at " << origCreateLuaInterface << std::endl << std::endl;
	
	std::cout << "Rumpa++ Loaded. F8 to open/close menu." << std::endl;

	if (G::pEngineClient->IsInGame()) {
		std::cout << "You're supposed to inject at the main menu, you pleb." << std::endl;
		G::pEngineClient->ClientCmd("retry");
	}
}

void Loop() {
	while (true) {
		if (G::pEngineClient->IsInGame() && G::Gamemode == GM_NOTSET) {
			std::cout << "We joined the server" << std::endl;
			Misc::GetGamemode();
			G::pAntiScreengrab = new CAntiScreengrab;
		}

		if (!G::pEngineClient->IsInGame() && G::Gamemode != GM_NOTSET) {
			std::cout << "We left the server" << std::endl;
			G::Gamemode = GM_NOTSET;
			G::pAntiAim->m_bEnabled = false;
			delete G::pAntiScreengrab;
		}

		Sleep(100);
	}

	/*
	time_t t = time(0);
	time_t nextNameChange = t;

	while (true) {
		t = time(0);

		if (G::pEngineClient->IsConnected() && G::pEngineClient->IsInGame() && t > nextNameChange) {
			G::pNameChanger->Do();

			nextNameChange = t + 5;
		}

		Sleep(100);
	}*/
}

void RumpaExit() {
	std::cout << "Exiting..." << std::endl;

	DllMain(NULL, DLL_PROCESS_DETACH, NULL);
}

HANDLE hnd;

BOOL APIENTRY DllMain(HMODULE hDll, DWORD dwReason, LPVOID lpReserved) {
	switch (dwReason) {
	case DLL_PROCESS_ATTACH:
		// console prep and opening
		FILE* conout;
		AllocConsole();
		SetConsoleTitle("Rumpa++ Debug Console");
		freopen_s(&conout, "conout$", "w", stdout);

		if (!RumpaAuth()) {
			std::cout << "err" << std::endl;
			return true;
		}

		hnd = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)RumpaInit, NULL, NULL, NULL);
		break;
	case DLL_PROCESS_DETACH:
		G::ClientModeVT->UnHook();
		G::PanelVT->UnHook();
		G::CHLClientVT->UnHook();
		G::InputInternalVT->UnHook();
		G::LuaSharedVT->UnHook();

		delete G::pMenu;
		delete G::pBunnyHop;
		delete G::pAutoStrafe;
		delete G::pAntiAim;
		delete G::pFlashlightSpammer;
		delete G::pPlayerEsp;
		delete G::pNameChanger;
		delete G::pAimbot;
		delete G::pCrosshair;

		FreeConsole();
		TerminateThread(hnd, NULL);

		break;
	}

	return true;
}

bool RumpaAuth() {
	HW_PROFILE_INFO hwProfileInfo;
	std::vector<const char*> fams;

	fams.push_back("{fuk u}"); // me

	if (GetCurrentHwProfile(&hwProfileInfo) != NULL) {
		const char* guid = hwProfileInfo.szHwProfileGuid;

		for (const char* fam : fams) {
			if (!strcmp(guid, fam))
				return true;
		}
	}

	return false;
}