#include "MovableTower.h"
#include "TileMap.h"

using namespace SampleGame;

MovableTower::MovableTower(SceneManagement::Scene& scene, float moveSpeed)
	: Actor(scene)
	, m_moveSpeed(moveSpeed)
	, m_move(true)
{
	auto row = 10;
	auto col = 1;
	auto tileMap = new TileMap(*this, 190, row, col, 970.f, 100.f);
	std::vector<std::vector<std::string>> tileArray = std::vector(col, std::vector<std::string>(row));
	for (int i = 0; i < col; ++i) {
		for (int j = 0; j < row; ++j) {
			if (j % 4 == 0) {
				tileArray[i][j] = "bg_tower";
			}
			else {
				tileArray[i][j] = "bg_tower";
			}
		}
	}
	tileMap->Register(tileArray);

	GetTransform().scale = Math::Vector3(2.2f, 2.2f, 1.f);
	GetTransform().position = Math::Vector3(-100.f, 50.f, 0.f);
}


MovableTower::~MovableTower() {}


void MovableTower::UpdateActor(float deltaTime) {
	if(!m_move) {
		return;
	}
	GetTransform().position.x -= m_moveSpeed * deltaTime;
}
