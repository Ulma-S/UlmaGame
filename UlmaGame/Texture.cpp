#include <string>
#include "Texture.h"
#include "FileLoader.h"
#include "Debug.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace UlmaEngine::Core;

Texture::Texture()
	: m_texId(0)
	, m_texWidth(600)
	, m_texHeight(600)
	, m_texBuffer(nullptr)
	, m_isActive(false)
{
	CreateTexture();
}


Texture::Texture(const char* fileName)
	: m_texId(0)
	, m_texWidth(0)
	, m_texHeight(0)
	, m_texBuffer(nullptr)
	, m_isActive(false)
{
	CreateTexture(fileName);
}


Texture::~Texture() {
	if (m_isActive) {
		delete[] m_texBuffer;
	}
}


bool Texture::CreateTexture() {
	int bpp = 0;
	m_texBuffer = stbi_load("Resource/brown.png", &m_texWidth, &m_texHeight, nullptr, STBI_rgb_alpha);

	glGenTextures(1, &m_texId);

	if (m_texId <= 0) {
		Debug::LogError("テクスチャのロードに失敗しました.");
		return false;
	}

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glBindTexture(GL_TEXTURE_2D, m_texId);

	glTexImage2D(
		GL_TEXTURE_2D,
		0,
		GL_RGBA,
		m_texWidth,
		m_texHeight,
		0,
		GL_RGBA,
		GL_UNSIGNED_BYTE,
		m_texBuffer
	);

	//各種設定
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	delete[] m_texBuffer;
	
	m_isActive = true;
	return true;
}


bool Texture::CreateTexture(const char* fileName) {
	std::string in = "Resource/" + std::string(fileName);
	m_texBuffer = stbi_load(in.c_str(), &m_texWidth, &m_texHeight, nullptr, STBI_rgb_alpha);
	
	glGenTextures(1, &m_texId);

	if (m_texId <= 0) {
		Debug::LogError("テクスチャのロードに失敗しました.");
		return false;
	}

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glBindTexture(GL_TEXTURE_2D, m_texId);

	glTexImage2D(
		GL_TEXTURE_2D,
		0,
		GL_RGBA,
		m_texWidth,
		m_texHeight,
		0,
		GL_RGBA,
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
		glBindTexture(GL_TEXTURE_2D, 0);
		m_isActive = false;
	}
}
