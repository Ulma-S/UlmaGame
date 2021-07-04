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
			void ClearDisplayBuffer() const override;
			void SwapBuffer() const override;
			void Finalize() const override;

			void PollEvent() const override;
			bool CanLoop() const override;
			float GetCurrentTime() const override;

			inline GLFWwindow& GetWindow() const { return *m_window; }
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