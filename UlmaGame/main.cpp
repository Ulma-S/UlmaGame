#include "ApplicationCore.h"
#include "WindowOpenGL.h"
#include "InputManagerOpenGL.h"
#include "ShaderLoaderOpenGL.h"
#include "ServiceLocator.h"

using namespace UlmaEngine;

int main() {
	Core::WindowOpenGL window;
	Core::ApplicationCore appCore;

	auto input = new InputSystem::InputManagerOpenGL();
	input->SetWindow(window);
	ServiceLocator::Register<InputSystem::IInputManager>(input);
	
	bool success = appCore.Initialize(window);

	if (success) {
		appCore.Update();
	}
	return 0;
}