#pragma once
#include <unordered_map>
#include <typeindex>
#include <any>

namespace UlmaEngine {
	class ServiceLocator {
	public:
		/// <summary>
		/// �C���X�^���X��o�^���郁�\�b�h.
		/// </summary>
		template<class T>
		inline static void Register(T* instance) {
			if(ExistType<T>()) {
				return;
			}
			s_registeredInstances[typeid(T)] = instance;
		}

		/// <summary>
		/// �C���X�^���X�̎Q�Ƃ��������郁�\�b�h.
		/// </summary>
		template<class T>
		inline static T* Resolve() {
			if(ExistType<T>()) {
				auto out = std::any_cast<T*>(s_registeredInstances[typeid(T)]);
				return out;
			}
			return nullptr;
		}

	private:
		/// <summary>
		/// �Ώۂ̌^�����ɑ��݂��Ă��邩�������郁�\�b�h.
		/// </summary>
		template<class T>
		inline static bool ExistType() {
			if(s_registeredInstances.find(typeid(T)) == s_registeredInstances.end()) {
				return false;
			}

			return true;
		}

		static std::unordered_map<std::type_index, std::any> s_registeredInstances;
	};
}

