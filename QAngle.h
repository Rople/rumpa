#pragma once

#ifndef QANGLE_H
#define QANGLE_H

#include <math.h>
#include <iostream>
#include <algorithm>

class QAngle {
public:
	float p, y, r = 0.0f;
	void Normalize();
};


#endif