#include "Vector.h"
#include "MathExt.h"

Math::Vector2::Vector2()
	: x(0.0f)
	, y(0.0f)
{}


Math::Vector2::Vector2(float _x, float _y)
	: x(_x)
	, y(_y)
{}


Math::Vector2::~Vector2() {}


float Math::Vector2::Magnitude() const {
	float mag = sqrt(this->x * this->x + this->y * this->y);
	return mag;
}


void Math::Vector2::Normalize() {
	float normalizedX = this->x / Magnitude();
	float normalizedY = this->y / Magnitude();
	this->x = normalizedX;
	this->y = normalizedY;
}


Math::Vector2 Math::Vector2::GetNormalized() const {
	Vector2 vec;
	vec.x = this->x / Magnitude();
	vec.y = this->y / Magnitude();
	return vec;
}


float Math::Vector2::GetAngle(Vector2& vec) const {
	float cos = Dot(vec) / (Magnitude() * vec.Magnitude());
	return acos(cos);
}


void Math::Vector2::RotateRad(float rad) {
	float rotatedX = cos(rad) * this->x - sin(rad) * this->y;
	float rotatedY = cos(rad) * this->y + cos(rad) * this->y;
	this->x = rotatedX;
	this->y = rotatedY;
}


void Math::Vector2::RotateDeg(float deg) {
	RotateRad(DegToRad(deg));
}


float Math::Vector2::Dot(Vector2& vec) const {
	float dot = this->x * vec.x + this->y * vec.y;
	return dot;
}


//-----------Vector3-------------//

Math::Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f)
{}


Math::Vector3::Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z)
{}


Math::Vector3::~Vector3() {
}


float Math::Vector3::Magnitude() const {
	float mag = sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
	return mag;
}


void Math::Vector3::Normalize() {
	float normalizedX = this->x / Magnitude();
	float normalizedY = this->y / Magnitude();
	float normalizedZ = this->z / Magnitude();
	this->x = normalizedX;
	this->y = normalizedY;
	this->z = normalizedZ;
}


Math::Vector3 Math::Vector3::GetNormalized() const {
	Vector3 vec;
	vec.x = this->x / Magnitude();
	vec.y = this->y / Magnitude();
	vec.z = this->z / Magnitude();
	return vec;
}
