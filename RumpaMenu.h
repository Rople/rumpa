#pragma once

#ifndef RUMPAMENU_H
#define RUMPAMENU_H

#include <iostream>
#include <vector>
#include "BaseElement.h"
#include "CheckBox.h"
#include "ComboBox.h"
#include "Globals.h"

typedef unsigned long HFont;

class CRumpaMenu {
public:
	CRumpaMenu();
	~CRumpaMenu();
	void Draw();
	void OnClick(int mouseX, int mouseY);
	void MouseMoved(int mouseX, int mouseY);
	bool m_bIsOpen = true;
	bool m_bIsReady = false;
	int x0, y0, x1, y1;
	HFont testFont; // remove
private:
	void MakeMenu();
	void GetMenuSize();
	std::vector<CBaseElement*> elements;
};

#endif // !RUMPAMENU_H