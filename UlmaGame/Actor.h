#pragma once
#include <vector>

class Actor {
public:
	enum EActorState {
		Active,
		Inactive,
	};

	Actor(class IApplicationCore& appCore);
	virtual ~Actor();

	virtual void Initialize();
	void Update(float deltaTime);
	virtual void UpdateActor(float deltaTime);
	void UpdateComponents(float deltaTime);

	void AddComponent(class Component& component);
	void RemoveComponent(class Component& component);


protected:
	class IApplicationCore* m_appCore;
	EActorState m_state;
	std::vector<class Component*> m_components;
};