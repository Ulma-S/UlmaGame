#pragma once
#include "Vector.h"
#include "MathExt.h"

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

			result.mat[0][3] =
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

			result.mat[2][2] =
				a.mat[2][0] * b.mat[0][2] +
				a.mat[2][1] * b.mat[1][2] +
				a.mat[2][2] * b.mat[2][2] +
				a.mat[2][3] * b.mat[3][2];

			result.mat[2][3] =
				a.mat[2][0] * b.mat[0][3] +
				a.mat[2][1] * b.mat[1][3] +
				a.mat[2][2] * b.mat[2][3] +
				a.mat[2][3] * b.mat[3][3];

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
			return Vector3(mat[0][0], mat[0][1], mat[0][2]).GetNormalized();
		}

		inline Vector3 GetLeft() {
			return Vector3(-mat[0][0], mat[0][1], mat[0][2]).GetNormalized();
		}

		inline Vector3 GetUp() {
			return Vector3(mat[1][0], mat[1][1], mat[1][2]).GetNormalized();
		}

		inline Vector3 GetDown() {
			return Vector3(mat[1][0], -mat[1][1], mat[1][2]).GetNormalized();
		}

		inline Vector3 GetForward() {
			return Vector3(mat[2][0], mat[2][1], -mat[2][2]).GetNormalized();
		}

		inline Vector3 GetBack() {
			return Vector3(mat[2][0], mat[2][1], mat[2][2]).GetNormalized();
		}

		//回転行列 (引数は度数法)
		static inline Matrix4 CreateRotationX(float angle) {
			float tmp[4][4] = {
				{1.0f, 0.0f, 0.0f, 0.0f},
				{0.0f, Math::Cos(angle), Math::Sin(angle), 0.0f},
				{0.0f, -Math::Sin(angle), Math::Cos(angle), 0.0f },
				{0.0f, 0.0f, 0.0f, 1.0f},
			};
			return Matrix4(tmp);
		}

		static inline Matrix4 CreateRotationY(float angle) {
			float tmp[4][4] = {
				{Math::Cos(angle), 0.0f, -Math::Sin(angle), 0.0f},
				{0.0f, 1.0f, 0.0f, 0.0f},
				{Math::Sin(angle), 0.0f, Math::Cos(angle), 0.0f },
				{0.0f, 0.0f, 0.0f, 1.0f},
			};
			return Matrix4(tmp);
		}

		static inline Matrix4 CreateRotationZ(float angle) {
			float tmp[4][4] = {
				{Math::Cos(angle), Math::Sin(angle), 0.0f, 0.0f},
				{-Math::Sin(angle), Math::Cos(angle), 0.0f, 0.0f},
				{0.0f, 0.0f, 1.0f, 0.0f },
				{0.0f, 0.0f, 0.0f, 1.0f},
			};
			return Matrix4(tmp);
		}

		//平行移動行列
		static inline Matrix4 CreateTranslation(Math::Vector3& ts) {
			float tmp[4][4] = {
				{1.0f, 0.0f, 0.0f, 0.0f},
				{0.0f, 1.0f, 0.0f, 0.0f},
				{0.0f, 0.0f, 1.0f, 0.0f},
				{ts.x, ts.y, ts.z, 1.0f}
			};
			return Matrix4(tmp);
		}

		//拡大縮小行列
		static inline Matrix4 CreateScale(float xSc, float ySc, float zSc) {
			float tmp[4][4] = {
				{xSc, 0.0f, 0.0f, 0.0f},
				{0.0f, ySc, 0.0f, 0.0f},
				{0.0f, 0.0f, zSc, 0.0f},
				{0.0f, 0.0f, 0.0f, 1.0f},
			};
			return Matrix4(tmp);
		}

		static inline Matrix4 CreateScale(Math::Vector3& vSc) {
			return CreateScale(vSc.x, vSc.y, vSc.z);
		}

		static inline Matrix4 CreateScale(float sc) {
			return CreateScale(sc, sc, sc);
		}

		static inline Matrix4 CreateViewProj(float width, float height) {
			float tmp[4][4] = {
				{2.0f/width, 0.0f, 0.0f, 0.0f},
				{0.0f, 2.0f/height, 0.0f, 0.0f},
				{0.0f, 0.0f, 1.0f, 0.0f},
				{0.0f, 0.0f, 1.0f, 1.0f}
			};
			return Matrix4(tmp);
		}
	};
}