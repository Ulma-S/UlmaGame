#include "TextureProvider.h"
#include "Texture.h"

using namespace UlmaEngine::Core;

TextureProvider::TextureProvider() {

}


TextureProvider::~TextureProvider() {
	std::unordered_map<std::string, Texture*>().swap(m_texMap);
}


void TextureProvider::UseTexture(const std::string& assetName) {
	auto it = m_texMap.find(assetName);
	if (it == m_texMap.end()) {
		Debug::LogError(assetName + "がキーに設定されていません.");
		return;
	}

	if (m_texMap[assetName] == nullptr) {
		Debug::LogError(assetName + "が存在しません.");
		return;
	}
	m_texMap[assetName]->Activate();
}


void TextureProvider::RegisterTexture(const std::string& assetName, Texture& texture) {
	//キーが存在していたらreturn
	auto it = m_texMap.find(assetName);
	if (it != m_texMap.end()) {
		Debug::LogError(assetName + "は既に存在しています.");
		return;
	}
	m_texMap[assetName] = &texture;
}
