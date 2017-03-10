#pragma once

#ifndef MISC_H
#define MISC_H

#include <math.h>
#include <algorithm>
#include "Vector.h"
#include "CUserCmd.h"
#include "Globals.h"

class Color {
public:
	Color() {
		this->r = 0;
		this->g = 0;
		this->b = 0;
		this->a = 0;
	}
	Color(int r, int g, int b) {
		this->r = r;
		this->g = g;
		this->b = b;
	}
	Color(int r, int g, int b, int a) {
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

	int r, g, b, a = 0;
};

enum GM {
	GM_NOTSET,
	GM_COULDNOTFIND,
	GM_DARKRP,
	GM_TTT,
	GM_SANDBOX,
	GM_JAILBREAK
};

#define M_PI		3.14159265358979323846
#define M_PI_F		((float)(M_PI))	
#define DEG2RAD( x )  ( (float)(x) * (float)(M_PI_F / 180.f) )

#define IN_ATTACK		(1 << 0)
#define IN_JUMP			(1 << 1)
#define IN_DUCK			(1 << 2)
#define IN_FORWARD		(1 << 3)
#define IN_BACK			(1 << 4)
#define IN_USE			(1 << 5)
#define IN_CANCEL		(1 << 6)
#define IN_LEFT			(1 << 7)
#define IN_RIGHT		(1 << 8)
#define IN_MOVELEFT		(1 << 9)
#define IN_MOVERIGHT	(1 << 10)
#define IN_ATTACK2		(1 << 11)
#define IN_RUN			(1 << 12)
#define IN_RELOAD		(1 << 13)
#define IN_ALT1			(1 << 14)
#define IN_ALT2			(1 << 15)
#define IN_SCORE		(1 << 16)   // Used by client.dll for when scoreboard is held down
#define IN_SPEED		(1 << 17)	// Player is holding the speed key
#define IN_WALK			(1 << 18)	// Player holding walk key
#define IN_ZOOM			(1 << 19)	// Zoom key for HUD zoom
#define IN_WEAPON1		(1 << 20)	// weapon defines these bits
#define IN_WEAPON2		(1 << 21)	// weapon defines these bits
#define IN_BULLRUSH		(1 << 22)
#define IN_GRENADE1		(1 << 23)	// grenade 1
#define IN_GRENADE2		(1 << 24)	// grenade 2
#define	IN_ATTACK3		(1 << 25)

#define	FL_ONGROUND		(1<<0)

enum MoveType_t
{
	MOVETYPE_NONE = 0,	// never moves
	MOVETYPE_ISOMETRIC,			// For players -- in TF2 commander view, etc.
	MOVETYPE_WALK,				// Player only - moving on the ground
	MOVETYPE_STEP,				// gravity, special edge handling -- monsters use this
	MOVETYPE_FLY,				// No gravity, but still collides with stuff
	MOVETYPE_FLYGRAVITY,		// flies through the air + is affected by gravity
	MOVETYPE_VPHYSICS,			// uses VPHYSICS for simulation
	MOVETYPE_PUSH,				// no clip to world, push and crush
	MOVETYPE_NOCLIP,			// No gravity, no collisions, still do velocity/avelocity
	MOVETYPE_LADDER,			// Used by players only when going onto a ladder
	MOVETYPE_OBSERVER,			// Observer movement, depends on player's observer mode
	MOVETYPE_CUSTOM,			// Allows the entity to describe its own physics

								// should always be defined as the last item in the list
								MOVETYPE_LAST = MOVETYPE_CUSTOM,

								MOVETYPE_MAX_BITS = 4
};

struct ViewMatrix_t {
	float vm[4][4];

	inline float* operator[](int i) {
		return vm[i];
	}

	inline const float* operator[](int i) const {
		return vm[i];
	}
};

enum FontDrawType_t {
	// Use the "additive" value from the scheme file
	FONT_DRAW_DEFAULT = 0,

	// Overrides
	FONT_DRAW_NONADDITIVE,
	FONT_DRAW_ADDITIVE,

	FONT_DRAW_TYPE_COUNT = 2,
};

enum ButtonCode_t {
	BUTTON_CODE_INVALID = -1,
	BUTTON_CODE_NONE = 0,

	KEY_FIRST = 0,

	KEY_NONE = KEY_FIRST,
	KEY_0,
	KEY_1,
	KEY_2,
	KEY_3,
	KEY_4,
	KEY_5,
	KEY_6,
	KEY_7,
	KEY_8,
	KEY_9,
	KEY_A,
	KEY_B,
	KEY_C,
	KEY_D,
	KEY_E,
	KEY_F,
	KEY_G,
	KEY_H,
	KEY_I,
	KEY_J,
	KEY_K,
	KEY_L,
	KEY_M,
	KEY_N,
	KEY_O,
	KEY_P,
	KEY_Q,
	KEY_R,
	KEY_S,
	KEY_T,
	KEY_U,
	KEY_V,
	KEY_W,
	KEY_X,
	KEY_Y,
	KEY_Z,
	KEY_PAD_0,
	KEY_PAD_1,
	KEY_PAD_2,
	KEY_PAD_3,
	KEY_PAD_4,
	KEY_PAD_5,
	KEY_PAD_6,
	KEY_PAD_7,
	KEY_PAD_8,
	KEY_PAD_9,
	KEY_PAD_DIVIDE,
	KEY_PAD_MULTIPLY,
	KEY_PAD_MINUS,
	KEY_PAD_PLUS,
	KEY_PAD_ENTER,
	KEY_PAD_DECIMAL,
	KEY_LBRACKET,
	KEY_RBRACKET,
	KEY_SEMICOLON,
	KEY_APOSTROPHE,
	KEY_BACKQUOTE,
	KEY_COMMA,
	KEY_PERIOD,
	KEY_SLASH,
	KEY_BACKSLASH,
	KEY_MINUS,
	KEY_EQUAL,
	KEY_ENTER,
	KEY_SPACE,
	KEY_BACKSPACE,
	KEY_TAB,
	KEY_CAPSLOCK,
	KEY_NUMLOCK,
	KEY_ESCAPE,
	KEY_SCROLLLOCK,
	KEY_INSERT,
	KEY_DELETE,
	KEY_HOME,
	KEY_END,
	KEY_PAGEUP,
	KEY_PAGEDOWN,
	KEY_BREAK,
	KEY_LSHIFT,
	KEY_RSHIFT,
	KEY_LALT,
	KEY_RALT,
	KEY_LCONTROL,
	KEY_RCONTROL,
	KEY_LWIN,
	KEY_RWIN,
	KEY_APP,
	KEY_UP,
	KEY_LEFT,
	KEY_DOWN,
	KEY_RIGHT,
	KEY_F1,
	KEY_F2,
	KEY_F3,
	KEY_F4,
	KEY_F5,
	KEY_F6,
	KEY_F7,
	KEY_F8,
	KEY_F9,
	KEY_F10,
	KEY_F11,
	KEY_F12,
	KEY_CAPSLOCKTOGGLE,
	KEY_NUMLOCKTOGGLE,
	KEY_SCROLLLOCKTOGGLE,

	KEY_LAST = KEY_SCROLLLOCKTOGGLE,
	KEY_COUNT = KEY_LAST - KEY_FIRST + 1,

	// Mouse
	MOUSE_FIRST = KEY_LAST + 1,

	MOUSE_LEFT = MOUSE_FIRST,
	MOUSE_RIGHT,
	MOUSE_MIDDLE,
	MOUSE_4,
	MOUSE_5,
	MOUSE_WHEEL_UP,		// A fake button which is 'pressed' and 'released' when the wheel is moved up 
	MOUSE_WHEEL_DOWN,	// A fake button which is 'pressed' and 'released' when the wheel is moved down
};

namespace Misc {
	extern void VectorAngles(Vector3D* forward, QAngle* angles);
	extern void FixMovement(QAngle oldAng);
	extern float flClamp(float val, float min, float max);
	extern float NormalizeAngle(float ang);
	extern bool MouseClick(int x0, int y0, int x1, int y1);
	extern bool ScreenTransform(const Vector3D &point, Vector2D &screen);
	extern bool WorldToScreen(const Vector3D &origin, Vector2D& screen);
	extern wchar_t* charToWChar(const char* text); // http://stackoverflow.com/questions/3074776/how-to-convert-char-array-to-wchar-t-array
	extern void DumpStack(int stackDumpId);
	extern void GetScreenSize();
	extern void GetGamemode();

	template <typename T>
	extern T GetVFunc(void *vTable, int iIndex) {
		return (*(T**)vTable)[iIndex];
	}

	template <typename T>
	extern T* CaptureInterface(std::string strModule, std::string strInterface)
	{
		typedef T* (*CreateInterfaceFn)(const char* szName, int iReturn);
		CreateInterfaceFn CreateInterface = (CreateInterfaceFn)GetProcAddress(GetModuleHandleA(strModule.c_str()), "CreateInterface");

		return CreateInterface(strInterface.c_str(), 0);
	}
}

#endif // !MISC_H
