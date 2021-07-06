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

	//ウィンドウ作成
	auto success = m_window->CreateWindow();
	if (!success) {
		return false;
	}

	//シェーダー初期化
	m_unlitShader = new ShaderLoaderOpenGL();
	if (!m_unlitShader->LoadProgram("unlit.vert", "unlit.frag")) {
		Debug::Log("unlitシェーダーのロードに失敗しました");
		return false;
	}
	m_unlitShader->Activate();

	m_spriteShader = new ShaderLoaderOpenGL();
	if (!m_spriteShader->LoadProgram("sprite.vert", "sprite.frag")) {
		Debug::Log("spriteシェーダーのロードに失敗しました.");
		return false;
	}
	m_spriteShader->Activate();

	//テクスチャ作成
	TextureProvider::GetInstance().RegisterTexture("noodle", *(new Texture("noodle.png")));
	TextureProvider::GetInstance().RegisterTexture("brown", *(new Texture("brown.png")));
	TextureProvider::GetInstance().RegisterTexture("blue", *(new Texture("blue.png")));

	
	//Scene作成
	auto gameScene = new Scene(SceneManager::GetInstance(), "Game");

	//Actor作成
	auto player = new SampleGame::Player(*gameScene);
	auto enemy = new SampleGame::Enemy(*gameScene);
	auto ground = new SampleGame::Ground(*gameScene);

	if (!SceneManager::GetInstance().LoadScene("Game")) {
		Debug::LogError("シーンのロードに失敗しました.");
		return false;
	}

	return true;
}


void Core::ApplicationCore::Update() {
	while (m_window->CanLoop()) {
		//delta time計算
		float deltaTime = m_window->GetCurrentTime() - m_frameTime;
		if (deltaTime > 0.05f) {
			deltaTime = 0.05f;
		}
		m_frameTime = m_window->GetCurrentTime();

		m_window->ClearDisplayBuffer();	//ディスプレイバッファのクリア

		//ビュー変換
		Math::Matrix4 viewProj = Math::Matrix4::CreateViewProj(static_cast<float>(m_window->GetWindowWidth()),
			static_cast<float>(m_window->GetWindowHeight()));
		m_unlitShader->SetUniformMat4("uViewProj", viewProj);
		m_spriteShader->SetUniformMat4("uViewProj", viewProj);

		SceneManagement::SceneManager::GetInstance().UpdateScene(deltaTime);	//シーンの更新
		SceneManagement::SceneManager::GetInstance().GenerateOutput(*m_spriteShader);

		m_window->SwapBuffer();	//ダブルバッファのスワップ

		m_window->PollEvent();	//イベント処理
	}
	Finalize();
}


void Core::ApplicationCore::Finalize() {
	m_window->Finalize();
}
