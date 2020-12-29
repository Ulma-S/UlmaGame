#pragma once
#include "IApplicationCore.h"

namespace System {
	namespace Core {
		class ShaderLoaderOpenGL;

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
			float m_frameTime;

			ShaderLoaderOpenGL* m_unlitShader;
			ShaderLoaderOpenGL* m_spriteShader;
		};
	}
}