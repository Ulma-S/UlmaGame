#pragma once
#define _USE_MATH_DEFINES
#include <cmath>


namespace Math {
	//度数法から弧度法へ変換
	inline float DegToRad(float deg) {
		return deg * (float) M_PI / 180.0f;
	}

	inline float Cos(float deg) {
		return cos(DegToRad(deg));
	}

	inline float Sin(float deg) {
		return sin(DegToRad(deg));
	}
}