#include "ApplicationCore.h"
#include "WindowOpenGL.h"

using namespace System::Core;

int main() {
	WindowOpenGL window;
	ApplicationCore appCore;

	bool success = appCore.Initialize(window);
	if (success) {
		appCore.Update();
	}
	appCore.Finalize();
	return 0;
}