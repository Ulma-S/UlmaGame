#include "SceneManager.h"
#include "Scene.h"
#include "Debug.h"

using namespace UlmaEngine;

SceneManagement::SceneManager::SceneManager() : m_currentScene(nullptr) {}


SceneManagement::SceneManager::~SceneManager() {
	std::unordered_map<std::string, Scene*>().swap(m_sceneMap);
}


void SceneManagement::SceneManager::UpdateScene(float deltaTime){
	if (m_currentScene == nullptr) return;
	m_currentScene->Update(deltaTime);
}


void SceneManagement::SceneManager::GenerateOutput(Core::ShaderLoaderOpenGL& shader) {
	m_currentScene->GenerateOutput(shader);
}


bool SceneManagement::SceneManager::LoadScene(const std::string& sceneName) {
	//シーンが存在しなければreturn
	auto it = m_sceneMap.find(sceneName);
	if (it == m_sceneMap.end()) {
		UlmaEngine::Debug::LogError(sceneName + "シーンが存在しません.");
		return false;
	}

	//シーンの終了処理
	if (m_currentScene != nullptr) {
		m_currentScene->OnExit();
	}

	//シーンの読み込み時の処理
	m_currentScene = it->second;
	m_currentScene->OnEnter();
	return true;
}


void SceneManagement::SceneManager::AddScene(const std::string& sceneName, Scene& scene) {
	//既に追加していたらreturn
	if (m_sceneMap.count(sceneName) != 0) return;
	m_sceneMap[sceneName] = &scene;
}


void SceneManagement::SceneManager::RemoveScene(const std::string& sceneName) {
	//キーが存在しなければreturn
	auto it = m_sceneMap.find(sceneName);
	if (it == m_sceneMap.end()) return;
	m_sceneMap.erase(it);
}
