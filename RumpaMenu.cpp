#include "RumpaMenu.h"

CRumpaMenu::CRumpaMenu() {
	GetMenuSize();
}

CRumpaMenu::~CRumpaMenu() {
	for (CBaseElement* e : elements)
		delete e;
}

void CRumpaMenu::GetMenuSize() { // needed because scrh and scrh is always 0 if gmod is minimized
	x0 = G::scrW / 2 - 360;
	y0 = 10;
	x1 = G::scrW / 2 + 360;
	y1 = y0 + 270;
}

void CRumpaMenu::Draw() {
	GetMenuSize();

	if (!m_bIsReady)
		MakeMenu();

	G::pSurface->DrawSetColor(43, 177, 214, 255);
	G::pSurface->DrawFilledRect(x0 - 2, y0 - 2, x1 + 2, y1 + 2);

	G::pSurface->DrawSetColor(40, 40, 40, 255);
	G::pSurface->DrawFilledRect(x0, y0, x1, y1);

	/*	Element drawing	 */
	for (CBaseElement* e : elements)
		e->Draw();

	/* Mouse movement and hovering	*/
	int mouseX, mouseY = 0;
	G::pSurface->SurfaceGetCursorPos(mouseX, mouseY);

	if (mouseX > G::pMenu->x0 && mouseX < G::pMenu->x1 && mouseY > G::pMenu->y0 && mouseY < G::pMenu->y1)
		MouseMoved(mouseX, mouseY);
}

void CRumpaMenu::OnClick(int mouseX, int mouseY) {
	for (CBaseElement* e : elements)
		e->OnClick(mouseX, mouseY);
}

void CRumpaMenu::MouseMoved(int mouseX, int mouseY) {
	for (CBaseElement* e : elements)
		e->OnHover(mouseX, mouseY);
}

void CRumpaMenu::MakeMenu() {
	testFont = G::pSurface->CreateFontA();
	G::pSurface->SetFontGlyphSet(testFont, "Euphemia", 17, 34, 0, 0, FONTFLAG_ANTIALIAS, 0, 0);

	/*	Checkboxes	*/
	CCheckBox* chkBunnyHop = new CCheckBox(L"Bunny Hop", &G::pBunnyHop->m_bEnabled, 10, 10);
	CCheckBox* chkAutoStrafe = new CCheckBox(L"Auto Strafe", &G::pAutoStrafe->m_bEnabled, 10, 40);
	CCheckBox* chkAntiAim = new CCheckBox(L"Anti Aim", &G::pAntiAim->m_bEnabled, 10, 70);
	CCheckBox* chkFlashlightSpam = new CCheckBox(L"Flashlight Spam", &G::pFlashlightSpammer->m_bEnabled, 200, 10);
	CCheckBox* chkPlayerEsp = new CCheckBox(L"Player Esp", &G::pPlayerEsp->m_bEnabled, 200, 40);
	CCheckBox* chkAimbot = new CCheckBox(L"Aimbot", &G::pAimbot->m_bEnabled, 200, 70);
	CCheckBox* chkCrosshair = new CCheckBox(L"Crosshair", &G::pCrosshair->m_bEnabled, 10, 100);

	elements.push_back(chkBunnyHop);
	elements.push_back(chkAutoStrafe);
	elements.push_back(chkFlashlightSpam);
	elements.push_back(chkPlayerEsp);
	elements.push_back(chkAntiAim);
	elements.push_back(chkAimbot);
	elements.push_back(chkCrosshair);

	/*	Comboboxes	*/

	std::vector<const wchar_t*> yawAANames;
	yawAANames.push_back(L"Off");
	yawAANames.push_back(L"Slow Spin");
	yawAANames.push_back(L"Fast Spin");
	yawAANames.push_back(L"Jitter");
	yawAANames.push_back(L"Random");
	yawAANames.push_back(L"Backwards");
	yawAANames.push_back(L"Sideways");
	CComboBox* cmbYawAntiAim = new CComboBox(L"Yaw", 10, 160, yawAANames, &G::pAntiAim->yawAntiAim);

	std::vector<const wchar_t*> pitchAANames;
	pitchAANames.push_back(L"Off");
	pitchAANames.push_back(L"Static Down");
	pitchAANames.push_back(L"Static Up");
	pitchAANames.push_back(L"Jitter");
	CComboBox* cmbPitchAntiAim = new CComboBox(L"Pitch", 150, 160, pitchAANames, &G::pAntiAim->pitchAntiAim);

	std::vector<const wchar_t*> crosshairTypes;
	crosshairTypes.push_back(L"Cross 1");
	crosshairTypes.push_back(L"Cross 2");
	crosshairTypes.push_back(L"Dot");
	crosshairTypes.push_back(L"X");
	CComboBox* cmbCrosshairTypes = new CComboBox(L"Crosshair", 290, 160, crosshairTypes, &G::pCrosshair->crosshairType);

	elements.push_back(cmbYawAntiAim);
	elements.push_back(cmbPitchAntiAim);
	elements.push_back(cmbCrosshairTypes);

	m_bIsReady = true;
}