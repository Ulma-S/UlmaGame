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
	//Actorクラス.
	class Actor {
	public:
		//Actorの状態列挙.
		enum EActorState {
			Active,
			Inactive,
		};

		Actor(UlmaEngine::SceneManagement::Scene& _scene);
		virtual ~Actor();

		//Actorを初期化するメソッド.
		virtual void Initialize();

		//Actor全体を更新するメソッド.
		void Update(float _deltaTime);

		//Componentを追加するメソッド.
		void AddComponent(class Component& _component);
		
		//Componentを削除するメソッド.
		void RemoveComponent(class Component& _component);

		inline UlmaEngine::SceneManagement::Scene& GetScene() const { return *m_scene; }
		inline const std::string& GetName() { return name; }
		inline UlmaEngine::Transform& GetTransform() const { return *m_transform; }

		//アタッチされた中からジェネリクス型に対応するComponentの参照を検索し、返すメソッド.
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

		//Actorの状態.
		EActorState state;

	protected:
		//Actor自身を更新するメソッド(オーバライド可能).
		virtual void UpdateActor(float _deltaTime);

		UlmaEngine::SceneManagement::Scene* m_scene;
		std::vector<class Component*> m_components;
		std::string name;

	private:
		//ActorにアタッチされたComponentを更新するメソッド.
		void UpdateComponents(float _deltaTime);
		UlmaEngine::Transform* m_transform;
	};
}