#pragma once

namespace System {
	namespace Core {
		namespace InputSystem {
			enum EKeyCode {
				Q, W, E, R, T, Y, U, I, O, P, A, S, D, F, G, H, J, K, L,
				Z, X, C, V, B, N, M,
				Key_0, Key_1, Key_2, Key_3, Key_4, Key_5, Key_6, Key_7, Key_8, Key_9,
				Space, LeftCtrl, RightCtrl, Esc,
				Key_Up, Key_Down, Key_Left, Key_Right,
			};

			enum EMouseButton {
				Left = 0,
				Right = 1,
				Middle = 2,
			};

			enum EAxisType {
				Horizontal,
				Vertical,
			};

			class IInputManager {
			public:
				virtual ~IInputManager() = default;

				virtual const bool GetKey(EKeyCode key) = 0;
				virtual const bool GetKeyDown(EKeyCode key) = 0;

				virtual const bool GetMouseButton(EMouseButton mouse) = 0;
				virtual const bool GetMouseButtonDown(EMouseButton mouse) = 0;

				virtual const float GetAxis(EAxisType axis) = 0;
			};
		}
	}
}