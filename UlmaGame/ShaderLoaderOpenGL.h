#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "Singleton.h"

namespace Math {
	class Vector2;
}

namespace System {
	namespace Core {
		class IWindow;

		class ShaderLoaderOpenGL {
		public:
			ShaderLoaderOpenGL();
			~ShaderLoaderOpenGL();

			GLuint LoadProgram(const char* vert, const char* frag);
			void Activate();	//シェーダーを使用可能にする
			void Unload();	//プログラムオブジェクトのメモリ開放

			//シェーダーのuniform変数をセット
			void SetUniformFloat(const char* uniform, GLfloat value);
			void SetUniformVec2(const char* uniform, Math::Vector2& value);

		private:
			GLuint CreateProgram(const char* vert, const char* frag);	//シェーダーファイルのコンパイル
			bool ReadShaderSource(const char* name, std::vector<GLchar>& buffer);	//シェーダーファイルの読み込み
		
			//IWindow* m_window;
			GLuint m_programId;
		};
	}
}