#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>


namespace System {
	namespace Core {
		class Texture {
		public:
			Texture();
			~Texture();

			bool CreateTexture();

			void Activate();
			void Inactivate();

		private:
			GLuint m_texId;
			int m_texWidth;
			int m_texHeight;
			char* m_texBuffer;
		};
	}
}