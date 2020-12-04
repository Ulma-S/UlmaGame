#pragma once
#include "Singleton.h"
#include "IInputManager.h"

namespace System {
	namespace Core {
		namespace InputSystem {
			class InputManagerOpenGL : public General::Singleton<InputManagerOpenGL>, IInputManager {
			public:
				~InputManagerOpenGL();

				const bool GetKey(EKeyCode key) override;
				const bool GetKeyDown(EKeyCode key) override;

				const bool GetMouseButton(EMouseButton mouse) override;
				const bool GetMouseButtonDown(EMouseButton mouse) override;

				const float GetAxis(EAxisType axis) override;

				inline void SetWindow(class WindowOpenGL& window) { m_window = &window; }

			protected:
				friend General::Singleton<InputManagerOpenGL>;
				InputManagerOpenGL();

			private:
				class WindowOpenGL* m_window;

				bool m_isPressed;
			};
		}
	}
}