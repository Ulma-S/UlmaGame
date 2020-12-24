#include <memory.h>
#include "Matrix.h"

using namespace Math;


Matrix4::Matrix4() {
	*this = Matrix4::Identity;
}


Matrix4::Matrix4(float inMat[4][4]) {
	memcpy(mat, inMat, 16 * sizeof(float));
}


Matrix4::~Matrix4(){
}


static float mat4Ident[4][4] = {
	{1.0f, 0.0f, 0.0f, 0.0f},
	{0.0f, 1.0f, 0.0f, 0.0f},
	{0.0f, 0.0f, 1.0f, 0.0f},
	{0.0f, 0.0f, 0.0f, 1.0f},
};


const Matrix4 Matrix4::Identity(mat4Ident);
