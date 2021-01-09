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
			void Activate();	//�V�F�[�_�[�̎g�p��錾
			void Unload();	//�v���O�����I�u�W�F�N�g�̃������J��


			//�V�F�[�_�[�̒��_�����Z�b�g
			void SetAttributeVertices(const char* attrib, float vertices[]);

			//�V�F�[�_�[��uniform�ϐ����Z�b�g
			void SetUniformInt(const char* uniform, GLint value);
			void SetUniformFloat(const char* uniform, GLfloat value);
			void SetUniformVec2(const char* uniform, const Math::Vector2& value);
			void SetUniformMat4(const char* uniform, const Math::Matrix4& value);

		private:
			GLuint CreateProgram(const char* vert, const char* frag);	//�V�F�[�_�[�t�@�C���̃R���p�C��
			bool ReadShaderSource(const char* name, std::vector<GLchar>& buffer);	//�V�F�[�_�[�t�@�C���̓ǂݍ���
		
			GLuint m_programId;
		};
	}
}