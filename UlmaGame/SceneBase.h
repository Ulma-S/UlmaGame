#pragma once
#include <vector>
#include "SceneList.h"

namespace System {
	namespace SceneManagement {
		class SceneBase {
		public:
			SceneBase(class SceneManager& sceneManager, ESceneType sceneType);
			virtual ~SceneBase() = default;

			virtual void OnEnter() = 0;
			virtual void Update() = 0;
			virtual void OnExit() = 0;

			void AddActor(class Actor& actor);
			void RemoveActor(class Actor& actor);


		protected:
			class SceneManager* m_sceneManager;
			ESceneType m_sceneType;
			std::vector<class Actor*> m_sceneActors;
		};
	}
}