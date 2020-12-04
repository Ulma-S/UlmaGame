#include "ApplicationCore.h"
#include "WindowOpenGL.h"
#include "InputManagerOpenGL.h"

using namespace System::Core;

int main() {
	WindowOpenGL window;
	ApplicationCore appCore;

	bool success = appCore.Initialize(window);

	//InputManagerèâä˙âª
	InputSystem::InputManagerOpenGL::GetInstance().SetWindow(window);

	if (success) {
		appCore.Update();
	}
	appCore.Finalize();
	return 0;
}