#pragma once
#include "Singleton.h"
#include "IInputManager.h"

namespace UlmaEngine {
	namespace Core {
		class WindowOpenGL;
	}

	namespace InputSystem {
		class InputManagerOpenGL : public Singleton<InputManagerOpenGL>, IInputManager {
		public:
			~InputManagerOpenGL();

			const bool GetKey(EKeyCode key) override;
			const bool GetKeyDown(EKeyCode key) override;

			const bool GetMouseButton(EMouseButton mouse) override;
			const bool GetMouseButtonDown(EMouseButton mouse) override;

			const float GetAxis(EAxisType axis) override;

			const Math::Vector2 GetMousePos() override;

			inline void SetWindow(Core::WindowOpenGL& window) { m_window = &window; }

		protected:
			friend Singleton<InputManagerOpenGL>;
			InputManagerOpenGL();

		private:
			Core::WindowOpenGL* m_window;

			bool m_isPressed;
		};

	}
}