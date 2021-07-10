#include "ApplicationCore.h"
#include "Actor.h"
#include "IWindow.h"
#include "ShaderLoaderOpenGL.h"
#include "Texture.h"
#include "TextureProvider.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Debug.h"

#include "TitleScene.h"
#include "Stage01Scene.h"
#include "GameClearScene.h"
#include "GameOverScene.h"

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
	TextureProvider::GetInstance().RegisterTexture("title", *(new Texture("title.png")));
	TextureProvider::GetInstance().RegisterTexture("gameClear", *(new Texture("gameClear.png")));
	TextureProvider::GetInstance().RegisterTexture("gameOver", *(new Texture("gameOver.png")));

	for (int i = 1; i <= 5; ++i) {
		auto name = "Idle/idle_00" + std::to_string(i) + ".png";
		TextureProvider::GetInstance().RegisterTexture("idle" + std::to_string(i), *(new Texture(name.c_str())));
	}
	
	for (int i = 1; i <= 10; i++) {
		if (i <= 9) {
			auto name = "Run/run_00" + std::to_string(i) + ".png";
			TextureProvider::GetInstance().RegisterTexture("run" + std::to_string(i), *(new Texture(name.c_str())));
		}else {
			auto name = "Run/run_0" + std::to_string(i) + ".png";
			TextureProvider::GetInstance().RegisterTexture("run" + std::to_string(i), *(new Texture(name.c_str())));
		}
	}

	
	//Scene�o�^.
	SceneManagement::SceneManager::GetInstance()
	.BindScenes([&](const std::string& sceneName) {
		Scene* scene = nullptr;
		
		if(sceneName == "title") {
			auto title = new SampleGame::TitleScene(SceneManager::GetInstance(), "title");
			scene = title;
		}else if(sceneName == "stage01") {
			auto stage01 = new SampleGame::Stage01Scene(SceneManager::GetInstance(), "stage01");
			scene = stage01;
		}else if(sceneName == "gameClear") {
			auto gameClear = new SampleGame::GameClearScene(SceneManager::GetInstance(), "gameClear");
			scene = gameClear;
		}else if(sceneName == "gameOver") {
			auto gameOver = new SampleGame::GameOverScene(SceneManager::GetInstance(), "gameOver");
			scene = gameOver;
		}

		return scene;
	});
	

	if (!SceneManager::GetInstance().LoadScene("title")) {
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
