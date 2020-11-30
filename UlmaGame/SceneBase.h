#pragma once
#include <vector>

class SceneBase {
public:
	SceneBase(class SceneManager& sceneManager);
	virtual ~SceneBase() = default;

	virtual void OnEnter() = 0;
	virtual void Update() = 0;
	virtual void OnExit() = 0;


protected:
	class SceneManager* m_sceneManager;
	std::vector<class Actor*> m_sceneActors;
};