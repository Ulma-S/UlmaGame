#include "Stage01Scene.h"
#include "Player.h"
#include "Enemy.h"
#include "Ground.h"

using namespace SampleGame;

Stage01Scene::Stage01Scene(ISceneManager& sceneManager, const std::string& sceneName)
	: Scene(sceneManager, sceneName)
{
	new Player(*this);
	new Enemy(*this);
	new Ground(*this);
}


Stage01Scene::~Stage01Scene() {}

