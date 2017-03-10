#include "CBaseEntity.h"

int CBaseEntity::GetHealth() {
	return *(int*)(this + 0x90);
}

int CBaseEntity::GetTeam() {
	return *(int*)(this + 0x9C);
}

int CBaseEntity::GetFlags() {
	return *(int*)(this + 0x350);
}

int CBaseEntity::GetMoveType() {
	return *(int*)(this + 0x178);
}

Vector3D CBaseEntity::GetPos() {
	return *(Vector3D*)(this + 0x260);
}

QAngle CBaseEntity::GetAngles() {
	return *(QAngle*)(this + 0x26C);
}

int CBaseEntity::GetIndex() {
	return *(int*)(this + 0x50);
}