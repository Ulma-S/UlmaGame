#include "ApplicationCore.h"
#include "Actor.h"
#include "WindowOpenGL.h"

System::Core::ApplicationCore::ApplicationCore(IWindow& window, System::SceneManagement::SceneManager& sceneManager)
	: m_window(&window)
{}


System::Core::ApplicationCore::~ApplicationCore(){
}


bool System::Core::ApplicationCore::Initialize() {
	//ウィンドウ作成
	bool success = m_window->CreateWindow();
	if (!success) {
		return false;
	}
	return true;
}


void System::Core::ApplicationCore::Update() {
	while (m_window->CanLoop()) {
	}
}


void System::Core::ApplicationCore::Finalize() {
	m_window->Finalize();
}
