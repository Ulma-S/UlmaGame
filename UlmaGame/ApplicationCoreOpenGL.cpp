#include "ApplicationCoreOpenGL.h"
#include "Actor.h"
#include "WindowOpenGL.h"

ApplicationCore::ApplicationCore(IWindow& window)
	: m_window(&window)
	, m_updatingActors(false)
{}


ApplicationCore::~ApplicationCore(){
}


bool ApplicationCore::Initialize() {
	//ウィンドウ作成
	bool success = m_window->CreateWindow();
	if (!success) {
		return false;
	}

	//Actorの初期化
	for (auto actor : m_actors) {
		actor->Initialize();
	}

	m_updatingActors = true;
	return true;
}


void ApplicationCore::Update() {
	while (m_window->CanLoop()) {
		m_updatingActors = true;
		for (auto actor : m_actors) {
			actor->Update(0.0f);
		}
		m_updatingActors = false;

		for (auto actor : m_pendingActors) {
			m_actors.emplace_back(actor);
		}
		m_pendingActors.clear();
	}
}


void ApplicationCore::Finalize() {
	m_window->Finalize();
}


void ApplicationCore::AddActor(Actor& actor) {
	if (m_updatingActors) {
		m_pendingActors.emplace_back(&actor);
	}
	else {
		m_actors.emplace_back(&actor);
	}
}


void ApplicationCore::RemoveActor(Actor& actor) {

}