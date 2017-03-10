#include "PlayerEsp.h"

void CPlayerEsp::Do(int iEntIndex) {
	CBaseEntity* ent = G::pClientEntityList->GetClientEntity(iEntIndex);

	if (!ent || ent->GetHealth() <= 0)
		return;

	Vector3D entPosMin = ent->GetPos();
	Vector2D screenPosMin, screenPosMax;

	Misc::WorldToScreen(entPosMin, screenPosMin);

	//entPos.z += 71; // to get the top of the player
	G::pClientLuaInterface->PushSpecial(SPECIAL_GLOB);
	Vector3D entPosMax = G::pLuaWrapper->GetBonePosition(iEntIndex, "ValveBiped.Bip01_Head1");
	G::pClientLuaInterface->Pop();

	entPosMax.z += 13;
	Misc::WorldToScreen(entPosMax, screenPosMax);

	int height = screenPosMin.y - screenPosMax.y + 10;
	int width = height / 4.8;

	G::pClientLuaInterface->PushSpecial(SPECIAL_GLOB);
	Color teamCol = G::pLuaWrapper->GetTeamColorFromEntityIndex(iEntIndex);
	G::pClientLuaInterface->Pop();

	G::pSurface->DrawSetColor(teamCol.r, teamCol.g, teamCol.b, 255);
	G::pSurface->DrawOutlinedRect(screenPosMax.x - width, screenPosMax.y, screenPosMax.x + width, screenPosMax.y + height);

	// name
	G::pClientLuaInterface->PushSpecial(SPECIAL_GLOB);
	const wchar_t* nick = G::pLuaWrapper->wGetNick(iEntIndex);
	G::pClientLuaInterface->Pop();

	G::pSurface->DrawSetTextColor(200, 200, 200, 255);
	G::pSurface->DrawSetTextPos(screenPosMax.x - 15, screenPosMax.y - 14);
	G::pSurface->DrawSetTextFont(0x7);
	G::pSurface->DrawPrintText(nick, wcslen(nick), FONT_DRAW_DEFAULT);
}