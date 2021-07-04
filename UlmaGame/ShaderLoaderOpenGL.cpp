#include <string>
#include <fstream>
#include "ShaderLoaderOpenGL.h"
#include "Math.h"
#include "Debug.h"

using namespace UlmaEngine::Core;

ShaderLoaderOpenGL::ShaderLoaderOpenGL()
	: m_programId(0)
{}


ShaderLoaderOpenGL::~ShaderLoaderOpenGL(){}


bool ShaderLoaderOpenGL::LoadProgram(const char*vert, const char* frag) {
	//シェーダーソースの読み込み
	std::vector<GLchar> vsrc;
	const bool vstat= ReadShaderSource(vert, vsrc);
	std::vector<GLchar> fsrc;
	const bool fstat = ReadShaderSource(frag, fsrc);

	if (vstat && fstat) {
		CreateProgram(vsrc.data(), fsrc.data());
		return true;
	}
	else {
		return false;
	}
}


void ShaderLoaderOpenGL::Activate() const {
	glUseProgram(m_programId);
}


void ShaderLoaderOpenGL::Unload() const {
	glDeleteProgram(m_programId);
}


void ShaderLoaderOpenGL::SetAttributeVertices(const char* attribName, float vertices[]) const
{
	int attLocation = glGetAttribLocation(m_programId, attribName);	//in変数の場所を検索
	glEnableVertexAttribArray(attLocation);	//attribute変数を有効化する
	glVertexAttribPointer(attLocation, 3, GL_FLOAT, GL_FALSE, 0, vertices);	//OpenGLからシェーダーに値をセット
}


void ShaderLoaderOpenGL::SetUniformInt(const char* uniformName, GLint value) const {
	int loc = glGetUniformLocation(m_programId, uniformName);
	glUniform1i(loc, value);
}


void ShaderLoaderOpenGL::SetUniformFloat(const char* uniformName, GLfloat value) const {
	int loc = glGetUniformLocation(m_programId, uniformName);
	glUniform1f(loc, value);
}


void ShaderLoaderOpenGL::SetUniformVec2(const char* uniformName, const Math::Vector2& value) const {
	int loc = glGetUniformLocation(m_programId, uniformName);
	glUniform2f(loc, value.x, value.y);
}


void ShaderLoaderOpenGL::SetUniformMat4(const char* uniformName, const Math::Matrix4& value) const {
	int loc = glGetUniformLocation(m_programId, uniformName);
	auto ptr = reinterpret_cast<const float*>(&value.mat[0][0]);
	glUniformMatrix4fv(loc, 1, GL_TRUE, ptr);
}


GLuint ShaderLoaderOpenGL::CreateProgram(const char* vsrc, const char* fsrc) {
	//プログラムオブジェクトの作成
	m_programId = glCreateProgram();

	if (vsrc != nullptr) {
		//バーテックスシェーダのコンパイル
		GLuint vobj = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vobj, 1, &vsrc, nullptr);
		glCompileShader(vobj);
		glAttachShader(m_programId, vobj);
		glDeleteShader(vobj);
	}

	if (fsrc != nullptr) {
		//フラグメントシェーダのコンパイル
		GLuint fobj = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fobj, 1, &fsrc, nullptr);
		glCompileShader(fobj);
		glAttachShader(m_programId, fobj);
		glDeleteShader(fobj);
	}

	// リンク
	glLinkProgram(m_programId);

	return m_programId;
}


bool ShaderLoaderOpenGL::ReadShaderSource(const char* name, std::vector<GLchar>& buffer) {
	if (name == nullptr) return false;

	//シェーダーファイルを開く
	std::ifstream file(name, std::ios::binary);
	if(file.fail()){
		Debug::LogError(static_cast<std::string>(name) + "ファイルの読み込みに失敗しました。");
		return false;
	}
	file.seekg(0L, std::ios::end);
	GLsizei length = static_cast<GLsizei>(file.tellg());

	buffer.resize(length + 1);	//ファイルサイズ分のメモリ確保

	file.seekg(0L, std::ios::beg);
	file.read(buffer.data(), length);
	buffer[length] = '\0';

	if (file.fail()) {
		Debug::LogError(static_cast<std::string>(name) + "ファイルの読み込みに失敗しました。");
		file.close();
		return false;
	}
	file.close();
	return true;
}