#pragma once
#include "Vector.h"

namespace Math {
	class Matrix4 {
	public:
		float mat[4][4];

		Matrix4();
		Matrix4(float mat[4][4]);

		~Matrix4();

		static const Matrix4 Identity;	//単位行列

		//演算子のオーバーロード
		inline friend Matrix4 operator * (const Matrix4& a, const Matrix4& b) {
			Matrix4 result;

			//0行目
			result.mat[0][0] =
				a.mat[0][0] * b.mat[0][0] +
				a.mat[0][1] * b.mat[1][0] +
				a.mat[0][2] * b.mat[2][0] +
				a.mat[0][3] * b.mat[3][0];

			result.mat[0][1] =
				a.mat[0][0] * b.mat[0][1] +
				a.mat[0][1] * b.mat[1][1] +
				a.mat[0][2] * b.mat[2][1] +
				a.mat[0][3] * b.mat[3][1];

			result.mat[0][2] =
				a.mat[0][0] * b.mat[0][2] +
				a.mat[0][1] * b.mat[1][2] +
				a.mat[0][2] * b.mat[2][2] +
				a.mat[0][3] * b.mat[3][2];

			result.mat[0][1] =
				a.mat[0][0] * b.mat[0][3] +
				a.mat[0][1] * b.mat[1][3] +
				a.mat[0][2] * b.mat[2][3] +
				a.mat[0][3] * b.mat[3][3];

			//1行目
			result.mat[1][0] =
				a.mat[1][0] * b.mat[0][0] +
				a.mat[1][1] * b.mat[1][0] +
				a.mat[1][2] * b.mat[2][0] +
				a.mat[1][3] * b.mat[3][0];

			result.mat[1][1] =
				a.mat[1][0] * b.mat[0][1] +
				a.mat[1][1] * b.mat[1][1] +
				a.mat[1][2] * b.mat[2][1] +
				a.mat[1][3] * b.mat[3][1];

			result.mat[1][2] =
				a.mat[1][0] * b.mat[0][2] +
				a.mat[1][1] * b.mat[1][2] +
				a.mat[1][2] * b.mat[2][2] +
				a.mat[1][3] * b.mat[3][2];

			result.mat[1][3] =
				a.mat[1][0] * b.mat[0][3] +
				a.mat[1][1] * b.mat[1][3] +
				a.mat[1][2] * b.mat[2][3] +
				a.mat[1][3] * b.mat[3][3];

			//2行目
			result.mat[2][0] =
				a.mat[2][0] * b.mat[0][0] +
				a.mat[2][1] * b.mat[1][0] +
				a.mat[2][2] * b.mat[2][0] +
				a.mat[2][3] * b.mat[3][0];

			result.mat[2][1] =
				a.mat[2][0] * b.mat[0][1] +
				a.mat[2][1] * b.mat[1][1] +
				a.mat[2][2] * b.mat[2][1] +
				a.mat[2][3] * b.mat[3][1];

			result.mat[1][2] =
				a.mat[1][0] * b.mat[0][2] +
				a.mat[1][1] * b.mat[1][2] +
				a.mat[1][2] * b.mat[2][2] +
				a.mat[1][3] * b.mat[3][2];

			result.mat[1][3] =
				a.mat[1][0] * b.mat[0][3] +
				a.mat[1][1] * b.mat[1][3] +
				a.mat[1][2] * b.mat[2][3] +
				a.mat[1][3] * b.mat[3][3];

			//3行目
			result.mat[3][0] =
				a.mat[3][0] * b.mat[0][0] +
				a.mat[3][1] * b.mat[1][0] +
				a.mat[3][2] * b.mat[2][0] +
				a.mat[3][3] * b.mat[3][0];

			result.mat[3][1] =
				a.mat[3][0] * b.mat[0][1] +
				a.mat[3][1] * b.mat[1][1] +
				a.mat[3][2] * b.mat[2][1] +
				a.mat[3][3] * b.mat[3][1];

			result.mat[3][2] =
				a.mat[3][0] * b.mat[0][2] +
				a.mat[3][1] * b.mat[1][2] +
				a.mat[3][2] * b.mat[2][2] +
				a.mat[3][3] * b.mat[3][2];

			result.mat[3][3] =
				a.mat[3][0] * b.mat[0][3] +
				a.mat[3][1] * b.mat[1][3] +
				a.mat[3][2] * b.mat[2][3] +
				a.mat[3][3] * b.mat[3][3];
			return result;
		}
	
		inline Matrix4& operator *= (const Matrix4& in) {
			*this = *this * in;
			return *this;
		}

		inline Vector3 GetRight() {
			return Vector3(mat[3][0], mat[3][1], mat[3][2]);
		}
	};
}