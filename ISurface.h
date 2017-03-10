#pragma once

#ifndef SURFACE_H
#define SURFACE_H

#include "Misc.h"

enum EFontFlags {
	FONTFLAG_NONE,
	FONTFLAG_ITALIC = 0x001,
	FONTFLAG_UNDERLINE = 0x002,
	FONTFLAG_STRIKEOUT = 0x004,
	FONTFLAG_SYMBOL = 0x008,
	FONTFLAG_ANTIALIAS = 0x010,
	FONTFLAG_GAUSSIANBLUR = 0x020,
	FONTFLAG_ROTARY = 0x040,
	FONTFLAG_DROPSHADOW = 0x080,
	FONTFLAG_ADDITIVE = 0x100,
	FONTFLAG_OUTLINE = 0x200,
	FONTFLAG_CUSTOM = 0x400,	// custom generated font - never fall back to asian compatibility mode
	FONTFLAG_BITMAP = 0x800,	// compiled bitmap font - no fallbacks
};

enum FontDrawType_t;
typedef unsigned long HFont;

class ISurface { // CMatSystemSurface
public:
	void DrawSetColor(int, int, int, int);
	void DrawFilledRect(int, int, int, int);
	void DrawOutlinedRect(int, int, int, int);
	void DrawLine(int, int, int, int);
	void DrawSetTextFont(unsigned int hFont);
	void DrawSetTextColor(int r, int g, int b, int a);
	void DrawSetTextPos(int x, int y);
	void DrawPrintText(const wchar_t* text, int textLen, FontDrawType_t drawType);
	HFont CreateFontA();
	bool SetFontGlyphSet(HFont font, const char* windowsFontName, int tall, int weight, int blur, int scanlines, int flags, int nRangeMin = 0, int nRangeMax = 0);
	void SurfaceGetCursorPos(int&, int&);
};

#endif // !SURFACE_H