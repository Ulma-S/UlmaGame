#pragma once
#include <unordered_map>
#include <functional>
#include <typeindex>
#include "ISceneManager.h"
#include "Singleton.h"
#include "Debug.h"

namespace UlmaEngine {
	namespace Core {
		class ShaderLoaderOpenGL;
	}

	namespace SceneManagement {
		class Scene;
		
		class SceneManager : public Singleton<SceneManager>, public ISceneManager {
		public:
			~SceneManager() override;
			void UpdateScene(float deltaTime) override;
			void GenerateOutput(UlmaEngine::Core::ShaderLoaderOpenGL& shader) override;
			bool LoadScene(const std::string& sceneName) override;

			void AddScene(const std::string& sceneName, class Scene& scene) override;
			void RemoveScene(const std::string& sceneName) override;

			void BindScenes(const std::function<Scene*(const std::string&)>& func) override {
				m_createSceneInstancesFunc = func;
			}
		
		protected:
			friend Singleton<SceneManager>;
			SceneManager();

		private:
			std::unordered_map<std::string, class Scene*> m_sceneMap;
			std::function<Scene*(const std::string&)> m_createSceneInstancesFunc;
			class Scene* m_currentScene;
		};
	}
}