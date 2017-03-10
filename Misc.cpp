#include "Misc.h"

void Misc::VectorAngles(Vector3D* forward, QAngle* angles) {
	if (forward->y == 0 && forward->x == 0) {
		angles->y = 0;
		if (forward->z > 0)
			angles->p = 270;
		else
			angles->p = 90;
	}
	else {
		angles->y = (atan2(forward->y, forward->x) * 180 / M_PI_F);
		if (angles->y < 0)
			angles->y += 360;

		float tmp = sqrt(forward->x * forward->x + forward->y * forward->y);
		angles->p = (atan2(-forward->z, tmp) * 180 / M_PI_F);

		if (angles->p < 0)
			angles->p += 360;
	}

	angles->r = 0;
}

void Misc::GetScreenSize() {
	int w, h = 0;
	G::pEngineClient->GetScreenSize(w, h);

	if (!w || !h)
		return;

	G::scrW = w;
	G::scrH = h;
}

void Misc::GetGamemode() {
	std::cout << "Getting gamemode..." << std::endl;

	G::pClientLuaInterface->PushSpecial(SPECIAL_GLOB);
	G::pClientLuaInterface->GetField(-1, "gmod");
	G::pClientLuaInterface->GetField(-1, "GetGamemode");
	G::pClientLuaInterface->Call(0, 1);

	G::pClientLuaInterface->GetField(-1, "Name");
	std::string gmName = G::pClientLuaInterface->GetString(-1);
	std::transform(gmName.begin(), gmName.end(), gmName.begin(), tolower);

	G::pClientLuaInterface->Pop(4);

	std::cout << "Gamemode = " << gmName << std::endl;

	if (gmName == "darkrp")
		G::Gamemode = GM_DARKRP;
	else if (gmName == "jail break")
		G::Gamemode = GM_JAILBREAK;
	else
		G::Gamemode = GM_COULDNOTFIND;
}

void Misc::DumpStack(int stackDumpId) {
	std::cout << "---------- Stack dump id " << stackDumpId << " ----------" << std::endl;

	for (int i = -5; i < 0; i++) {
		int t = G::pClientLuaInterface->GetType(i);

		switch (t) {
		case Type::NIL:
			std::cout << i << " nil" << std::endl;
			break;
		case Type::STRING:
			std::cout << i << " string " << G::pClientLuaInterface->GetString(i) << std::endl;
			break;
		case Type::NUMBER:
			std::cout << i << " number " << G::pClientLuaInterface->GetNumber(i) << std::endl;
			break;
		case Type::TABLE:
			std::cout << i << " table" << std::endl;
			break;
		case Type::USERDATA:
			std::cout << i << " userdata" << std::endl;
			break;
		case Type::ENTITY:
			std::cout << i << " entity" << std::endl;
			break;
		default:
			std::cout << i << " unknown" << std::endl;
		}
	}

	std::cout << "---------- End of stack dump id " << stackDumpId << " ----------" << std::endl << std::endl;
}

bool Misc::ScreenTransform(const Vector3D& point, Vector2D& screen) { // tots not pasted #2
	float w;
	const ViewMatrix_t& worldToScreen = G::pEngineClient->WorldToScreenMatrix();

	screen.x = worldToScreen[0][0] * point.x + worldToScreen[0][1] * point.y + worldToScreen[0][2] * point.z + worldToScreen[0][3];
	screen.y = worldToScreen[1][0] * point.x + worldToScreen[1][1] * point.y + worldToScreen[1][2] * point.z + worldToScreen[1][3];
	w = worldToScreen[3][0] * point.x + worldToScreen[3][1] * point.y + worldToScreen[3][2] * point.z + worldToScreen[3][3];

	bool behind = false;

	if (w < 0.001f) {
		behind = true;
		screen.x *= 100000;
		screen.y *= 100000;
	}
	else {
		behind = false;
		float invw = 1.0f / w;
		screen.x *= invw;
		screen.y *= invw;
	}

	return behind;
}

bool Misc::WorldToScreen(const Vector3D& origin, Vector2D& screen) {
	if (!ScreenTransform(origin, screen)) {
		float x = G::scrW / 2;
		float y = G::scrH / 2;
		x += 0.5 * screen.x * G::scrW + 0.5;
		y -= 0.5 * screen.y * G::scrH + 0.5;
		screen.x = x;
		screen.y = y;

		return true;
	}

	return false;
}

wchar_t* Misc::charToWChar(const char* text) {
	const size_t size = strlen(text) + 1;
	wchar_t* wText = new wchar_t[size];
	mbstowcs(wText, text, size);
	return wText;
}

void Misc::FixMovement(QAngle viewAnglesOld) {
	Vector3D move;
	move.x = G::Cmd->forwardmove;
	move.y = G::Cmd->sidemove;
	move.z = 0.0f;

	float speed = sqrt(move.x * move.x + move.y * move.y);

	QAngle ang;
	Misc::VectorAngles(&move, &ang);

	float yaw = DEG2RAD(G::Cmd->viewangles.y - viewAnglesOld.y + ang.y);

	G::Cmd->forwardmove = (cos(yaw) * speed);
	G::Cmd->sidemove = (sin(yaw) * speed);
}

float Misc::flClamp(float val, float min, float max) {
	if (val > max)
		return max;

	if (val < min)
		return min;

	return val;
}

float Misc::NormalizeAngle(float ang) {
	ang = fmodf(ang, 360.0f);

	if (ang > 180.0f)
		ang -= 360.0f;

	if (ang < -180.0f)
		ang += 360.0f;

	return ang;
}

bool Misc::MouseClick(int x0, int y0, int x1, int y1) {
	int mouseX, mouseY;
	G::pSurface->SurfaceGetCursorPos(mouseX, mouseY);

	return ((GetAsyncKeyState(1) & 1) && ((mouseX > x0 && mouseX < x1) && (mouseY > y0 && mouseY < y1)));
}