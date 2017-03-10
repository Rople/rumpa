#pragma once

#ifndef OVERRIDEVIEW_H
#define OVERRIDEVIEW_H

#include "Globals.h"

class CViewSetup {
public:
	int x;
	int unscaled_x;
	int y;
	int unscaled_y;
	int width;
	int unscaled_width;
	int height;
	int stereo_eye;
	int unscaled_height;
	//char _pad0x24[0x78];
	bool ortho;
	float ortho_left;
	float ortho_top;
	float ortho_right;
	float ortho_bottom;
	float fov;
	float fov_viewmodel;
	Vector3D origin;
	QAngle angles;
	float z_near;
	float z_far;
	float z_near_viewmodel;
	float z_far_viewmodel;
	bool render_to_subrect_of_larger_screen;
	float aspect_ratio;
	bool off_center;
	float off_center_top;
	float off_center_bottom;
	float off_center_left;
	float off_center_right;
	bool do_bloom_and_tone_mapping;
	bool cache_full_scene_state;
	bool view_to_projection_override;
	//Matrix view_to_projection;
};

typedef void(__stdcall* OverrideViewFn)(CViewSetup*);
OverrideViewFn origOverrideView;


void __stdcall hkOverrideView(CViewSetup* pViewSetup) {
	pViewSetup->fov = 110.0f;

	origOverrideView(pViewSetup);
}

#endif OVERRIDEVIEW_H