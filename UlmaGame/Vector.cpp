#include "Vector.h"
#include "MathExt.h"

Math::Vector2::Vector2()
	: x(0.0f)
	, y(0.0f)
{}


Math::Vector2::Vector2(float x, float y)
	: x(x)
	, y(y)
{}


Math::Vector2::Vector2(Math::Vector3& vec)
	: x(vec.x), y(vec.y)
{}


Math::Vector2::~Vector2() {}


float Math::Vector2::Magnitude() const {
	return sqrt(this->x * this->x + this->y * this->y);
}


void Math::Vector2::Normalize() {
	float normalizedX = this->x / Magnitude();
	float normalizedY = this->y / Magnitude();
	this->x = normalizedX;
	this->y = normalizedY;
}


Math::Vector2 Math::Vector2::GetNormalized() const {
	return Vector2(
		this->x / Magnitude(),
		this->y / Magnitude()
	);
}


float Math::Vector2::GetAngle(const Vector2& vec) const {
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


float Math::Vector2::Cross(const Vector2& vec) const {
	return this->x * vec.y - this->y * vec.x;
}


float Math::Vector2::Dot(const Vector2& vec) const {
	return this->x * vec.x + this->y * vec.y;
}


const Math::Vector2 Math::Vector2::zero(0.0f, 0.0f);

//-----------Vector3-------------//

Math::Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f)
{}


Math::Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z)
{}


Math::Vector3::Vector3(Math::Vector2& vec) : x(vec.x), y(vec.y), z(0.0f)
{}


Math::Vector3::~Vector3() {
}


float Math::Vector3::Magnitude() const {
	return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
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
	return Vector3(
		this->x / Magnitude(),
		this->y / Magnitude(),
		this->z / Magnitude()
	);
}


Math::Vector3 Math::Vector3::Cross(const Math::Vector3& vec) const {
	return Vector3(
		this->y * vec.z - this->z * vec.y,
		this->z * vec.x - this->x * vec.z,
		this->x * vec.y - this->y * vec.x
	);
}


float Math::Vector3::Dot(const Math::Vector3& vec) const{
	return this->x * vec.x + this->y * vec.y + this->z * vec.z;
}


const Math::Vector3 Math::Vector3::zero(0.0f, 0.0f, 0.0f);