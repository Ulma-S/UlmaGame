#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

namespace UlmaEngine {
	namespace Core {
		class Texture {
		public:
			Texture();
			Texture(const char* fileName);
			~Texture();

			void Activate() const;
			void Inactivate();
			
			inline unsigned int GetWidth() const { return m_texWidth; }
			inline unsigned int GetHeight() const { return m_texHeight; }
			inline std::string GetName() const { return m_fileName; }


		private:
			bool CreateTexture();
			bool CreateTexture(const char* fileName);

			std::string m_fileName;
			GLuint m_texId;
			int m_texWidth;
			int m_texHeight;
			unsigned char* m_texBuffer;
			bool m_isActive;
		};
	}
}