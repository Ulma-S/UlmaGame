#include "ApplicationCore.h"
#include "Actor.h"
#include "WindowOpenGL.h"
#include "SceneManager.h"
#include "Scene.h"

using namespace System::SceneManagement;

System::Core::ApplicationCore::ApplicationCore(){}


System::Core::ApplicationCore::ApplicationCore(IWindow& window)
	: m_window(&window)
{}


System::Core::ApplicationCore::~ApplicationCore(){
}


bool System::Core::ApplicationCore::Initialize(IWindow& window) {
	m_window = &window;

	//�E�B���h�E�쐬
	bool success = m_window->CreateWindow();
	if (!success) {
		return false;
	}

	//�V�[���쐬
	Scene* gameScene = new Scene(SceneManager::GetInstance(), Game::Game);
	SceneManager::GetInstance().AddScene(Game::Game, *gameScene);
	return true;
}


void System::Core::ApplicationCore::Update() {
	float deltaTime = 0.0f;
	while (m_window->CanLoop()) {
		//�f�B�X�v���C�o�b�t�@�̃N���A
		m_window->ClearDisplayBuffer();

		SceneManagement::SceneManager::GetInstance().UpdateScene(deltaTime);

		//�_�u���o�b�t�@�̃X���b�v
		m_window->SwapBuffer();

		m_window->PollEvent();
	}
	Finalize();
}


void System::Core::ApplicationCore::Finalize() {
	m_window->Finalize();
}
