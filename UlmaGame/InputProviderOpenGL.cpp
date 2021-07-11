#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "WindowOpenGL.h"
#include "InputProviderOpenGL.h"

using namespace UlmaEngine::Core;
using namespace UlmaEngine::InputSystem;

InputProviderOpenGL::InputProviderOpenGL() : m_window(nullptr), m_isPressed(false) {}


InputProviderOpenGL::~InputProviderOpenGL(){}


bool InputProviderOpenGL::GetKey(EKeyCode key) {
	bool keyState = false;

	switch (key) {
	case Q:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_Q) == GLFW_PRESS);
		break;

	case W:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_W) == GLFW_PRESS);
		break;

	case E:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_E) == GLFW_PRESS);
		break;

	case R:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_R) == GLFW_PRESS);
		break;

	case T:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_T) == GLFW_PRESS);
		break;

	case Y:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_Y) == GLFW_PRESS);
		break;
	
	case U:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_U) == GLFW_PRESS);
		break;
	
	case I:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_I) == GLFW_PRESS);
		break;
	
	case O:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_O) == GLFW_PRESS);
		break;
	
	case P:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_P) == GLFW_PRESS);
		break;
	
	case A:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_A) == GLFW_PRESS);
		break;
	
	case S:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_S) == GLFW_PRESS);
		break;

	case D:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_D) == GLFW_PRESS);
		break;
	
	case F:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_F) == GLFW_PRESS);
		break;
	
	case G:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_G) == GLFW_PRESS);
		break;
	
	case H:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_H) == GLFW_PRESS);
		break;
	
	case J:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_J) == GLFW_PRESS);
		break;
	
	case K:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_K) == GLFW_PRESS);
		break;
	
	case L:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_L) == GLFW_PRESS);
		break;
	
	case Z:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_Z) == GLFW_PRESS);
		break;
	
	case X:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_X) == GLFW_PRESS);
		break;
	
	case C:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_C) == GLFW_PRESS);
		break;
	
	case V:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_V) == GLFW_PRESS);
		break;
	
	case B:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_B) == GLFW_PRESS);
		break;
	
	case N:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_N) == GLFW_PRESS);
		break;
	
	case M:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_M) == GLFW_PRESS);
		break;

	case Key_0:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_0) == GLFW_PRESS);
		break;

	case Key_1:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_1) == GLFW_PRESS);
		break;

	case Key_2:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_2) == GLFW_PRESS);
		break;

	case Key_3:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_3) == GLFW_PRESS);
		break;

	case Key_4:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_4) == GLFW_PRESS);
		break;

	case Key_5:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_5) == GLFW_PRESS);
		break;

	case Key_6:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_6) == GLFW_PRESS);
		break;

	case Key_7:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_7) == GLFW_PRESS);
		break;

	case Key_8:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_8) == GLFW_PRESS);
		break;

	case Key_9:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_9) == GLFW_PRESS);
		break;

	case Space:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_SPACE) == GLFW_PRESS);
		break;

	case LeftCtrl:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS);
		break;

	case RightCtrl:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_RIGHT_CONTROL) == GLFW_PRESS);
		break;

	case Esc:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_ESCAPE) == GLFW_PRESS);
		break;

	case Key_Up:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_UP) == GLFW_PRESS);
		break;


	case Key_Down:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_DOWN) == GLFW_PRESS);
		break;

	case Key_Left:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_LEFT) == GLFW_PRESS);
		break;

	case Key_Right:
		keyState = (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_RIGHT) == GLFW_PRESS);
		break;


	default:
		keyState = false;
		break;
	}

	return keyState;
}


bool InputProviderOpenGL::GetKeyDown(EKeyCode key) {
	bool keyState = false;
	switch (key) {
	case Q:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_Q) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case W:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_W) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case E:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_E) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case R:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_R) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case T:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_T) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case Y:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_Y) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case U:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_U) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case I:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_I) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case O:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_O) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case P:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_P) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case A:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_A) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case S:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_S) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case D:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_D) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case F:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_F) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case G:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_G) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case H:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_H) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case J:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_J) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case K:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_K) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case L:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_L) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case Z:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_Z) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case X:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_X) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case C:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_C) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case V:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_V) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case B:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_B) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case N:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_W) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case M:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_W) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case Key_0:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_0) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;
	
	case Key_1:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_1) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;
		
	case Key_2:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_2) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case Key_3:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_3) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case Key_4:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_4) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case Key_5:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_5) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case Key_6:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_6) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case Key_7:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_7) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case Key_8:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_8) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case Key_9:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_9) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case Space:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_SPACE) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break; 
	
	case LeftCtrl:
			if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {
				if (!m_isPressed) {
					m_isPressed = true;
					keyState = true;
				}
				else {
					keyState = false;
				}
			}
			else {
				m_isPressed = false;
			}
			break;

	case RightCtrl:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_RIGHT_CONTROL) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case Esc:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case Key_Up:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_UP) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case Key_Down:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_DOWN) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case Key_Left:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_LEFT) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case Key_Right:
		if (glfwGetKey(&(m_window->GetWindow()), GLFW_KEY_RIGHT) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				keyState = true;
			}
			else {
				keyState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	default:
		keyState = false;
		break;
	}
	return keyState;
}


bool InputProviderOpenGL::GetMouseButton(EMouseButton mouse) {
	bool mouseState = false;

	switch (mouse) {
	case Left:
		mouseState = (glfwGetMouseButton(&(m_window->GetWindow()), GLFW_MOUSE_BUTTON_1) == GLFW_PRESS);
		break;

	case Right:
		mouseState = (glfwGetMouseButton(&(m_window->GetWindow()), GLFW_MOUSE_BUTTON_2) == GLFW_PRESS);
		break;

	case Middle:
		mouseState = (glfwGetMouseButton(&(m_window->GetWindow()), GLFW_MOUSE_BUTTON_3) == GLFW_PRESS);
		break;

	default:
		mouseState = false;
		break;
	}

	return mouseState;
}


bool InputProviderOpenGL::GetMouseButtonDown(EMouseButton mouse) {
	bool mouseState = false;

	switch (mouse) {
	case Left:
		if (glfwGetMouseButton(&(m_window->GetWindow()), GLFW_MOUSE_BUTTON_1) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				mouseState = true;
			}
			else {
				mouseState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case Right:
		if (glfwGetMouseButton(&(m_window->GetWindow()), GLFW_MOUSE_BUTTON_2) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				mouseState = true;
			}
			else {
				mouseState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	case Middle:
		if (glfwGetMouseButton(&(m_window->GetWindow()), GLFW_MOUSE_BUTTON_3) == GLFW_PRESS) {
			if (!m_isPressed) {
				m_isPressed = true;
				mouseState = true;
			}
			else {
				mouseState = false;
			}
		}
		else {
			m_isPressed = false;
		}
		break;

	default:
		mouseState = false;
		m_isPressed = false;
		break;
	}
	return mouseState;
}


float InputProviderOpenGL::GetAxis(EAxisType axis) {
	float value = 0.0f;

	switch (axis) {
	case Horizontal:
		if (GetKey(EKeyCode::D) || GetKey(EKeyCode::Key_Right)) {
			value = 1.0f;
		}
		else if (GetKey(EKeyCode::A) || GetKey(EKeyCode::Key_Left)) {
			value = -1.0f;
		}
		else {
			value = 0.0f;
		}
		break;
	
	case Vertical:
		if (GetKey(EKeyCode::W) || GetKey(EKeyCode::Key_Up)) {
			value = 1.0f;
		}
		else if (GetKey(EKeyCode::S) || GetKey(EKeyCode::Key_Down)) {
			value = -1.0f;
		}
		else {
			value = 0.0f;
		}
		break;
	
	default:
		value = 0.0f;
		break;
	}
	return value;
}


const Math::Vector2 InputProviderOpenGL::GetMousePos() {
	double x, y;
	glfwGetCursorPos(&(m_window->GetWindow()), &x, &y);
	
	if (x >= m_window->GetWindowWidth()) {
		x = m_window->GetWindowWidth() - 1;
	}
	if (x < 0) {
		x = 0;
	}
	if (y >= m_window->GetWindowHeight()) {
		y = m_window->GetWindowHeight() - 1;
	}
	if (y < 0) {
		y = 0;
	}
	return Math::Vector2(static_cast<float>(x), static_cast<float>(y));
}