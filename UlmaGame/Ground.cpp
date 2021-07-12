#include "Ground.h"
#include "TileMap.h"

SampleGame::Ground::Ground(SceneManagement::Scene& _scene)
	: Actor::Actor(_scene)
{
	GetTransform().position = Math::Vector3(-600.f, -330.f, 0.f);
	GetTransform().scale = Math::Vector3(1.f/6.f, 1.f/6.f, 1.f);

	new BoxCollider2D(*this, Math::Vector3::zero, 5000.f, 150.f, 0.f);

	auto row = 30;
	auto col = 2;
	auto tileMap = new TileMap(*this, 100, row, col, 50.f, 50.f);
	std::vector<std::vector<std::string>> tileArray = std::vector(col, std::vector<std::string>(row));
	for(int i=0; i < col; ++i) {
		for (int j = 0; j < row; ++j) {
			if (j % 4 == 0) {
				tileArray[i][j] = "bg_tile_2";
			}else {
				tileArray[i][j] = "bg_tile_1";
			}
		}
	}
	tileMap->Register(tileArray);
	
	this->name = "Ground";
}


SampleGame::Ground::~Ground() {

}


void SampleGame::Ground::Initialize() {

}


void SampleGame::Ground::UpdateActor(float deltaTime) {

}