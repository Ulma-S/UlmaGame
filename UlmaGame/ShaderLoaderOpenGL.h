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
			void Activate();	//�V�F�[�_�[���g�p�\�ɂ���
			void Unload();	//�v���O�����I�u�W�F�N�g�̃������J��

			//�V�F�[�_�[��uniform�ϐ����Z�b�g
			void SetUniformFloat(const char* uniform, GLfloat value);
			void SetUniformVec2(const char* uniform, Math::Vector2& value);

		private:
			GLuint CreateProgram(const char* vert, const char* frag);	//�V�F�[�_�[�t�@�C���̃R���p�C��
			bool ReadShaderSource(const char* name, std::vector<GLchar>& buffer);	//�V�F�[�_�[�t�@�C���̓ǂݍ���
		
			//IWindow* m_window;
			GLuint m_programId;
		};
	}
}