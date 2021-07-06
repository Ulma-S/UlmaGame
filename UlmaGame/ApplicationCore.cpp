#include "ApplicationCore.h"
#include "Actor.h"
#include "IWindow.h"
#include "ShaderLoaderOpenGL.h"
#include "Texture.h"
#include "TextureProvider.h"
#include "SceneManager.h"
#include "Scene.h"
#include "ServiceLocator.h"
#include "IInputManager.h"
#include "InputManagerOpenGL.h"
#include "Debug.h"

#include "Player.h"
#include "Enemy.h"
#include "Ground.h"

#include <any>

using namespace UlmaEngine;
using namespace UlmaEngine::SceneManagement;

Core::ApplicationCore::ApplicationCore()
	: m_window(nullptr)
	, m_frameTime(0.0f)
	, m_unlitShader(nullptr)
	, m_spriteShader(nullptr)
{}


Core::ApplicationCore::ApplicationCore(IWindow& window)
	: m_window(&window)
	, m_frameTime(0.0f)
	, m_unlitShader(nullptr)
	, m_spriteShader(nullptr)
{}


Core::ApplicationCore::~ApplicationCore(){
	m_unlitShader->Unload();
	m_spriteShader->Unload();
	delete m_unlitShader;
	delete m_spriteShader;

	ApplicationCore::Finalize();
}


bool Core::ApplicationCore::Initialize(IWindow& window) {
	m_window = &window;

	//�E�B���h�E�쐬
	auto success = m_window->CreateWindow();
	if (!success) {
		return false;
	}

	//�V�F�[�_�[������
	m_unlitShader = new ShaderLoaderOpenGL();
	if (!m_unlitShader->LoadProgram("unlit.vert", "unlit.frag")) {
		Debug::Log("unlit�V�F�[�_�[�̃��[�h�Ɏ��s���܂���");
		return false;
	}
	m_unlitShader->Activate();

	m_spriteShader = new ShaderLoaderOpenGL();
	if (!m_spriteShader->LoadProgram("sprite.vert", "sprite.frag")) {
		Debug::Log("sprite�V�F�[�_�[�̃��[�h�Ɏ��s���܂���.");
		return false;
	}
	m_spriteShader->Activate();

	//�e�N�X�`���쐬
	TextureProvider::GetInstance().RegisterTexture("noodle", *(new Texture("noodle.png")));
	TextureProvider::GetInstance().RegisterTexture("brown", *(new Texture("brown.png")));
	TextureProvider::GetInstance().RegisterTexture("blue", *(new Texture("blue.png")));

	
	//Scene�쐬
	auto gameScene = new Scene(SceneManager::GetInstance(), "Game");

	//Actor�쐬
	auto player = new SampleGame::Player(*gameScene);
	auto enemy = new SampleGame::Enemy(*gameScene);
	auto ground = new SampleGame::Ground(*gameScene);

	if (!SceneManager::GetInstance().LoadScene("Game")) {
		Debug::LogError("�V�[���̃��[�h�Ɏ��s���܂���.");
		return false;
	}

	return true;
}


void Core::ApplicationCore::Update() {
	while (m_window->CanLoop()) {
		//delta time�v�Z
		float deltaTime = m_window->GetCurrentTime() - m_frameTime;
		if (deltaTime > 0.05f) {
			deltaTime = 0.05f;
		}
		m_frameTime = m_window->GetCurrentTime();

		m_window->ClearDisplayBuffer();	//�f�B�X�v���C�o�b�t�@�̃N���A

		//�r���[�ϊ�
		Math::Matrix4 viewProj = Math::Matrix4::CreateViewProj(static_cast<float>(m_window->GetWindowWidth()),
			static_cast<float>(m_window->GetWindowHeight()));
		m_unlitShader->SetUniformMat4("uViewProj", viewProj);
		m_spriteShader->SetUniformMat4("uViewProj", viewProj);

		SceneManagement::SceneManager::GetInstance().UpdateScene(deltaTime);	//�V�[���̍X�V
		SceneManagement::SceneManager::GetInstance().GenerateOutput(*m_spriteShader);

		m_window->SwapBuffer();	//�_�u���o�b�t�@�̃X���b�v

		m_window->PollEvent();	//�C�x���g����
	}
	Finalize();
}


void Core::ApplicationCore::Finalize() {
	m_window->Finalize();
}
