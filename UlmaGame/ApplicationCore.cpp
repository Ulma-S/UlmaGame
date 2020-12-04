#include "ApplicationCore.h"
#include "Actor.h"
#include "IWindow.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Player.h"

using namespace System::SceneManagement;

System::Core::ApplicationCore::ApplicationCore()
	: m_window(nullptr)
	, m_frameTime(0.0)
{}


System::Core::ApplicationCore::ApplicationCore(IWindow& window)
	: m_window(&window)
	, m_frameTime(0.0)
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

	//Scene�쐬
	Scene* gameScene = new Scene(SceneManager::GetInstance(), Game::Game);
	SceneManager::GetInstance().AddScene(Game::Game, *gameScene);

	//Actor�쐬
	Game::Player* player = new Game::Player(*gameScene);

	SceneManager::GetInstance().LoadScene(Game::Game);
	return true;
}


void System::Core::ApplicationCore::Update() {
	while (m_window->CanLoop()) {
		//delta time�v�Z
		float deltaTime = m_window->GetCurrentTime() - m_frameTime;
		if (deltaTime > 0.05f) {
			deltaTime = 0.05f;
		}
		m_frameTime = m_window->GetCurrentTime();

		m_window->ClearDisplayBuffer();	//�f�B�X�v���C�o�b�t�@�̃N���A

		SceneManagement::SceneManager::GetInstance().UpdateScene(deltaTime);	//�V�[����Update

		m_window->SwapBuffer();	//�_�u���o�b�t�@�̃X���b�v

		m_window->PollEvent();	//�C�x���g����
	}
	Finalize();
}


void System::Core::ApplicationCore::Finalize() {
	m_window->Finalize();
}
