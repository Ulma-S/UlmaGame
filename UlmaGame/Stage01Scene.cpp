#include "Stage01Scene.h"
#include "Player.h"
#include "Enemy.h"
#include "Ground.h"
#include "Wall.h"
#include "Background.h"

using namespace SampleGame;

Stage01Scene::Stage01Scene(ISceneManager& sceneManager, const std::string& sceneName)
	: Scene(sceneManager, sceneName)
{
	new Player(*this);
	new Enemy(*this);
	new Ground(*this);
	new Wall(*this, Math::Vector2(800.f, 0.f));
	new Background(*this);
}


Stage01Scene::~Stage01Scene() {}

