#include "Aimbot.h"

void CAimbot::Do() {
	CBaseEntity* bestTarget = GetBestTarget();

	if (!bestTarget)
		return;

	m_bIsAimbotting = true;
	
	G::pClientLuaInterface->PushSpecial(SPECIAL_GLOB);
	Vector3D headPos = G::pLuaWrapper->GetBonePosition(bestTarget->GetIndex(), "ValveBiped.Bip01_Head1");
	Vector3D ourEyePos = G::pLuaWrapper->GetShootPos(G::pEngineClient->GetLocalPlayer());
	G::pClientLuaInterface->Pop();

	Vector3D pos = headPos - ourEyePos;

	Misc::VectorAngles(&pos, &aimAngle);

	G::Cmd->viewangles = aimAngle;
	G::pEngineClient->SetViewAngles(aimAngle);
	G::Cmd->buttons |= IN_ATTACK;
}

CBaseEntity* CAimbot::GetBestTarget() {
	CBaseEntity* bestTarget = nullptr;

	for (int i = 1; i < G::pEngineClient->GetMaxClients(); i++) {
		if (i == G::pEngineClient->GetLocalPlayer())
			continue;

		CBaseEntity* ent = G::pClientEntityList->GetClientEntity(i);

		if (!ent)
			break;

		if (ent->GetHealth() > 0) {
			if (targetType == AIMBOT_TARGET_TYPE_CLOSEST) {
				if (!bestTarget)
					bestTarget = ent;

				float distEntToLocal = ent->GetPos().GetDistance(G::pLocalPlayer->GetPos());
				float distBestToLocal = bestTarget->GetPos().GetDistance(G::pLocalPlayer->GetPos());

				if (distEntToLocal < distBestToLocal)
					bestTarget = ent;
			}
			else if (targetType == AIMBOT_TARGET_TYPE_FOV) {

			}
		}
	}

	return bestTarget;
}