#pragma once
#include "ApplicationCoreBase.h"

namespace System {
	namespace SceneManagement {
		class SceneManager;
	}
}

namespace System {

	namespace Core {
		class ApplicationCore : public IApplicationCore {
		public:
			ApplicationCore(class IWindow& window, System::SceneManagement::SceneManager& sceneManager);
			~ApplicationCore();

			bool Initialize() override;
			void Update() override;
			void Finalize() override;


		private:
			class IWindow* m_window;
			System::SceneManagement::SceneManager* m_sceneManager;
		};
	}
}