#pragma once

#ifndef CHECKBOX_H
#define CHECKBOX_H

#include "Globals.h"
#include "BaseElement.h"

class CCheckBox : public CBaseElement {
public:
	CCheckBox(const wchar_t* name, bool* var, int posX, int posY);
	void Draw();
	void OnClick(int mouseX, int mouseY);
	void OnHover(int mouseX, int mouseY);
private:
	int posX, posY;
	bool* m_pbEnabled;
	const wchar_t* name;
};

#endif // !CHECKBOX_H