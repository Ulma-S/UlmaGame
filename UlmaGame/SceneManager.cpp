#include "SceneManager.h"
#include "Scene.h"

using namespace UlmaEngine;

SceneManagement::SceneManager::SceneManager() : m_currentScene(nullptr) {}


SceneManagement::SceneManager::~SceneManager() {
	std::unordered_map<std::string, Scene*>().swap(m_sceneMap);
}


void SceneManagement::SceneManager::UpdateScene(float _deltaTime){
	if (m_currentScene == nullptr) return;
	m_currentScene->Update(_deltaTime);
}


void SceneManagement::SceneManager::GenerateOutput(Core::ShaderLoaderOpenGL& shader) {
	m_currentScene->GenerateOutput(shader);
}


void SceneManagement::SceneManager::LoadScene(const std::string& _sceneName) {
	//�V�[�������݂��Ȃ����return
	auto it = m_sceneMap.find(_sceneName);
	if (it == m_sceneMap.end()) return;

	//�V�[���̏I������
	if (m_currentScene != nullptr) {
		m_currentScene->OnExit();
	}

	//�V�[���̓ǂݍ��ݎ��̏���
	m_currentScene = it->second;
	m_currentScene->OnEnter();
}


void SceneManagement::SceneManager::AddScene(const std::string& _sceneName, Scene& _scene) {
	//���ɒǉ����Ă�����return
	if (m_sceneMap.count(_sceneName) != 0) return;
	m_sceneMap[_sceneName] = &_scene;
}


void SceneManagement::SceneManager::RemoveScene(const std::string& _sceneName) {
	//�L�[�����݂��Ȃ����return
	auto it = m_sceneMap.find(_sceneName);
	if (it == m_sceneMap.end()) return;
	m_sceneMap.erase(it);
}
