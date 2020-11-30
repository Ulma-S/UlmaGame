#pragma once
#include <vector>

namespace System {
	namespace SceneManagement {
		class SceneBase;
	}
}

namespace Game {
	class Actor {
	public:
		enum EActorState {
			Active,
			Inactive,
		};

		Actor(System::SceneManagement::SceneBase& scene);
		virtual ~Actor();

		virtual void Initialize();
		void Update(float deltaTime);
		virtual void UpdateActor(float deltaTime);
		void UpdateComponents(float deltaTime);

		void AddComponent(class Component& component);
		void RemoveComponent(class Component& component);


	protected:
		System::SceneManagement::SceneBase* m_scene;
		EActorState m_state;
		std::vector<class Component*> m_components;
	};
}