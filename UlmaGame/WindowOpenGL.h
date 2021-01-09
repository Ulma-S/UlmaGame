#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "IWindow.h"

namespace UlmaEngine {
	namespace Core {
		class WindowOpenGL : public IWindow {
		public:
			WindowOpenGL();
			WindowOpenGL(int windowWidth, int windowHeight);
			~WindowOpenGL();

			bool CreateWindow() override;
			void ClearDisplayBuffer() override;
			void SwapBuffer() override;
			void Finalize() override;

			void PollEvent() override;
			bool CanLoop() override;
			float GetCurrentTime() override;

			inline GLFWwindow& GetWindow() { return *m_window; }
			inline int GetWindowWidth() const { return m_windowWidth; }
			inline int GetWindowHeight() const { return m_windowHeight; }
			inline float GetScale() const { return m_scale; }

		private:
			GLFWwindow* m_window;

			int m_windowWidth;
			int m_windowHeight;
			float m_scale;
		};
	}
}