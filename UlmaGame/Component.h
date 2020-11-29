#pragma once

class Component {
public:
	Component(class Actor& owner, int updateOrder);
	virtual ~Component();

	void Update(float deltaTime);

protected:
	class Actor* m_owner;
	int m_updateOrder;
};