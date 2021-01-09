#pragma once
#include <vector>
#include <string>
#include "Vector.h"
#include "Transform.h"

namespace UlmaEngine {
	namespace SceneManagement {
		class Scene;
	}
}

namespace UlmaEngine {
	class Actor {
	public:
		enum EActorState {
			Active,
			Inactive,
		};

		Actor(UlmaEngine::SceneManagement::Scene& scene);
		virtual ~Actor();

		virtual void Initialize();
		void Update(float deltaTime);
		void AddComponent(class Component& component);
		void RemoveComponent(class Component& component);

		inline UlmaEngine::SceneManagement::Scene& GetScene() const { return *m_scene; }
		inline std::string& GetName() { return name; }
		inline UlmaEngine::Transform& GetTransform() const { return *m_transform; }

		template<class T>
		inline T* GetComponent() const {
			auto it = m_components.begin();
			for (; it != m_components.end(); ++it) {
				T* t = dynamic_cast<T*>(*it);
				if (t != nullptr) {
					return t;
				}
			}
			return nullptr;
		}


	protected:
		virtual void UpdateActor(float deltaTime);

		UlmaEngine::SceneManagement::Scene* m_scene;
		EActorState m_state;
		std::vector<class Component*> m_components;
		std::string name;

	private:
		void UpdateComponents(float deltaTime);
		UlmaEngine::Transform* m_transform;
	};
}