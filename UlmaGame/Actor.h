#pragma once
#include <vector>
#include <string>
#include "Vector.h"
#include "Transform.h"
#include "Debug.h"

namespace System {
	namespace SceneManagement {
		class Scene;
	}
}

namespace Game {
	namespace Core {
		class Actor {
		public:
			enum EActorState {
				Active,
				Inactive,
			};

			Actor(System::SceneManagement::Scene& scene);
			virtual ~Actor();

			virtual void Initialize();
			void Update(float deltaTime);
			void AddComponent(class Component& component);
			void RemoveComponent(class Component& component);

			inline System::SceneManagement::Scene& GetScene() const{ return *m_scene; }
			inline std::string& GetName() { return name; }
			inline Core::Transform& GetTransform() const { return *m_transform; }

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
			void UpdateComponents(float deltaTime);
			virtual void UpdateActor(float deltaTime);

			System::SceneManagement::Scene* m_scene;
			EActorState m_state;
			std::vector<class Component*> m_components;
			std::string name;

		private:
			Core::Transform* m_transform;
		};
	}
}