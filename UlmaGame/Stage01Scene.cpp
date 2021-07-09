#include "Stage01Scene.h"
#include "Player.h"

using namespace SampleGame;

Stage01Scene::Stage01Scene(ISceneManager& sceneManager, const std::string& sceneName)
	: Scene(sceneManager, sceneName)
{
	new Player(*this);
}


Stage01Scene::~Stage01Scene() {}

