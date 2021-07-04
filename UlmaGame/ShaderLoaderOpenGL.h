#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

namespace Math {
	class Vector2;
	class Matrix4;
}

namespace UlmaEngine {
	namespace Core {
		class IWindow;

		class ShaderLoaderOpenGL {
		public:
			ShaderLoaderOpenGL();
			~ShaderLoaderOpenGL();

			bool LoadProgram(const char* vert, const char* frag);
			void Activate() const;	//シェーダーの使用を宣言
			void Unload() const;	//プログラムオブジェクトのメモリ開放


			//シェーダーの頂点情報をセット
			void SetAttributeVertices(const char* attrib, float vertices[]) const;

			//シェーダーのuniform変数をセット
			void SetUniformInt(const char* uniform, GLint value) const;
			void SetUniformFloat(const char* uniform, GLfloat value) const;
			void SetUniformVec2(const char* uniform, const Math::Vector2& value) const;
			void SetUniformMat4(const char* uniform, const Math::Matrix4& value) const;

		private:
			GLuint CreateProgram(const char* vert, const char* frag);	//シェーダーファイルのコンパイル
			bool ReadShaderSource(const char* name, std::vector<GLchar>& buffer);	//シェーダーファイルの読み込み
		
			GLuint m_programId;
		};
	}
}