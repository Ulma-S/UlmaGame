#pragma once
#include <string>
#include <functional>

namespace UlmaEngine {
	namespace Core {
		class ShaderLoaderOpenGL;
	}

	namespace SceneManagement {
		class Scene;
		
		class ISceneManager {
		public:
			virtual ~ISceneManager() = default;

			virtual void UpdateScene(float deltaTime) = 0;
			virtual void GenerateOutput(const Core::ShaderLoaderOpenGL& shader) = 0;
			virtual bool LoadScene(const std::string& sceneName) = 0;

			virtual void BindScenes(const std::function<Scene*(const std::string& sceneName)>& func) = 0;
		};
	}
}