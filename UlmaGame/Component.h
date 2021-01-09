#pragma once

namespace UlmaEngine {
	class Component {
	public:
		Component(class Actor& owner, int updateOrder = 100);
		virtual ~Component();

		virtual void Update(float deltaTime);

		inline int GetUpdateOrder() const { return m_updateOrder; }

	protected:
		class Actor* m_owner;
		int m_updateOrder;
	};
}