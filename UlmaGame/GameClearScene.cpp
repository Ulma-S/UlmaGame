#include "GameClearScene.h"
#include "GameClearManager.h"

using namespace SampleGame;

SampleGame::GameClearScene::GameClearScene(ISceneManager& sceneManager, const std::string& sceneName)
	: Scene(sceneManager, sceneName)
{
	new GameClearManager(*this);
}


SampleGame::GameClearScene::~GameClearScene() {}

