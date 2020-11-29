#pragma once
#include <vector>
#include "ApplicationCoreBase.h"

class ApplicationCore : public IApplicationCore {
public:
	ApplicationCore(class IWindow& window);
	~ApplicationCore();

	bool Initialize() override;
	void Update() override;
	void Finalize() override;

	void AddActor(class Actor& actor) override;
	void RemoveActor(class Actor& actor) override;

private:
	class IWindow* m_window;

	std::vector<class Actor*> m_actors;
	//’Ç‰Á•Û—¯’†‚ÌActor
	std::vector<class Actor*> m_pendingActors;

	bool m_updatingActors;
};