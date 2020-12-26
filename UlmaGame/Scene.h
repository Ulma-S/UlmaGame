#pragma once
#include <vector>
#include "SceneList.h"

namespace System {
	namespace Core {
		class ShaderLoaderOpenGL;
	}
}

namespace Game {
	namespace Core {
		class Actor;
		class SpriteComponent;
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
			void GenerateOutput(System::Core::ShaderLoaderOpenGL& shader);
			void OnExit();
			
			void AddActor(Game::Core::Actor& actor);
			void RemoveActor(Game::Core::Actor& actor);

			void AddSprite(Game::Core::SpriteComponent& sprite);


		protected:
			class ISceneManager* m_sceneManager;
			Game::ESceneType m_sceneType;
			std::vector<Game::Core::Actor*> m_sceneActors;
			std::vector<Game::Core::Actor*> m_pendingActors;
			bool m_isUpdating;

			std::vector<Game::Core::SpriteComponent*> m_sprites;
		};
	}
}