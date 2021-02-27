#pragma once
#include <vector>
#include <string>

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
			Scene(class ISceneManager& sceneManager, const std::string& _sceneName);
			virtual ~Scene();

			void OnEnter();
			void Update(float _deltaTime);
			void GenerateOutput(UlmaEngine::Core::ShaderLoaderOpenGL& _shader);
			void OnExit();
			
			void AddActor(Actor& _actor);
			void RemoveActor(Actor& _actor);

			void AddSprite(SpriteComponent& _sprite);
			void RemoveSprite(SpriteComponent& _sprite);

			template<class T>
			void Instantiate(T _t);

			inline std::vector<Actor*>& GetActors() { return m_sceneActors; }

		protected:
			class ISceneManager* m_sceneManager;
			std::string m_sceneName;
			std::vector<Actor*> m_sceneActors;
			std::vector<Actor*> m_pendingActors;
			bool m_isUpdating;

			std::vector<SpriteComponent*> m_sprites;

		private:
			void DetectCollision();
		};
	}
}