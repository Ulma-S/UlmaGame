#pragma once
#include <unordered_map>
#include "ISceneManager.h"
#include "Singleton.h"

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
			bool LoadScene(const std::string& _scenename) override;

			void AddScene(const std::string& sceneName, class Scene& scene) override;
			void RemoveScene(const std::string& sceneName) override;

		protected:
			friend Singleton<SceneManager>;
			SceneManager();

		private:
			std::unordered_map<std::string, class Scene*> m_sceneMap;
			class Scene* m_currentScene;
		};
	}
}