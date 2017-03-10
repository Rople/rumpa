#include "ComboBox.h"

CComboBox::CComboBox(const wchar_t* name, int posX, int posY, std::vector<const wchar_t*> names, int* pEnum) {
	this->name = name;
	this->posX = posX;
	this->posY = posY;
	this->names = names;
	this->pEnum = pEnum;

	int curYPos = G::pMenu->y0 + posY + COMBOBOX_HEIGHT;
	int i = 0;

	for (const wchar_t* name : names) {
		CComboOption cco(name, i, G::pMenu->x0 + posX, curYPos, pEnum);
		comboOptions.push_back(cco);

		curYPos += COMBOOPTION_HEIGHT;
		++i;
	}
}

void CComboBox::Draw() {
	G::pSurface->DrawSetColor(43, 177, 214, 255);
	G::pSurface->DrawFilledRect(G::pMenu->x0 + posX, G::pMenu->y0 + posY, G::pMenu->x0 + posX + COMBOBOX_WIDTH, G::pMenu->y0 + posY + COMBOBOX_HEIGHT);

	// text inside the box
	G::pSurface->DrawSetTextColor(255, 255, 255, 255);
	G::pSurface->DrawSetTextPos(G::pMenu->x0 + posX + 4, G::pMenu->y0 + posY + 2);
	G::pSurface->DrawSetTextFont(G::pMenu->testFont);

	wchar_t finalStr[30];
	wcscpy(finalStr, name);
	wcscat(finalStr, L" - ");
	wcscat(finalStr, names.at(*pEnum));

	G::pSurface->DrawPrintText(finalStr, wcslen(finalStr), FONT_DRAW_DEFAULT);

	if (bActivated) {
		for (CComboOption cco : comboOptions)
			cco.Draw();
	}
}

void CComboBox::OnClick(int mouseX, int mouseY) {
	if (bActivated) {
		for (CComboOption cco : comboOptions)
			cco.Update(mouseX, mouseY);

		bActivated = false;
	}
	else if ((mouseX > (G::pMenu->x0 + posX) && mouseX < (G::pMenu->x0 + posX + COMBOBOX_WIDTH)) && (mouseY > (G::pMenu->y0 + posY) && mouseY < (G::pMenu->y0 + posY + COMBOBOX_HEIGHT)))
		bActivated = !bActivated;
	else if (!((mouseX >(G::pMenu->x0 + posX) && mouseX < (G::pMenu->x0 + posX + COMBOBOX_WIDTH)) && ((G::pMenu->y0 + mouseY) > posY && mouseY < (G::pMenu->y0 + posY + COMBOBOX_HEIGHT)))
		&& bActivated)
		bActivated = false;
}

void CComboBox::OnHover(int mouseX, int mouseY) {
	
}


CComboOption::CComboOption(const wchar_t* name, int index, int posX, int posY, int* pEnum) {
	this->name = name;
	this->posX = posX;
	this->posY = posY;
	this->index = index;
	this->pEnum = pEnum;
}

void CComboOption::Update(int mouseX, int mouseY) {
	if ((mouseX > posX && mouseX < posX + COMBOOPTION_WIDTH) && (mouseY > posY && mouseY < posY + COMBOOPTION_HEIGHT)) {
		*pEnum = index;
	}
}

void CComboOption::Draw() {
	if (index % 2 == 0)
		G::pSurface->DrawSetColor(16, 127, 158, 255);
	else
		G::pSurface->DrawSetColor(43, 177, 214, 255);

	G::pSurface->DrawFilledRect(posX, posY, posX + COMBOOPTION_WIDTH, posY + COMBOOPTION_HEIGHT);

	G::pSurface->DrawSetTextColor(255, 255, 255, 255);
	G::pSurface->DrawSetTextPos(posX + 4, posY);
	G::pSurface->DrawSetTextFont(G::pMenu->testFont);
	G::pSurface->DrawPrintText(name, wcslen(name), FONT_DRAW_DEFAULT);
}