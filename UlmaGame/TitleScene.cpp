#include "TitleScene.h"
#include "TitleManager.h"

SampleGame::TitleScene::TitleScene(ISceneManager& sceneManager, const std::string& sceneName)
	: Scene(sceneManager, sceneName)
{
	new TitleManager(*this);
}


SampleGame::TitleScene::~TitleScene() {}
