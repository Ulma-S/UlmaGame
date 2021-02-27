#pragma once
#include <string>
#include <unordered_map>
#include "Singleton.h"
#include "Debug.h"

namespace UlmaEngine {
	namespace Core {
		class Texture;

		class TextureProvider : public Singleton<TextureProvider> {
		public:
			~TextureProvider();

			void UseTexture(const std::string& _assetName);
			void AddTexture(const std::string& _assetName, Texture& _texture);

			inline const Texture* GetTexture(const std::string& _assetName) {
				auto it = m_texMap.begin();
				if (it == m_texMap.end()) {
					Debug::Log(_assetName + "‚ªƒL[‚Éİ’è‚³‚ê‚Ä‚¢‚Ü‚¹‚ñB");
					return nullptr;
				}
				return m_texMap[_assetName];
			}

		protected:
			friend Singleton<TextureProvider>;
			TextureProvider();
		
		private:
			std::unordered_map<std::string, Texture*> m_texMap;
		};
	}
}