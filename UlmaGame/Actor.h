#pragma once
#include <vector>
#include "Vector.h"

namespace System {
	namespace SceneManagement {
		class Scene;
	}
}

namespace Game {
	class Actor {
	public:
		enum EActorState {
			Active,
			Inactive,
		};

		Actor();
		Actor(System::SceneManagement::Scene& scene);
		virtual ~Actor();

		virtual void Initialize();
		void Update(float deltaTime);
		void AddComponent(class Component& component);
		void RemoveComponent(class Component& component);


	protected:
		void UpdateComponents(float deltaTime);
		virtual void UpdateActor(float deltaTime);

		System::SceneManagement::Scene* m_scene;
		EActorState m_state;
		std::vector<class Component*> m_components;
		Math::Vector2 m_position;
		Math::Vector2 m_scale;
		float m_rotation;
	};
}