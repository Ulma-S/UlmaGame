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
			void UpdateScene(float _deltaTime) override;
			void GenerateOutput(UlmaEngine::Core::ShaderLoaderOpenGL& _shader);
			void LoadScene(const std::string& _scenename) override;

			void AddScene(const std::string& _sceneName, class Scene& scene) override;
			void RemoveScene(const std::string& _sceneName) override;

		protected:
			friend Singleton<SceneManager>;
			SceneManager();

		private:
			std::unordered_map<std::string, class Scene*> m_sceneMap;
			class Scene* m_currentScene;
		};
	}
}