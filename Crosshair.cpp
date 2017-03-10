#include "Crosshair.h"

void CCrosshair::DrawCrosshair() {
	G::pSurface->DrawSetColor(232, 19, 207, 255);

	if (crosshairType == CROSSHAIR_CROSS_COMPACT) {
		G::pSurface->DrawFilledRect((G::scrW / 2) - 11, (G::scrH / 2) - 1, (G::scrW / 2) + 11, (G::scrH / 2) + 1);
		G::pSurface->DrawFilledRect((G::scrW / 2) - 1, (G::scrH / 2) - 11, (G::scrW / 2) + 1, (G::scrH / 2) + 11);
	}
	else if (crosshairType == CROSSHAIR_CROSS_SEPERATED) {
		G::pSurface->DrawFilledRect((G::scrW / 2) - 11, (G::scrH / 2) - 1, (G::scrW / 2) - 3, (G::scrH / 2) + 1); // left line
		G::pSurface->DrawFilledRect((G::scrW / 2) + 3, (G::scrH / 2) - 1, (G::scrW / 2) + 11, (G::scrH / 2) + 1); // right line

		G::pSurface->DrawFilledRect((G::scrW / 2) - 1, (G::scrH / 2) - 11, (G::scrW / 2) + 1, (G::scrH / 2) - 3);; // top line
		G::pSurface->DrawFilledRect((G::scrW / 2) - 1, (G::scrH / 2) + 3, (G::scrW / 2) + 1, (G::scrH / 2) + 11);; // bottom line
	}
	else if (crosshairType == CROSSHAIR_DOT) {

	}
	else if (crosshairType == CROSSHAIR_X) {
		G::pSurface->DrawLine((G::scrW / 2) - 8, (G::scrH / 2) - 8, (G::scrW / 2) + 8, (G::scrH / 2) + 8);
		G::pSurface->DrawFilledRect((G::scrW / 2) + 8, (G::scrH / 2) + 8, (G::scrW / 2) - 8, (G::scrH / 2) - 8);
	}
}