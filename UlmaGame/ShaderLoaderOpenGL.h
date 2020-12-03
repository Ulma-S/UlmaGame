#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "Singleton.h"

namespace System {
	namespace Core {
		class ShaderLoaderOpenGL : public General::Singleton<ShaderLoaderOpenGL> {
		public:
			~ShaderLoaderOpenGL();

			GLuint LoadProgram(const char* vert, const char* frag);

		private:
			GLuint CreateProgram(const char* vert, const char* frag);

			bool ReadShaderSource(const char* name, std::vector<GLchar>& buffer);
		};
	}
}