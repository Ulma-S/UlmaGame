#pragma once
#include <string>
#include "Component.h"
#include "SpriteType.h"

namespace UlmaEngine {
	namespace Core {
		class ShaderLoaderOpenGL;
		class Texture;
	}
}

namespace UlmaEngine {
		class SpriteComponent : public Component{
		public:
			SpriteComponent(class Actor& owner, int drawOrder = 100);
			SpriteComponent(class Actor& owner, ESpriteType type, int drawOrder = 100);
			SpriteComponent(class Actor& owner, const char* assetName, ESpriteType type, int drawOrder = 100);
			~SpriteComponent();

			virtual void Draw(const Core::ShaderLoaderOpenGL& shader) const;

			inline int GetDrawOrder() const { return m_drawOrder; }
			
		private:
			ESpriteType m_spriteType;
			int m_drawOrder;
			std::string m_assetName;
		};
}