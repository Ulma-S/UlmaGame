#pragma once
#include "Singleton.h"
#include "IInputManager.h"

namespace UlmaEngine {
	namespace Core {
		class WindowOpenGL;
	}

	namespace InputSystem {
		class InputManagerOpenGL : public IInputManager {
		public:
			InputManagerOpenGL();
			~InputManagerOpenGL() override;

			bool GetKey(EKeyCode key) override;
			bool GetKeyDown(EKeyCode key) override;

			bool GetMouseButton(EMouseButton mouse) override;
			bool GetMouseButtonDown(EMouseButton mouse) override;

			float GetAxis(EAxisType axis) override;

			const Math::Vector2 GetMousePos() override;

			inline void SetWindow(Core::WindowOpenGL& window) { m_window = &window; }


		private:
			Core::WindowOpenGL* m_window;

			bool m_isPressed;
		};

	}
}