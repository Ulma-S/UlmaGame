#include "Background.h"
#include "TileMap.h"

using namespace SampleGame;

Background::Background(SceneManagement::Scene& scene)
	: Actor(scene)
{
	new SpriteComponent(*this, "bg_sky_night", ESpriteType::Rectangle, 250);
	new SpriteComponent(*this, "bg_moon", ESpriteType::Rectangle, 240);
	new SpriteComponent(*this, "bg_buildings", ESpriteType::Rectangle, 200);
	

	GetTransform().scale = Math::Vector3(2.2f, 2.2f, 1.f);
	GetTransform().position = Math::Vector3(0.f, 50.f, 0.f);
}


Background::~Background() {
	
}


void Background::UpdateActor(float deltaTime) {
	
}
