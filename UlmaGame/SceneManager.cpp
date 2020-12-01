#include "SceneManager.h"
#include "Scene.h"

System::SceneManagement::SceneManager::SceneManager() : m_currentScene(nullptr) {}


System::SceneManagement::SceneManager::~SceneManager() {
	std::unordered_map<Game::ESceneType, Scene*>().swap(m_sceneMap);
}


void System::SceneManagement::SceneManager::UpdateScene(float deltaTime){
	if (m_currentScene == nullptr) return;
	m_currentScene->Update(deltaTime);
}


void System::SceneManagement::SceneManager::LoadScene(Game::ESceneType sceneType){
	//シーンが存在しなければreturn
	auto it = m_sceneMap.find(sceneType);
	if (it == m_sceneMap.end()) return;

	//シーンの終了処理
	m_currentScene->OnExit();

	//シーンの読み込み時の処理
	m_currentScene = it->second;
	m_currentScene->OnEnter();
}


void System::SceneManagement::SceneManager::AddScene(Game::ESceneType sceneType, Scene& scene) {
	//既に追加していたらreturn
	if (m_sceneMap.count(sceneType) != 0) return;
	m_sceneMap[sceneType] = &scene;
}


void System::SceneManagement::SceneManager::RemoveScene(Game::ESceneType sceneType) {
	//キーが存在しなければreturn
	auto it = m_sceneMap.find(sceneType);
	if (it == m_sceneMap.end()) return;
	m_sceneMap.erase(it);
}
