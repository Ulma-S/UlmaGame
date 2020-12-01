#include "ApplicationCore.h"
#include "Actor.h"
#include "WindowOpenGL.h"
#include "SceneManager.h"

System::Core::ApplicationCore::ApplicationCore(){}


System::Core::ApplicationCore::ApplicationCore(IWindow& window)
	: m_window(&window)
{}


System::Core::ApplicationCore::~ApplicationCore(){
}


bool System::Core::ApplicationCore::Initialize(IWindow& window) {
	m_window = &window;

	//ウィンドウ作成
	bool success = m_window->CreateWindow();
	if (!success) {
		return false;
	}
	return true;
}


void System::Core::ApplicationCore::Update() {
	float deltaTime = 0.0f;
	while (m_window->CanLoop()) {
		SceneManagement::SceneManager::GetInstance().UpdateScene(deltaTime);
		m_window->PollEvent();
	}
	Finalize();
}


void System::Core::ApplicationCore::Finalize() {
	m_window->Finalize();
}
