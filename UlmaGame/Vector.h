#pragma once
#include <iostream> 

namespace Math {
	class Vector2 {
	public:
		float x, y;

		Vector2();
		Vector2(float _x, float _y);
		~Vector2();

		float Magnitude() const ;	//大きさを返す
		
		void Normalize();	//このベクトルを正規化
		Vector2 GetNormalized() const;	//正規化されたベクトルを返す

		float GetAngle(Vector2& vec) const;

		void RotateRad(float rad);	//弧度法で回転させる
		void RotateDeg(float deg);	//度数法で回転させる

		float Dot(Vector2& vec) const;	//内積

		inline Vector2& operator = (const Vector2& v) {
			this->x = v.x;
			this->y = v.y;
			return *this;
		}

		inline friend bool operator == (const Vector2& v1, const Vector2& v2) {
			if (v1.x == v2.x && v1.y == v2.y) {
				return true;
			}
			else {
				return false;
			}
		}

		inline friend bool operator != (const Vector2& v1, const Vector2& v2) {
			if (v1.x == v2.x && v1.y == v2.y) {
				return false;
			}
			else {
				return true;
			}
		}

		inline friend Vector2 operator + (const Vector2& v1, const Vector2& v2) {
			Vector2 out;
			out.x = v1.x + v2.x;
			out.y = v1.y + v2.y;
			return out;
		}

		inline friend Vector2 operator - (const Vector2& v1, const Vector2& v2) {
			Vector2 out;
			out.x = v1.x - v2.x;
			out.y = v1.y - v2.y;
			return out;
		}

		inline friend Vector2 operator * (const Vector2& v, const float f) {
			Vector2 out;
			out.x = v.x * f;
			out.y = v.y * f;
			return out;
		}

		inline Vector2 operator / (const float f) const {
			Vector2 out;
			out.x = this->x / f;
			out.y = this->y / f;
			return out;
		}

		inline Vector2& operator += (const Vector2& v) {
			*this = *this + v;
			return *this;
		}

		inline Vector2& operator -= (const Vector2& v) {
			*this = *this - v;
			return *this;
		}

		inline Vector2& operator *= (const float f) {
			*this = *this * f;
			return *this;
		}

		inline Vector2& operator /= (const float f) {
			this->x /= f;
			this->y /= f;
			return *this;
		}

		inline friend std::ostream& operator << (std::ostream& os, const Vector2& v) {
			os << "(" << v.x << ", " << v.y << ")";
			return os;
		}
	};

	class Vector3 {
	public:
		float x, y, z;

		Vector3();
		Vector3(float x, float y, float z);
		~Vector3();
	
		float Magnitude() const;	//大きさを返す

		void Normalize();	//このベクトルを正規化
		Vector3 GetNormalized() const;	//正規化されたベクトルを返す

		inline static Vector3 GetRight() { return Vector3(1.0f, 0.0f, 0.0f); }
		inline static Vector3 GetUp() { return Vector3(0.0f, 1.0f, 0.0f); }

		inline Vector3& operator = (const Vector3& v) {
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
			return *this;
		}

		inline friend bool operator == (const Vector3& v1, const Vector3& v2) {
			if (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z) {
				return true;
			}
			else {
				return false;
			}
		}

		inline friend bool operator != (const Vector3& v1, const Vector3& v2) {
			if (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z) {
				return false;
			}
			else {
				return true;
			}
		}

		inline friend Vector3 operator + (const Vector3& v1, const Vector3& v2) {
			Vector3 out;
			out.x = v1.x + v2.x;
			out.y = v1.y + v2.y;
			out.z = v1.z + v2.z;
			return out;
		}

		inline friend Vector3 operator - (const Vector3& v1, const Vector3& v2) {
			Vector3 out;
			out.x = v1.x - v2.x;
			out.y = v1.y - v2.y;
			out.z = v1.z - v2.z;
			return out;
		}

		inline friend Vector3 operator * (float f, const Vector3& v) {
			Vector3 out;
			out.x = v.x * f;
			out.y = v.y * f;
			out.z = v.z * f;
			return out;
		}

		inline friend Vector3 operator * (const Vector3& v, float f) {
			Vector3 out;
			out.x = v.x * f;
			out.y = v.y * f;
			out.z = v.z * f;
			return out;
		}

		inline Vector3 operator / (const float f) const {
			Vector3 out;
			out.x = this->x / f;
			out.y = this->y / f;
			out.z = this->z / f;
			return out;
		}

		inline Vector3& operator += (const Vector3& v) {
			*this = *this + v;
			return *this;
		}

		inline Vector3& operator -= (const Vector3& v) {
			*this = *this - v;
			return *this;
		}

		inline Vector3& operator *= (const float f) {
			*this = *this * f;
			return *this;
		}

		inline Vector3& operator /= (const float f) {
			this->x /= f;
			this->y /= f;
			return *this;
		}

		inline friend std::ostream& operator << (std::ostream& os, const Vector3& v) {
			os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
			return os;
		}
	};
}