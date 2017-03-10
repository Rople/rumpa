#pragma once

#ifndef SHOULDDRAWLOCALPLAYER_H
#define SHOULDDRAWLOCALPLAYER_H

#include "Globals.h"

typedef bool(__stdcall* ShouldDrawLocalPlayerFn)(void* pPlayer);
ShouldDrawLocalPlayerFn origShouldDrawLocalPlayer;


bool __stdcall hkShouldDrawLocalPlayer(void* pPlayer) {
	return true;
}

#endif SHOULDDRAWLOCALPLAYER_H