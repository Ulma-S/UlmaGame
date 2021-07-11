#include "Wall.h"

using namespace SampleGame;

Wall::Wall(SceneManagement::Scene& scene, const Math::Vector2& position)
	: Actor(scene)
{
	new SpriteComponent(*this, "brown", ESpriteType::Rectangle);
	new BoxCollider2D(*this, Math::Vector3::zero , 400.f, 400.f);

	GetTransform().position = Math::Vector3(position);

	this->name = "wall";
}


Wall::~Wall() {
	
}

