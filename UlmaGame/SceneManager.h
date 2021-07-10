#pragma once
#include <functional>
#include "ISceneManager.h"
#include "Singleton.h"

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
			void GenerateOutput(const Core::ShaderLoaderOpenGL& shader) override;
			bool LoadScene(const std::string& sceneName) override;

			//シーンのインスタンスを生成する関数を登録するメソッド.
			void BindScenes(const std::function<Scene*(const std::string&)>& func) override {
				m_createSceneInstancesFunc = func;
			}
		
		protected:
			friend Singleton<SceneManager>;
			SceneManager();

		private:
			bool ExecuteLoadScene(const std::string& sceneName);
			
			std::function<Scene*(const std::string&)> m_createSceneInstancesFunc;
			class Scene* m_currentScene;
			bool m_isUpdating;
			std::string m_nextSceneName;
			bool m_isRequestedLoadScene;
		};
	}
}