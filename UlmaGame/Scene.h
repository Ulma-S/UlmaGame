#pragma once
#include <vector>
#include "SceneList.h"

namespace Game {
	namespace Core {
		class Actor;
	}
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
			
			void AddActor(Game::Core::Actor& actor);
			void RemoveActor(Game::Core::Actor& actor);


		protected:
			class ISceneManager* m_sceneManager;
			Game::ESceneType m_sceneType;
			std::vector<Game::Core::Actor*> m_sceneActors;
			std::vector<Game::Core::Actor*> m_pendingActors;
			bool m_isUpdating;
		};
	}
}