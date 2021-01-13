#pragma once
#include <vector>
#include "SceneList.h"

namespace UlmaEngine {
	namespace Core {
		class ShaderLoaderOpenGL;
	}
	class Actor;
	class SpriteComponent;
}

namespace UlmaEngine {
	namespace SceneManagement {
		class Scene {
		public:
			Scene(class ISceneManager& sceneManager, ESceneType sceneType);
			virtual ~Scene();

			void OnEnter();
			void Update(float deltaTime);
			void GenerateOutput(UlmaEngine::Core::ShaderLoaderOpenGL& shader);
			void OnExit();
			
			void AddActor(Actor& actor);
			void RemoveActor(Actor& actor);

			void AddSprite(SpriteComponent& sprite);
			void RemoveSprite(SpriteComponent& sprite);

			template<class T>
			void Instantiate(T t);

			inline std::vector<Actor*>& GetActors() { return m_sceneActors; }

		protected:
			class ISceneManager* m_sceneManager;
			ESceneType m_sceneType;
			std::vector<Actor*> m_sceneActors;
			std::vector<Actor*> m_pendingActors;
			bool m_isUpdating;

			std::vector<SpriteComponent*> m_sprites;

		private:
			void DetectCollision();
		};
	}
}