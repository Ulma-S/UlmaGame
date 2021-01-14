#include "ApplicationCore.h"
#include "Actor.h"
#include "IWindow.h"
#include "ShaderLoaderOpenGL.h"
#include "Texture.h"
#include "TextureProvider.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Debug.h"
#include "Player.h"
#include "Enemy.h"

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
	delete m_unlitShader;

	Finalize();
}


bool Core::ApplicationCore::Initialize(IWindow& window) {
	m_window = &window;

	//�E�B���h�E�쐬
	bool success = m_window->CreateWindow();
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
		Debug::Log("sprite�V�F�[�_�[�̃��[�h�Ɏ��s���܂���");
		return false;
	}
	m_spriteShader->Activate();

	//�e�N�X�`���쐬
	Texture* noodle = new Texture();
	TextureProvider::GetInstance().AddTexture("noodle", *(new Texture("noodle.png")));

	//Scene�쐬
	Scene* gameScene = new Scene(SceneManager::GetInstance(), "Game");
	SceneManager::GetInstance().AddScene("Game", *gameScene);

	//Actor�쐬
	SampleGame::Player* player = new SampleGame::Player(*gameScene);
	SampleGame::Enemy* enemy = new SampleGame::Enemy(*gameScene);

	SceneManager::GetInstance().LoadScene("Game");
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
		Math::Matrix4 viewProj = Math::Matrix4::CreateViewProj((float)m_window->GetWindowWidth(), (float)m_window->GetWindowHeight());
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
