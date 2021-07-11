#pragma once
#include <iostream>

namespace Math {
	class Vector3;
	
	class Vector2 {
	public:
		float x, y;

		Vector2();
		Vector2(float x, float y);
		Vector2(const Vector3& vec);
		~Vector2();

		float Magnitude() const;	//�傫����Ԃ�

		void Normalize();	//���̃x�N�g���𐳋K��
		Vector2 GetNormalized() const;	//���K�����ꂽ�x�N�g����Ԃ�

		float GetAngle(const Vector2& vec) const;

		void RotateRad(float rad);	//�ʓx�@�ŉ�]������
		void RotateDeg(float deg);	//�x���@�ŉ�]������

		float Cross(const Vector2& vec) const;	//�O��
		float Dot(const Vector2& vec) const;	//����

		static const Vector2 zero;

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
}