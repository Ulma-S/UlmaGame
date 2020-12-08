#pragma once
 
namespace Math {
	class Vector2 {
	public:
		float x, y;

		Vector2();
		Vector2(float _x, float _y);
		~Vector2();

		float Magnitude() const ;	//‘å‚«‚³‚ğ•Ô‚·
		
		void Normalize();	//‚±‚ÌƒxƒNƒgƒ‹‚ğ³‹K‰»
		Vector2 GetNormalized() const;	//³‹K‰»‚³‚ê‚½ƒxƒNƒgƒ‹‚ğ•Ô‚·

		float GetAngle(Vector2& vec) const;

		void RotateRad(float rad);	//ŒÊ“x–@‚Å‰ñ“]‚³‚¹‚é
		void RotateDeg(float deg);	//“x”–@‚Å‰ñ“]‚³‚¹‚é

		float Dot(Vector2& vec) const;	//“àÏ

		inline Vector2& operator = (const Vector2& v) {
			this->x = v.x;
			this->y = v.y;
			return *this;
		}

		inline bool operator == (const Vector2& v) {
			if (this->x == v.x && this->y == v.y) {
				return true;
			}
			else {
				return false;
			}
		}

		inline bool operator != (const Vector2& v) {
			if (this->x == v.x && this->y == v.y) {
				return false;
			}
			else {
				return true;
			}
		}

		inline Vector2 operator + (const Vector2& v) const {
			Vector2 out;
			out.x = this->x + v.x;
			out.y = this->y + v.y;
			return out;
		}

		inline Vector2 operator - (const Vector2& v) const {
			Vector2 out;
			out.x = this->x - v.x;
			out.y = this->y - v.y;
			return out;
		}

		inline Vector2 operator * (const float f) const {
			Vector2 out;
			out.x = this->x * f;
			out.y = this->y * f;
			return out;
		}

		inline Vector2 operator / (const float f) const {
			Vector2 out;
			out.x = this->x / f;
			out.y = this->y / f;
			return out;
		}

		inline Vector2& operator += (const Vector2& v) {
			this->x += v.x;
			this->y += v.y;
			return *this;
		}

		inline Vector2& operator -= (const Vector2& v) {
			this->x -= v.x;
			this->y -= v.y;
			return *this;
		}

		inline Vector2& operator *= (const float f) {
			this->x *= f;
			this->y *= f;
			return *this;
		}

		inline Vector2& operator *= (const Vector2& v) {
			this->x *= v.x;
			this->y *= v.y;
			return *this;
		}

		inline Vector2& operator /= (const float f) {
			this->x /= f;
			this->y /= f;
			return *this;
		}
	};
}