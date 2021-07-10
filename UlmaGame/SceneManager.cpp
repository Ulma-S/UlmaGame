#include "SceneManager.h"
#include "Scene.h"
#include "Debug.h"

using namespace UlmaEngine;

SceneManagement::SceneManager::SceneManager() : m_currentScene(nullptr), m_isUpdating(false), m_nextSceneName(""),m_isRequestedLoadScene(false) {}


SceneManagement::SceneManager::~SceneManager() {
	m_currentScene->OnExit();
	delete m_currentScene;
}


void SceneManagement::SceneManager::UpdateScene(float deltaTime) {
	if (m_currentScene == nullptr) {
		return;
	}
	m_isUpdating = true;
	m_currentScene->Update(deltaTime);
	m_isUpdating = false;

	//シーンのロードを要求されていたらロードする.
	if(m_isRequestedLoadScene) {
		ExecuteLoadScene(m_nextSceneName);
		m_isRequestedLoadScene = false;
	}
}


void SceneManagement::SceneManager::GenerateOutput(const Core::ShaderLoaderOpenGL& shader) {
	m_currentScene->GenerateOutput(shader);
}


bool SceneManagement::SceneManager::LoadScene(const std::string& sceneName) {
	//更新中でなければシーンをロードする.
	if (!m_isUpdating) {
		ExecuteLoadScene(sceneName);
		m_isRequestedLoadScene = false;
		return true;
	}

	m_isRequestedLoadScene = true;
	m_nextSceneName = sceneName;
	return false;
}


bool SceneManagement::SceneManager::ExecuteLoadScene(const std::string& sceneName) {
	if (m_createSceneInstancesFunc == nullptr) {
		return false;
	}
	auto nextScene = m_createSceneInstancesFunc(sceneName);

	if (nextScene == nullptr) {
		Debug::LogError(sceneName + "シーンが存在しません.");
		return false;
	}

	if (m_currentScene != nullptr) {
		m_currentScene->OnExit();
	}

	m_currentScene = nextScene;
	nextScene->OnEnter();
	return true;
}

