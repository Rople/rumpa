#pragma once

#ifndef ANTISCREENGRAB_H
#define ANTISCREENGRAB_H

#include "Globals.h"

int DetouredCapture(lua_State* lua);

class CAntiScreengrab {
public:
	CAntiScreengrab();
	~CAntiScreengrab();
	const char* oldCaptureName = "efgeufhiefjef"; // generate random string here
};

#endif // !ANTISCREENGRAB_H