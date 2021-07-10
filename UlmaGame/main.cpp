#include "UlmaEngine.h"
#include "TitleScene.h"
#include "Stage01Scene.h"
#include "GameClearScene.h"
#include "GameOverScene.h"

using namespace UlmaEngine;
using namespace SceneManagement;

//テクスチャを登録する関数.
void RegisterTexture() {
	Core::TextureProvider::GetInstance().RegisterTexture("noodle", *(new Core::Texture("noodle.png")));
	Core::TextureProvider::GetInstance().RegisterTexture("brown", *(new Core::Texture("brown.png")));
	Core::TextureProvider::GetInstance().RegisterTexture("blue", *(new Core::Texture("blue.png")));
	Core::TextureProvider::GetInstance().RegisterTexture("title", *(new Core::Texture("title.png")));
	Core::TextureProvider::GetInstance().RegisterTexture("gameClear", *(new Core::Texture("gameClear.png")));
	Core::TextureProvider::GetInstance().RegisterTexture("gameOver", *(new Core::Texture("gameOver.png")));



	for (int i = 1; i <= 5; ++i) {
		auto name = "Idle/idle_00" + std::to_string(i) + ".png";
		Core::TextureProvider::GetInstance().RegisterTexture("idle" + std::to_string(i), *(new Core::Texture(name.c_str())));
	}

	for (int i = 1; i <= 10; i++) {
		if (i <= 9) {
			auto name = "Run/run_00" + std::to_string(i) + ".png";
			Core::TextureProvider::GetInstance().RegisterTexture("run" + std::to_string(i), *(new Core::Texture(name.c_str())));
		}
		else {
			auto name = "Run/run_0" + std::to_string(i) + ".png";
			Core::TextureProvider::GetInstance().RegisterTexture("run" + std::to_string(i), *(new Core::Texture(name.c_str())));
		}
	}

}

//シーンを登録する関数.
void RegisterScene() {
	SceneManagement::SceneManager::GetInstance()
		.BindScenes([&](const std::string& sceneName) {
			Scene* scene = nullptr;

			if (sceneName == "title") {
				auto title = new SampleGame::TitleScene(SceneManager::GetInstance(), "title");
				scene = title;
			}
			else if (sceneName == "stage01") {
				auto stage01 = new SampleGame::Stage01Scene(SceneManager::GetInstance(), "stage01");
				scene = stage01;
			}
			else if (sceneName == "gameClear") {
				auto gameClear = new SampleGame::GameClearScene(SceneManager::GetInstance(), "gameClear");
				scene = gameClear;
			}
			else if (sceneName == "gameOver") {
				auto gameOver = new SampleGame::GameOverScene(SceneManager::GetInstance(), "gameOver");
				scene = gameOver;
			}

			return scene;
		});
}

int main() {
	Core::WindowOpenGL window;
	Core::ApplicationCore appCore;

	//ServiceLocatorにインスタンスを登録.
	auto input = new InputSystem::InputProviderOpenGL();
	input->SetWindow(window);
	ServiceLocator::Register<InputSystem::IInputProvider>(input);

	bool success = appCore.Initialize(window, RegisterTexture, RegisterScene);

	if (success) {
		if (!SceneManager::GetInstance().LoadScene("title")) {
			Debug::LogError("シーンのロードに失敗しました.");
			return 1;
		}

		appCore.Update();
	}
	return 0;
}