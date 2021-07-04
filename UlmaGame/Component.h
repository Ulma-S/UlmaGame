#pragma once

namespace UlmaEngine {
	class Component {
	public:
		Component(class Actor& owner, int updateOrder = 100);
		virtual ~Component();

		virtual void Update(float deltaTime);

		inline int GetUpdateOrder() const { return m_updateOrder; }

		inline Actor& GetOwner() const { return *m_owner; }

		bool enable;

	protected:
		class Actor* m_owner;
		int m_updateOrder;
	};
}