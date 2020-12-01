#include "SceneManager.h"
#include "SceneBase.h"


System::SceneManagement::SceneManager::SceneManager() : m_currentScene(nullptr) {}

void System::SceneManagement::SceneManager::UpdateScene(float deltaTime){
	if (m_currentScene == nullptr) return;
	m_currentScene->Update(deltaTime);
}


void System::SceneManagement::SceneManager::LoadScene(Game::ESceneType sceneType){
	//�V�[�������݂��Ȃ����return
	auto it = m_sceneMap.find(sceneType);
	if (it == m_sceneMap.end()) return;

	//�V�[���̏I������
	m_currentScene->OnExit();

	//�V�[���̓ǂݍ��ݎ��̏���
	m_currentScene = it->second;
	m_currentScene->OnEnter();
}


void System::SceneManagement::SceneManager::AddScene(Game::ESceneType sceneType, SceneBase& scene) {
	//���ɒǉ����Ă�����return
	if (m_sceneMap.count(sceneType) != 0) return;
	m_sceneMap[sceneType] = &scene;
}


void System::SceneManagement::SceneManager::RemoveScene(Game::ESceneType sceneType) {
	//�L�[�����݂��Ȃ����return
	auto it = m_sceneMap.find(sceneType);
	if (it == m_sceneMap.end()) return;
	m_sceneMap.erase(it);
}
