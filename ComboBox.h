#pragma once

#ifndef COMBOBOX_H
#define COMBOBOX_H

#include "Globals.h"
#include "BaseElement.h"
#include "RumpaMenu.h"

#define COMBOBOX_WIDTH			130
#define COMBOBOX_HEIGHT			22
#define COMBOOPTION_WIDTH		130
#define COMBOOPTION_HEIGHT		18

class CComboOption;

class CComboBox : public CBaseElement {
public:
	CComboBox(const wchar_t* name, int xPos, int yPos, std::vector<const wchar_t*>, int* pEnum);
	void Draw();
	void OnClick(int mouseX, int mouseY);
	void OnHover(int mouseX, int mouseY);
private:
	int* pEnum;
	std::vector<CComboOption> comboOptions;
	int posX, posY;
	bool bActivated;
	std::vector<const wchar_t*> names;
	const wchar_t* name;
};


class CComboOption {
public:
	CComboOption(const wchar_t* name, int index, int posX, int posY, int* pEnum);
	void Draw();
	void Update(int mouseX, int mouseY);
private:
	int* pEnum;
	int index;
	int posX, posY;
	const wchar_t* name;
};

/* How 2 combo box 

	Check if box has been clicked
	If yes then activate a bool and show all the options else deactivate

	if dropdown is active, and the list is showing then once a user clicks an option the enum corresponds to the element id of the names vector
*/

#endif // !COMBOBOX_H