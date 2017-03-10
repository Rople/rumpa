#include "IPanel.h"

const char* IPanel::GetName(int iPanel) {
	typedef const char*(__thiscall* OriginalFn)(void*, int);
	return Misc::GetVFunc<OriginalFn>(this, 36)(this, iPanel);
}