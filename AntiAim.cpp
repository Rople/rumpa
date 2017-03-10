#include "AntiAim.h"

void CAntiAim::Do(QAngle realView) {
	//if (G::pLocalPlayer->GetMoveType() == MOVETYPE_LADDER || G::pLocalPlayer->GetMoveType() == MOVETYPE_NOCLIP)
		//return;

	if ((G::Cmd->buttons & IN_ATTACK) || (G::Cmd->buttons & IN_USE))
		G::pEngineClient->SetViewAngles(realView);
	else {
		if (pitchAntiAim == PITCH_NONE) // meme antiaims
			fakeView.p = realView.p;
		else if (pitchAntiAim == PITCH_DOWN)
			fakeView.p = -89.0f;
		else if (pitchAntiAim == PITCH_UP)
			fakeView.p = 89.0f;
		else if (pitchAntiAim == PITCH_JITTER) {
			if (flip)
				fakeView.p = -89.0f;
			else
				fakeView.p = 89.0f;
		}

		if (yawAntiAim == YAW_NONE) // meme antiaims
			fakeView.y = realView.y;
		else if (yawAntiAim == YAW_SLOWSPIN)
			fakeView.y += 10;
		else if (yawAntiAim == YAW_FASTSPIN)
			fakeView.y += 26;
		else if (yawAntiAim == YAW_BACKWARDS)
			fakeView.y = realView.y + 180.0f;
		else if (yawAntiAim == YAW_SIDEWAYS)
			fakeView.y = realView.y + 90.0f;
		else if (yawAntiAim == YAW_JITTER) {
			fakeView.y += 210;
		}

		fakeView.r = 0.f;

		fakeView.p = Misc::flClamp(fakeView.p, -89.0f, 89.0f);
		fakeView.y = Misc::NormalizeAngle(fakeView.y);

		G::Cmd->viewangles = fakeView;

		flip = !flip;
	}
}