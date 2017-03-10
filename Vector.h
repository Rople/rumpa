#pragma once

#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>

class Vector3D {
public:
	float x, y, z = 0.0f;
	Vector3D operator - (Vector3D vec2);
	Vector3D operator * (int multiplier);
	bool operator ! ();
	float GetLength();
	float GetDistance(Vector3D vec2);
	Vector3D GetNormalized();
};

class Vector2D {
public:
	float x, y = 0.0f;
	Vector2D operator - (Vector2D vec2);
};


#endif // VECTOR_H