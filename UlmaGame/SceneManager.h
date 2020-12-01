#pragma once
#include <unordered_map>
#include "ISceneManager.h"
#include "Singleton.h"
#include "SceneList.h"

namespace System {
	namespace SceneManagement {
		class SceneManager : public General::Singleton<SceneManager>, public ISceneManager {
		public:
			~SceneManager();
			void UpdateScene(float deltaTime) override;
			void LoadScene(Game::ESceneType sceneType) override;

			void AddScene(Game::ESceneType type, class Scene& scene) override;
			void RemoveScene(Game::ESceneType type) override;

		protected:
			friend General::Singleton<SceneManager>;
			SceneManager();

		private:
			std::unordered_map<Game::ESceneType, class Scene*> m_sceneMap;
			class Scene* m_currentScene;
		};
	}
}