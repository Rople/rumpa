#include "Vector.h"

Vector3D Vector3D::operator - (Vector3D vec2) {
	Vector3D vec;

	vec.x = this->x - vec2.x;

	vec.y = this->y - vec2.y;

	vec.z = this->z - vec2.z;

	return vec;
}

bool Vector3D::operator ! () {
	if (!x && !y && !z)
		return true;

	return false;
}

Vector3D Vector3D::operator * (int multiplier) {
	Vector3D vec;

	vec.x = this->x * multiplier;
	vec.y = this->y * multiplier;
	vec.z = this->z * multiplier;

	return vec;
}

float Vector3D::GetLength() {
	return sqrtf((x * x) + (y * y) + (z * z));
}

float Vector3D::GetDistance(Vector3D vec2) {
	Vector3D vec;

	vec.x = x - vec2.x;
	vec.y = y - vec2.y;
	vec.z = z - vec2.z;

	return vec.GetLength();
}

Vector3D Vector3D::GetNormalized() {
	float length = this->GetLength();
	Vector3D vec;

	if (length) {
		vec.x = x / length;
		vec.y = y / length;
		vec.z = z / length;
	}

	return vec;
}


Vector2D Vector2D::operator - (Vector2D vec2) {
	Vector2D vec;

	vec.x = this->x - vec2.x;
	vec.y = this->y - vec2.y;

	return vec;
}