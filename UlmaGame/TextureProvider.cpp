#include "TextureProvider.h"
#include "Texture.h"

using namespace System::Core;

TextureProvider::TextureProvider() {

}


TextureProvider::~TextureProvider() {
	std::unordered_map<std::string, Texture*>().swap(m_texMap);
}


void TextureProvider::UseTexture(const std::string& assetName) {
	auto it = m_texMap.find(assetName);
	if (it == m_texMap.end()) {
		System::Debug::LogError(assetName + "���L�[�ɐݒ肳��Ă��܂���B");
		return;
	}

	if (m_texMap[assetName] == nullptr) {
		System::Debug::LogError(assetName + "��null�ł��B");
		return;
	}
	m_texMap[assetName]->Activate();
}


void TextureProvider::AddTexture(const std::string& assetName, Texture& texture) {
	//�L�[�����݂��Ă�����return
	auto it = m_texMap.find(assetName);
	if (it != m_texMap.end()) {
		System::Debug::LogError(assetName + "�͊��ɑ��݂��Ă��܂��B");
		return;
	}
	m_texMap[assetName] = &texture;
}
