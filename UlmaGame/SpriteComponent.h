#pragma once
#include "Component.h"
#include "SpriteType.h"

namespace System {
	namespace Core {
		class ShaderLoaderOpenGL;
	}
}

namespace Game {
	namespace Core {
		class SpriteComponent : public Component{
		public:
			SpriteComponent(class Actor& owner, int drawOrder = 100);
			~SpriteComponent();

			void Update(float deltaTime) override;
			
		private:
			void Draw(System::Core::ShaderLoaderOpenGL& shaderLoader);

			ESpriteType m_spriteType;
		};
	}
}