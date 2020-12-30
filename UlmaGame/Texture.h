#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

namespace System {
	namespace Core {
		class Texture {
		public:
			Texture();
			Texture(const char* fileName);
			~Texture();

			void Activate();
			void Inactivate();
			
			inline unsigned int GetWidth() const { return m_texWidth; }
			inline unsigned int GetHeight() const { return m_texHeight; }

		private:
			bool CreateTexture();
			bool CreateTexture(const char* fileName);
			
			GLuint m_texId;
			int m_texWidth;
			int m_texHeight;
			unsigned char* m_texBuffer;
			bool m_isActive;
		};
	}
}