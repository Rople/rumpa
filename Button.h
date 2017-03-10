#pragma once

#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include "Globals.h"

class CButton {
public:
	CButton(const wchar_t* buttonName, bool* var, int x0, int y0, int x1, int y1);
	void Draw();
	void OnClick(int mouseX, int mouseY);
private:
	int x0, y0, x1, y1;
	bool* m_pbEnabled;
	const wchar_t* name;
};

#endif // !BUTTON_H