#pragma once
#include "IApplicationCore.h"

namespace System {
	namespace Core {
		class ApplicationCore : public IApplicationCore {
		public:
			ApplicationCore();
			ApplicationCore(class IWindow& window);
			~ApplicationCore();

			bool Initialize(class IWindow& window) override;
			void Update() override;
			void Finalize() override;


		private:
			class IWindow* m_window;
		};
	}
}