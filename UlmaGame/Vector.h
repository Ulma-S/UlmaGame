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
	};
}