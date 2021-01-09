#pragma once
#include <unordered_map>
#include "ISceneManager.h"
#include "Singleton.h"
#include "SceneList.h"

namespace UlmaEngine {
	namespace Core {
		class ShaderLoaderOpenGL;
	}

	namespace SceneManagement {
		class SceneManager : public Singleton<SceneManager>, public ISceneManager {
		public:
			~SceneManager();
			void UpdateScene(float deltaTime) override;
			void GenerateOutput(UlmaEngine::Core::ShaderLoaderOpenGL& shader);
			void LoadScene(ESceneType sceneType) override;

			void AddScene(ESceneType type, class Scene& scene) override;
			void RemoveScene(ESceneType type) override;

		protected:
			friend Singleton<SceneManager>;
			SceneManager();

		private:
			std::unordered_map<ESceneType, class Scene*> m_sceneMap;
			class Scene* m_currentScene;
		};
	}
}