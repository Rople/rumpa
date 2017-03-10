#include "Checkbox.h"

CCheckBox::CCheckBox(const wchar_t* name, bool* var, int posX, int posY) {
	this->name = name;
	this->m_pbEnabled = var;
	this->posX = posX;
	this->posY = posY;
}

void CCheckBox::OnClick(int mouseX, int mouseY) {
	if ((mouseX > (G::pMenu->x0 + posX) && mouseX < (G::pMenu->x0 + posX + 20)) && (mouseY > (G::pMenu->y0 + posY) && mouseY < (G::pMenu->y0 + posY + 20)))
		*m_pbEnabled = !*m_pbEnabled;
}

void CCheckBox::OnHover(int mouseX, int mouseY) {
	if ((mouseX >(G::pMenu->x0 + posX) && mouseX < (G::pMenu->x0 + posX + 20)) && (mouseY >(G::pMenu->y0 + posY) && mouseY < (G::pMenu->y0 + posY + 20))) {
		
	}
}

void CCheckBox::Draw() {
	G::pSurface->DrawSetColor(43, 177, 214, 255);

	if (*m_pbEnabled) {
		G::pSurface->DrawOutlinedRect(G::pMenu->x0 + posX, G::pMenu->y0 + posY, G::pMenu->x0 + posX + 20, G::pMenu->y0 + posY + 20);
		G::pSurface->DrawFilledRect(G::pMenu->x0 + posX + 4, G::pMenu->y0 + posY + 4, G::pMenu->x0 + posX + 16, G::pMenu->y0 + posY + 16);
	}
	else
		G::pSurface->DrawOutlinedRect(G::pMenu->x0 + posX, G::pMenu->y0 + posY, G::pMenu->x0 + posX + 20, G::pMenu->y0 + posY + 20);

	G::pSurface->DrawSetTextColor(255, 255, 255, 255);
	G::pSurface->DrawSetTextPos(G::pMenu->x0 + posX + 25, G::pMenu->y0 + posY);
	G::pSurface->DrawSetTextFont(G::pMenu->testFont);
	G::pSurface->DrawPrintText(name, wcslen(name), FONT_DRAW_DEFAULT);
}