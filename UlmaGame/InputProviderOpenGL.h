#pragma once
#include <vector>
#include "IInputProvider.h"

namespace UlmaEngine {
	namespace Core {
		class WindowOpenGL;
	}

	namespace InputSystem {
		class InputProviderOpenGL : public IInputProvider {
		public:
			InputProviderOpenGL();
			~InputProviderOpenGL() override;

			bool GetKey(EKeyCode key) override;
			bool GetKeyDown(EKeyCode key) override;

			bool GetMouseButton(EMouseButton mouse) override;
			bool GetMouseButtonDown(EMouseButton mouse) override;

			float GetAxis(EAxisType axis) override;

			const Math::Vector2 GetMousePos() override;

			inline void SetWindow(Core::WindowOpenGL& window) { m_window = &window; }


		private:
			Core::WindowOpenGL* m_window;
			std::vector<bool> m_isPressedArray;
			bool m_isPressed;
		};

	}
}