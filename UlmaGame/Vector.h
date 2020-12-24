#pragma once
 
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
	};
}