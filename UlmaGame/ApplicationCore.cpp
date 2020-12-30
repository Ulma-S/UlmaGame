#include "ApplicationCore.h"
#include "Actor.h"
#include "IWindow.h"
#include "ShaderLoaderOpenGL.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Debug.h"
#include "Player.h"

using namespace System::SceneManagement;

System::Core::ApplicationCore::ApplicationCore()
	: m_window(nullptr)
	, m_frameTime(0.0f)
	, m_unlitShader(nullptr)
	, m_spriteShader(nullptr)
{}


System::Core::ApplicationCore::ApplicationCore(IWindow& window)
	: m_window(&window)
	, m_frameTime(0.0f)
	, m_unlitShader(nullptr)
	, m_spriteShader(nullptr)
{}


System::Core::ApplicationCore::~ApplicationCore(){
	m_unlitShader->Unload();
	delete m_unlitShader;
}


bool System::Core::ApplicationCore::Initialize(IWindow& window) {
	m_window = &window;

	//ウィンドウ作成
	bool success = m_window->CreateWindow();
	if (!success) {
		return false;
	}

	//シェーダー初期化
	m_unlitShader = new ShaderLoaderOpenGL();
	if (!m_unlitShader->LoadProgram("unlit.vert", "unlit.frag")) {
		System::Debug::Log("unlitシェーダーのロードに失敗しました");
		return false;
	}
	m_unlitShader->Activate();

	m_spriteShader = new ShaderLoaderOpenGL();
	if (!m_spriteShader->LoadProgram("sprite.vert", "sprite.frag")) {
		System::Debug::Log("spriteシェーダーのロードに失敗しました");
		return false;
	}
	m_spriteShader->Activate();

	//ビュー変換
	Math::Matrix4 viewProj = Math::Matrix4::CreateViewProj(640.0f, 480.0f);
	m_unlitShader->SetUniformMat4("uViewProj", viewProj);
	m_spriteShader->SetUniformMat4("uViewProj", viewProj);
	
	//Scene作成
	Scene* gameScene = new Scene(SceneManager::GetInstance(), Game::Game);
	SceneManager::GetInstance().AddScene(Game::Game, *gameScene);

	//Actor作成
	Game::Player* player = new Game::Player(*gameScene);

	SceneManager::GetInstance().LoadScene(Game::Game);
	return true;
}


void System::Core::ApplicationCore::Update() {
	while (m_window->CanLoop()) {
		//delta time計算
		float deltaTime = m_window->GetCurrentTime() - m_frameTime;
		if (deltaTime > 0.05f) {
			deltaTime = 0.05f;
		}
		m_frameTime = m_window->GetCurrentTime();

		m_window->ClearDisplayBuffer();	//ディスプレイバッファのクリア

		SceneManagement::SceneManager::GetInstance().UpdateScene(deltaTime);	//シーンの更新
		SceneManagement::SceneManager::GetInstance().GenerateOutput(*m_spriteShader);

		m_window->SwapBuffer();	//ダブルバッファのスワップ

		m_window->PollEvent();	//イベント処理
	}
	Finalize();
}


void System::Core::ApplicationCore::Finalize() {
	m_window->Finalize();
}
