#include "GameOverScene.h"
#include "GameOverManager.h"

SampleGame::GameOverScene::GameOverScene(ISceneManager& sceneManager, const std::string& sceneName)
	: Scene(sceneManager, sceneName) {
	new GameOverManager(*this);
}


SampleGame::GameOverScene::~GameOverScene() {}

