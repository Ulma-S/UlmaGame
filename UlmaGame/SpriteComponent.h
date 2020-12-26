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

			void Draw(System::Core::ShaderLoaderOpenGL& shader);

			inline int GetDrawOrder() { return m_drawOrder; }
			
		private:
			ESpriteType m_spriteType;
			int m_drawOrder;
		};
	}
}