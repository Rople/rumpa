#include "Button.h"

CButton::CButton(const wchar_t* buttonName, bool* var, int x0, int y0, int x1, int y1) {
	name = buttonName;
	m_pbEnabled = var;
	this->x0 = x0;
	this->y0 = y0;
	this->x1 = x1;
	this->y1 = y1;
}

void CButton::OnClick(int mouseX, int mouseY) {
	if ((mouseX > x0 && mouseX < x1) && (mouseY > y0 && mouseY < y1))
		*m_pbEnabled = !*m_pbEnabled;
}

void CButton::Draw() {
	if (*m_pbEnabled)
		G::pSurface->DrawSetColor(50, 255, 50, 255);
	else
		G::pSurface->DrawSetColor(255, 50, 50, 255);

	G::pSurface->DrawFilledRect(x0, y0, x1, y1);

	G::pSurface->DrawSetTextColor(255, 255, 255, 255);
	G::pSurface->DrawSetTextPos(x0 + 2, y0 + 1);
	G::pSurface->DrawSetTextFont(139);
	G::pSurface->DrawPrintText(name, wcslen(name), FONT_DRAW_DEFAULT);
}