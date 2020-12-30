#include "Texture.h"
#include "FileLoader.h"
#include "Debug.h"
#include <fstream>

using namespace System::Core;

Texture::Texture()
	: m_texId(0)
	, m_texWidth(256)
	, m_texHeight(256)
	, m_texBuffer(nullptr)
	, m_isActive(false)
{}


Texture::Texture(int width, int height) 
	: m_texId(0)
	, m_texWidth(width)
	, m_texHeight(height)
	, m_texBuffer(nullptr)
	, m_isActive(false)
{}


Texture::~Texture() {
	if (m_isActive) {
		delete[] m_texBuffer;
	}
}


bool Texture::CreateTexture() {
	FileLoader::GetInstance().LoadFile("Resource/cat.raw", &m_texBuffer);

	glGenTextures(1, &m_texId);

	if (m_texId <= 0) {
		System::Debug::LogError("テクスチャのロードに失敗しました。");
		return false;
	}

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glBindTexture(GL_TEXTURE_2D, m_texId);

	glTexImage2D(
		GL_TEXTURE_2D,
		0,
		GL_RGB,
		m_texWidth,
		m_texHeight,
		0,
		GL_RGB,
		GL_UNSIGNED_BYTE,
		m_texBuffer
	);

	//各種設定
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	
	m_isActive = true;
	return true;
}


void Texture::Activate() {
	glBindTexture(GL_TEXTURE_2D, m_texId);
}


void Texture::Inactivate() {
	if (m_isActive) {
		delete[] m_texBuffer;
		m_isActive = false;
	 }
}
