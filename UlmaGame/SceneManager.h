#pragma once
#include <unordered_map>
#include "SceneList.h"

class SceneManager {
public:
	SceneManager();
	~SceneManager();

	void UpdateScene();
	void ChangeScene();

	void AddScene(ESceneType type, class SceneBase& scene);
	void RemoveScene(ESceneType type);

private:
	std::unordered_map<ESceneType, class SceneBase*> m_sceneMap;
};