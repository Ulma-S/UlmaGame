#pragma once
#include <unordered_map>
#include "Singleton.h"
#include "SceneList.h"

namespace System {
	namespace SceneManagement {
		class SceneManager : public General::Singleton<SceneManager> {
		public:
			void UpdateScene();
			void ChangeScene();

			void AddScene(ESceneType type, class SceneBase& scene);
			void RemoveScene(ESceneType type);

		private:
			std::unordered_map<ESceneType, class SceneBase*> m_sceneMap;
		};
	}
}