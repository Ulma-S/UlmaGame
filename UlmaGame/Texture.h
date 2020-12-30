#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>


namespace System {
	namespace Core {
		class Texture {
		public:
			Texture();
			Texture(int width, int height);
			~Texture();

			bool CreateTexture();

			void Activate();
			void Inactivate();
			
			inline int GetWidth() const { return m_texWidth; }
			inline int GetHeight() const { return m_texHeight; }

		private:
			GLuint m_texId;
			int m_texWidth;
			int m_texHeight;
			char* m_texBuffer;
			bool m_isActive;
		};
	}
}