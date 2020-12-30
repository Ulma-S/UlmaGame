#pragma once
#include <string>
#include <unordered_map>
#include "Singleton.h"
#include "Debug.h"

namespace System {
	namespace Core {
		class Texture;

		class TextureProvider : public General::Singleton<TextureProvider> {
		public:
			~TextureProvider();

			void UseTexture(const std::string& assetName);
			void AddTexture(const std::string& assetName, Texture& texture);

			inline Texture* GetTexture(const std::string& assetName) {
				auto it = m_texMap.begin();
				if (it == m_texMap.end()) {
					System::Debug::Log(assetName + "‚ªƒL[‚Éİ’è‚³‚ê‚Ä‚¢‚Ü‚¹‚ñB");
					return nullptr;
				}
				return m_texMap[assetName];
			}

		protected:
			friend General::Singleton<TextureProvider>;
			TextureProvider();
		
		private:
			std::unordered_map<std::string, Texture*> m_texMap;
		};
	}
}