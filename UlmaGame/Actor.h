#pragma once
#include <vector>
#include <string>
#include "Transform.h"

namespace UlmaEngine {
	namespace SceneManagement {
		class Scene;
	}
}

namespace UlmaEngine {
	//Actor�N���X.
	class Actor {
	public:
		//Actor�̏�ԗ�.
		enum EActorState {
			Active,
			Inactive,
		};

		Actor(SceneManagement::Scene& _scene);
		virtual ~Actor();

		//Actor�����������郁�\�b�h.
		virtual void Initialize();

		//Actor�S�̂��X�V���郁�\�b�h.
		void Update(float deltaTime);

		//Component��ǉ����郁�\�b�h.
		void AddComponent(class Component& _component);
		
		//Component���폜���郁�\�b�h.
		void RemoveComponent(class Component& component);

		inline SceneManagement::Scene& GetScene() const { return *m_scene; }
		inline const std::string& GetName() const { return name; }
		inline Transform& GetTransform() const { return *m_transform; }

		//�A�^�b�`���ꂽ������W�F�l���N�X�^�ɑΉ�����Component�̎Q�Ƃ��������A�Ԃ����\�b�h.
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

		//�W�F�l���N�X�^�ɑΉ�����Component�����݂��邩�m�F���郁�\�b�h.
		//���݂��Ă����true, ���Ȃ����false.
		//���݂��Ă���ꍇ�A������out�ɂ͂��̎Q�Ƃ�����.
		template<class T>
		inline bool TryGetComponent(T* out) const {
			auto it = m_components.begin();
			for(; it != m_components.end(); ++it) {
				T* t = dynamic_cast<T*>(*it);
				if(t != nullptr) {
					out = t;
					return true;
				}
			}
			return false;
		}
		

		int layer;

		//Actor�̏��.
		EActorState state;

	protected:
		//Actor���g���X�V���郁�\�b�h(�I�[�o���C�h�\).
		virtual void UpdateActor(float deltaTime);

		SceneManagement::Scene* m_scene;
		std::vector<class Component*> m_components;
		std::string name;

	private:
		//Actor�ɃA�^�b�`���ꂽComponent���X�V���郁�\�b�h.
		void UpdateComponents(float deltaTime);
		Transform* m_transform;
	};
}