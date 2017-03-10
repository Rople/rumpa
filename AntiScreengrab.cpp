#include "AntiScreengrab.h"

CAntiScreengrab::CAntiScreengrab() {
	G::pClientLuaInterface->PushSpecial(SPECIAL_GLOB);
	G::pClientLuaInterface->GetField(-1, "render");
	G::pClientLuaInterface->GetField(-1, "Capture");
	G::pClientLuaInterface->SetField(-2, oldCaptureName);
	G::pClientLuaInterface->Pop();

	G::pClientLuaInterface->GetField(-1, "render");
	G::pClientLuaInterface->PushCFunction(DetouredCapture);
	G::pClientLuaInterface->SetField(-2, "Capture");
	G::pClientLuaInterface->Pop(2);

	std::cout << "AntiScreengrab Initialized" << std::endl;
}

CAntiScreengrab::~CAntiScreengrab() {
	std::cout << "AntiScreengrab De-initialized" << std::endl;
}

int DetouredCapture(lua_State* lua) {
	G::bBeingScreengrabbed = true;
	std::cout << "Something or someone just attempted to screengrab us!" << std::endl;

	G::pClientLuaInterface->PushSpecial(SPECIAL_GLOB);

	G::pClientLuaInterface->CreateTable();
	G::pClientLuaInterface->PushBool(true);
	G::pClientLuaInterface->SetField(-2, "drawhud");
	G::pClientLuaInterface->PushBool(true);
	G::pClientLuaInterface->SetField(-2, "drawmonitors");
	int viewData = G::pClientLuaInterface->ReferenceCreate();

	Misc::DumpStack(0);

	G::pClientLuaInterface->GetField(-1, "render");
	G::pClientLuaInterface->GetField(-1, "RenderView");

	Misc::DumpStack(1);

	G::pClientLuaInterface->ReferencePush(viewData);
	G::pClientLuaInterface->SetTable(-2);

	Misc::DumpStack(2);

	G::pClientLuaInterface->Call(1, 0);
	G::pClientLuaInterface->Pop();

	Misc::DumpStack(3);

	G::pClientLuaInterface->GetField(-1, "render");
	G::pClientLuaInterface->GetField(-1, G::pAntiScreengrab->oldCaptureName);
	G::pClientLuaInterface->Push(-4);
	G::pClientLuaInterface->Call(1, 1);

	G::pClientLuaInterface->ReferenceFree(viewData);
	G::bBeingScreengrabbed = false;

	return 1;
}