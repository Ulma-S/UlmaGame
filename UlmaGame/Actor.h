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

		Actor(UlmaEngine::SceneManagement::Scene& _scene);
		virtual ~Actor();

		virtual void Initialize();
		void Update(float _deltaTime);
		void AddComponent(class Component& _component);
		void RemoveComponent(class Component& _component);

		inline UlmaEngine::SceneManagement::Scene& GetScene() const { return *m_scene; }
		inline const std::string& GetName() { return name; }
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

		int layer;
		EActorState state;

	protected:
		virtual void UpdateActor(float _deltaTime);

		UlmaEngine::SceneManagement::Scene* m_scene;
		std::vector<class Component*> m_components;
		std::string name;

	private:
		void UpdateComponents(float _deltaTime);
		UlmaEngine::Transform* m_transform;
	};
}