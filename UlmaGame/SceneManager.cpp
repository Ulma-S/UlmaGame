#include "SceneManager.h"
#include "Scene.h"
#include "Debug.h"

using namespace UlmaEngine;

SceneManagement::SceneManager::SceneManager() : m_currentScene(nullptr) {}


SceneManagement::SceneManager::~SceneManager() {
	std::unordered_map<std::string, Scene*>().swap(m_sceneMap);
}


void SceneManagement::SceneManager::UpdateScene(float deltaTime) {
	if (m_currentScene == nullptr) return;
	m_currentScene->Update(deltaTime);
}


void SceneManagement::SceneManager::GenerateOutput(Core::ShaderLoaderOpenGL& shader) {
	m_currentScene->GenerateOutput(shader);
}


bool SceneManagement::SceneManager::LoadScene(const std::string& sceneName) {
	if (m_createSceneInstancesFunc == nullptr) {
		return false;
	}
	auto nextScene = m_createSceneInstancesFunc(sceneName);

	if (nextScene == nullptr) {
		Debug::LogError(sceneName + "�V�[�������݂��܂���.");
		return false;
	}

	if (m_currentScene != nullptr) {
		m_currentScene->OnExit();
	}

	m_currentScene = nextScene;
	nextScene->OnEnter();
	return true;
}


void SceneManagement::SceneManager::AddScene(const std::string& sceneName, Scene& scene) {
	//���ɒǉ����Ă�����return
	if (m_sceneMap.count(sceneName) != 0) return;
	m_sceneMap[sceneName] = &scene;
}


void SceneManagement::SceneManager::RemoveScene(const std::string& sceneName) {
	//�L�[�����݂��Ȃ����return
	auto it = m_sceneMap.find(sceneName);
	if (it == m_sceneMap.end()) return;
	m_sceneMap.erase(it);
}
