#pragma once
 
namespace Math {
	class Vector2 {
	public:
		float x, y;

		Vector2();
		Vector2(float _x, float _y);
		~Vector2();

		float Magnitude() const ;	//�傫����Ԃ�
		
		void Normalize();	//���̃x�N�g���𐳋K��
		Vector2 GetNormalized() const;	//���K�����ꂽ�x�N�g����Ԃ�

		float GetAngle(Vector2& vec) const;

		void RotateRad(float rad);	//�ʓx�@�ŉ�]������
		void RotateDeg(float deg);	//�x���@�ŉ�]������

		float Dot(Vector2& vec) const;	//����
	};
}