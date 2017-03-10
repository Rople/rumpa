#include "ISurface.h"

void ISurface::DrawSetColor(int r, int g, int b, int a) {
	typedef void(__thiscall* OriginalFn)(void*, int, int, int, int);
	return Misc::GetVFunc<OriginalFn>(this, 11)(this, r, g, b, a);
}

void ISurface::DrawFilledRect(int x0, int y0, int x1, int y1) {
	typedef void(__thiscall* OriginalFn)(void*, int, int, int, int);
	return Misc::GetVFunc<OriginalFn>(this, 12)(this, x0, y0, x1, y1);
}

void ISurface::DrawOutlinedRect(int x0, int y0, int x1, int y1) {
	typedef void(__thiscall* OriginalFn)(void*, int, int, int, int);
	return Misc::GetVFunc<OriginalFn>(this, 14)(this, x0, y0, x1, y1);
}

void ISurface::DrawLine(int x0, int y0, int x1, int y1) {
	typedef void(__thiscall* OriginalFn)(void*, int, int, int, int);
	return Misc::GetVFunc<OriginalFn>(this, 15)(this, x0, y0, x1, y1);
}

void ISurface::DrawSetTextFont(unsigned int hFont) {
	typedef void(__thiscall* OriginalFn)(void*, unsigned int);
	return Misc::GetVFunc<OriginalFn>(this, 17)(this, hFont);
}

void ISurface::DrawSetTextColor(int r, int g, int b, int a) {
	typedef void(__thiscall* OriginalFn)(void*, int, int, int, int);
	return Misc::GetVFunc<OriginalFn>(this, 19)(this, r, g, b, a);
}

void ISurface::DrawSetTextPos(int x, int y) {
	typedef void(__thiscall* OriginalFn)(void*, int, int);
	return Misc::GetVFunc<OriginalFn>(this, 20)(this, x, y);
}

void ISurface::DrawPrintText(const wchar_t* text, int textLen, FontDrawType_t drawType) {
	typedef void(__thiscall* OriginalFn)(void*, const wchar_t*, int, FontDrawType_t);
	return Misc::GetVFunc<OriginalFn>(this, 22)(this, text, textLen, drawType);
}

HFont ISurface::CreateFontA() {
	typedef HFont(__thiscall* OriginalFn)(void*);
	return Misc::GetVFunc<OriginalFn>(this, 66)(this);
}

bool ISurface::SetFontGlyphSet(HFont font, const char* windowsFontName, int tall, int weight, int blur, int scanlines, int flags, int nRangeMin, int nRangeMax) {
	typedef bool(__thiscall* OriginalFn)(void*, HFont, const char*, int, int, int, int, int, int, int); // try removing last 2 args after working
	return Misc::GetVFunc<OriginalFn>(this, 67)(this, font, windowsFontName, tall, weight, blur, scanlines, flags, nRangeMin, nRangeMax);
}

void ISurface::SurfaceGetCursorPos(int& w, int& h) {
	typedef void(__thiscall* OriginalFn)(void*, int&, int&);
	return Misc::GetVFunc<OriginalFn>(this, 97)(this, w, h);
}