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
#include "Ground.h"



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
