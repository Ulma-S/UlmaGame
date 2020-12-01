#pragma once
#include <vector>
#include "SceneList.h"

namespace Game {
	class Actor;
}

namespace System {
	namespace SceneManagement {
		class SceneBase {
		public:
			SceneBase(class SceneManager& sceneManager, Game::ESceneType sceneType);
			virtual ~SceneBase() = default;

			virtual void OnEnter() = 0;
			virtual void Update(float deltaTime) = 0;
			virtual void OnExit() = 0;

			void AddActor(Game::Actor& actor);
			void RemoveActor(Game::Actor& actor);


		protected:
			class SceneManager* m_sceneManager;
			Game::ESceneType m_sceneType;
			std::vector<Game::Actor*> m_sceneActors;
		};
	}
}