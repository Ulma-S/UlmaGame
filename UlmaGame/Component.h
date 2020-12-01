#pragma once

namespace Game {
	class Component {
	public:
		Component(class Actor& owner, int updateOrder);
		virtual ~Component();

		void Update(float deltaTime);

		inline int GetUpdateOrder() const { return m_updateOrder; }

	protected:
		class Actor* m_owner;
		int m_updateOrder;
	};
}