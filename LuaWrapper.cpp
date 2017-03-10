#include "LuaWrapper.h"

void CLuaWrapper::GetEntity(int iEntityIndex) {
	G::pClientLuaInterface->GetField(-1, "Entity");
	G::pClientLuaInterface->PushNumber(iEntityIndex);
	G::pClientLuaInterface->Call(1, 1);
}

const char* CLuaWrapper::GetNick(int iEntityIndex) {
	GetEntity(iEntityIndex);

	G::pClientLuaInterface->GetField(-1, "Nick");
	G::pClientLuaInterface->Push(-2);
	G::pClientLuaInterface->Call(1, 1);

	const char* nick = G::pClientLuaInterface->GetString(-1);
	G::pClientLuaInterface->Pop(2);

	return nick;
}

const wchar_t* CLuaWrapper::wGetNick(int iEntityIndex) {
	GetEntity(iEntityIndex);

	G::pClientLuaInterface->GetField(-1, "Nick");
	G::pClientLuaInterface->Push(-2);
	G::pClientLuaInterface->Call(1, 1);

	const char* nick = G::pClientLuaInterface->GetString(-1);
	G::pClientLuaInterface->Pop(2);

	return Misc::charToWChar(nick);
}

int CLuaWrapper::GetPlayerTeam(int iEntityIndex) {
	GetEntity(iEntityIndex);

	G::pClientLuaInterface->GetField(-1, "Team");
	G::pClientLuaInterface->Push(-2);
	G::pClientLuaInterface->Call(1, 1);
	int iTeamNum = (int)G::pClientLuaInterface->GetNumber(-1);

	G::pClientLuaInterface->Pop(2);

	return iTeamNum;
}

Color CLuaWrapper::GetTeamColorFromEntityIndex(int iEntityIndex) {
	Color teamCol;

	int iTeamIndex = GetPlayerTeam(iEntityIndex);

	G::pClientLuaInterface->GetField(-1, "team");
	G::pClientLuaInterface->GetField(-1, "GetColor");
	G::pClientLuaInterface->PushNumber(iTeamIndex);
	G::pClientLuaInterface->Call(1, 1);

	G::pClientLuaInterface->GetField(-1, "r");
	teamCol.r = G::pClientLuaInterface->GetNumber(-1);
	G::pClientLuaInterface->Pop();

	G::pClientLuaInterface->GetField(-1, "g");
	teamCol.g = G::pClientLuaInterface->GetNumber(-1);
	G::pClientLuaInterface->Pop();

	G::pClientLuaInterface->GetField(-1, "b");
	teamCol.b = G::pClientLuaInterface->GetNumber(-1);
	G::pClientLuaInterface->Pop();

	G::pClientLuaInterface->GetField(-1, "a");
	teamCol.a = G::pClientLuaInterface->GetNumber(-1);

	G::pClientLuaInterface->Pop(3);

	return teamCol;
}

Color CLuaWrapper::GetTeamColorFromTeamIndex(int iTeamIndex) {
	Color teamCol;

	G::pClientLuaInterface->GetField(-1, "team");
	G::pClientLuaInterface->GetField(-1, "GetColor");
	G::pClientLuaInterface->PushNumber(iTeamIndex);
	G::pClientLuaInterface->Call(1, 1);

	G::pClientLuaInterface->GetField(-1, "r");
	teamCol.r = G::pClientLuaInterface->GetNumber(-1);
	G::pClientLuaInterface->Pop();

	G::pClientLuaInterface->GetField(-1, "g");
	teamCol.g = G::pClientLuaInterface->GetNumber(-1);
	G::pClientLuaInterface->Pop();

	G::pClientLuaInterface->GetField(-1, "b");
	teamCol.b = G::pClientLuaInterface->GetNumber(-1);
	G::pClientLuaInterface->Pop();

	G::pClientLuaInterface->GetField(-1, "a");
	teamCol.a = G::pClientLuaInterface->GetNumber(-1);

	G::pClientLuaInterface->Pop(3);

	return teamCol;
}

Vector3D CLuaWrapper::GetBonePosition(int iEntIndex, const char* boneName) {
	int iBoneIndex = 0;
	Vector3D bonePos;

	GetEntity(iEntIndex);

	G::pClientLuaInterface->GetField(-1, "LookupBone");
	G::pClientLuaInterface->Push(-2);
	G::pClientLuaInterface->PushString(boneName);
	G::pClientLuaInterface->Call(2, 1);

	iBoneIndex = G::pClientLuaInterface->GetNumber(-1);

	G::pClientLuaInterface->Pop();

	G::pClientLuaInterface->GetField(-1, "GetBonePosition");
	G::pClientLuaInterface->Push(-2);
	G::pClientLuaInterface->PushNumber(iBoneIndex);
	G::pClientLuaInterface->Call(2, 1);

	G::pClientLuaInterface->GetField(-1, "x");
	bonePos.x = G::pClientLuaInterface->GetNumber(-1);
	G::pClientLuaInterface->Pop();

	G::pClientLuaInterface->GetField(-1, "y");
	bonePos.y = G::pClientLuaInterface->GetNumber(-1);
	G::pClientLuaInterface->Pop();

	G::pClientLuaInterface->GetField(-1, "z");
	bonePos.z = G::pClientLuaInterface->GetNumber(-1);

	G::pClientLuaInterface->Pop(3);

	return bonePos;
}

Vector3D CLuaWrapper::GetShootPos(int iEntIndex) {
	Vector3D shootPos;

	GetEntity(iEntIndex);

	G::pClientLuaInterface->GetField(-1, "GetShootPos");
	G::pClientLuaInterface->Push(-2);
	G::pClientLuaInterface->Call(1, 1);

	G::pClientLuaInterface->GetField(-1, "x");
	shootPos.x = G::pClientLuaInterface->GetNumber(-1);
	G::pClientLuaInterface->Pop();

	G::pClientLuaInterface->GetField(-1, "y");
	shootPos.y = G::pClientLuaInterface->GetNumber(-1);
	G::pClientLuaInterface->Pop();

	G::pClientLuaInterface->GetField(-1, "z");
	shootPos.z = G::pClientLuaInterface->GetNumber(-1);

	G::pClientLuaInterface->Pop(3);

	return shootPos;
}

int isVisibleFilter(lua_State* lua) {
	G::pClientLuaInterface->GetField(-1, "IsPlayer");
	G::pClientLuaInterface->Push(-2);
	G::pClientLuaInterface->Call(1, 1);

	std::cout << "IsPlayer = " << G::pClientLuaInterface->GetBool(-1) << std::endl;

	return 1;
}

bool CLuaWrapper::IsVisible(int iEntIndex, const char* bone) {
	Vector3D startPos, endPos;
	startPos = GetShootPos(G::pEngineClient->GetLocalPlayer());
	endPos = GetBonePosition(iEntIndex, "ValveBiped.Bip01_Head1");

	G::pClientLuaInterface->GetField(-1, "util");
	G::pClientLuaInterface->GetField(-1, "TraceLine");
}