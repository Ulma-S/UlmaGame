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
		Debug::LogError(assetName + "���L�[�ɐݒ肳��Ă��܂���.");
		return;
	}

	if (m_texMap[assetName] == nullptr) {
		Debug::LogError(assetName + "�����݂��܂���.");
		return;
	}
	m_texMap[assetName]->Activate();
}


void TextureProvider::RegisterTexture(const std::string& assetName, Texture& texture) {
	//�L�[�����݂��Ă�����return
	auto it = m_texMap.find(assetName);
	if (it != m_texMap.end()) {
		Debug::LogError(assetName + "�͊��ɑ��݂��Ă��܂�.");
		return;
	}
	m_texMap[assetName] = &texture;
}
