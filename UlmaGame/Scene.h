#pragma once
#include <vector>
#include "SceneList.h"

namespace Game {
	class Actor;
}

namespace System {
	namespace SceneManagement {
		class Scene {
		public:
			Scene(class ISceneManager& sceneManager, Game::ESceneType sceneType);
			virtual ~Scene();

			void OnEnter();
			void Update(float deltaTime);
			void OnExit();

			void AddActor(Game::Actor& actor);
			void RemoveActor(Game::Actor& actor);


		protected:
			class ISceneManager* m_sceneManager;
			Game::ESceneType m_sceneType;
			std::vector<Game::Actor*> m_sceneActors;
			std::vector<Game::Actor*> m_pendingActors;
			bool m_isUpdating;
		};
	}
}