#include <string>
#include <fstream>
#include "ShaderLoaderOpenGL.h"
#include "Math.h"
#include "Debug.h"

System::Core::ShaderLoaderOpenGL::ShaderLoaderOpenGL()
	: m_programId(0)
{}


System::Core::ShaderLoaderOpenGL::~ShaderLoaderOpenGL(){}


bool System::Core::ShaderLoaderOpenGL::LoadProgram(const char*vert, const char* frag) {
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


void System::Core::ShaderLoaderOpenGL::Activate() {
	glUseProgram(m_programId);
}


void System::Core::ShaderLoaderOpenGL::Unload() {
	glDeleteProgram(m_programId);
}


void System::Core::ShaderLoaderOpenGL::SetAttributeVerticies(const char* attribName, float verticies[]) {
	int attLocation = glGetAttribLocation(m_programId, attribName);	//in変数の場所を検索
	glEnableVertexAttribArray(attLocation);	//attribute変数を有効化する
	glVertexAttribPointer(attLocation, 3, GL_FLOAT, GL_FALSE, 0, verticies);	//OpenGLからシェーダーに値をセット
}


void System::Core::ShaderLoaderOpenGL::SetUniformInt(const char* uniformName, GLint value) {
	int loc = glGetUniformLocation(m_programId, uniformName);
	glUniform1i(loc, value);
}


void System::Core::ShaderLoaderOpenGL::SetUniformFloat(const char* uniformName, GLfloat value) {
	int loc = glGetUniformLocation(m_programId, uniformName);
	glUniform1f(loc, value);
}


void System::Core::ShaderLoaderOpenGL::SetUniformVec2(const char* uniformName, const Math::Vector2& value) {
	int loc = glGetUniformLocation(m_programId, uniformName);
	glUniform2f(loc, value.x, value.y);
}


void System::Core::ShaderLoaderOpenGL::SetUniformMat4(const char* uniformName, const Math::Matrix4& value) {
	int loc = glGetUniformLocation(m_programId, uniformName);
	auto ptr = reinterpret_cast<const float*>(&value.mat[0][0]);
	glUniformMatrix4fv(loc, 1, GL_TRUE, ptr);
}


GLuint System::Core::ShaderLoaderOpenGL::CreateProgram(const char* vsrc, const char* fsrc) {
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


bool System::Core::ShaderLoaderOpenGL::ReadShaderSource(const char* name, std::vector<GLchar>& buffer) {
	if (name == nullptr) return false;

	//シェーダーファイルを開く
	std::ifstream file(name, std::ios::binary);
	if(file.fail()){
		System::Debug::LogError((std::string)name + "ファイルの読み込みに失敗しました。");
		return false;
	}
	file.seekg(0L, std::ios::end);
	GLsizei length = static_cast<GLsizei>(file.tellg());

	buffer.resize(length + 1);	//ファイルサイズ分のメモリ確保

	file.seekg(0L, std::ios::beg);
	file.read(buffer.data(), length);
	buffer[length] = '\0';

	if (file.fail()) {
		System::Debug::LogError((std::string)name + "ファイルの読み込みに失敗しました。");
		file.close();
		return false;
	}
	file.close();
	return true;
}