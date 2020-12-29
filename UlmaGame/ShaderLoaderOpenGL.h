#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

namespace Math {
	class Vector2;
	class Matrix4;
}

namespace System {
	namespace Core {
		class IWindow;

		class ShaderLoaderOpenGL {
		public:
			ShaderLoaderOpenGL();
			~ShaderLoaderOpenGL();

			bool LoadProgram(const char* vert, const char* frag);
			void Activate();	//シェーダーの使用を宣言
			void Unload();	//プログラムオブジェクトのメモリ開放


			//シェーダーの頂点情報をセット
			void SetAttributeVerticies(const char* attrib, float verticies[]);

			//シェーダーのuniform変数をセット
			void SetUniformInt(const char* uniform, GLint value);
			void SetUniformFloat(const char* uniform, GLfloat value);
			void SetUniformVec2(const char* uniform, const Math::Vector2& value);
			void SetUniformMat4(const char* uniform, const Math::Matrix4& value);

			GLuint GetProgramId() { return m_programId; }

		private:
			GLuint CreateProgram(const char* vert, const char* frag);	//シェーダーファイルのコンパイル
			bool ReadShaderSource(const char* name, std::vector<GLchar>& buffer);	//シェーダーファイルの読み込み
		
			GLuint m_programId;
		};
	}
}