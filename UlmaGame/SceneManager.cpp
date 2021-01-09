#include "SceneManager.h"
#include "Scene.h"

using namespace UlmaEngine;

SceneManagement::SceneManager::SceneManager() : m_currentScene(nullptr) {}


SceneManagement::SceneManager::~SceneManager() {
	std::unordered_map<ESceneType, Scene*>().swap(m_sceneMap);
}


void SceneManagement::SceneManager::UpdateScene(float deltaTime){
	if (m_currentScene == nullptr) return;
	m_currentScene->Update(deltaTime);
}


void SceneManagement::SceneManager::GenerateOutput(Core::ShaderLoaderOpenGL& shader) {
	m_currentScene->GenerateOutput(shader);
}


void SceneManagement::SceneManager::LoadScene(ESceneType sceneType){
	//�V�[�������݂��Ȃ����return
	auto it = m_sceneMap.find(sceneType);
	if (it == m_sceneMap.end()) return;

	//�V�[���̏I������
	if (m_currentScene != nullptr) {
		m_currentScene->OnExit();
	}

	//�V�[���̓ǂݍ��ݎ��̏���
	m_currentScene = it->second;
	m_currentScene->OnEnter();
}


void SceneManagement::SceneManager::AddScene(ESceneType sceneType, Scene& scene) {
	//���ɒǉ����Ă�����return
	if (m_sceneMap.count(sceneType) != 0) return;
	m_sceneMap[sceneType] = &scene;
}


void SceneManagement::SceneManager::RemoveScene(ESceneType sceneType) {
	//�L�[�����݂��Ȃ����return
	auto it = m_sceneMap.find(sceneType);
	if (it == m_sceneMap.end()) return;
	m_sceneMap.erase(it);
}
