#include <string>
#include <fstream>
#include "ShaderLoaderOpenGL.h"
#include "Vector.h"
#include "Debug.h"

System::Core::ShaderLoaderOpenGL::ShaderLoaderOpenGL(){}


System::Core::ShaderLoaderOpenGL::~ShaderLoaderOpenGL(){}


GLuint System::Core::ShaderLoaderOpenGL::LoadProgram(const char*vert, const char* frag) {
	//シェーダーソースの読み込み
	std::vector<GLchar> vsrc;
	const bool vstat= ReadShaderSource(vert, vsrc);
	std::vector<GLchar> fsrc;
	const bool fstat = ReadShaderSource(frag, fsrc);

	if (vstat && fstat) {
		return CreateProgram(vsrc.data(), fsrc.data());
	}
	else {
		return 0;
	}
}


void System::Core::ShaderLoaderOpenGL::Activate() {
	glUseProgram(m_programId);
}


void System::Core::ShaderLoaderOpenGL::Unload() {
	glDeleteProgram(m_programId);
}


void System::Core::ShaderLoaderOpenGL::SetUniformFloat(const char* uniformName, GLfloat value) {
	int loc = glGetUniformLocation(m_programId, uniformName);
	glUniform1f(loc, value);
}


void System::Core::ShaderLoaderOpenGL::SetUniformVec2(const char* uniformName, Math::Vector2& value) {
	int loc = glGetUniformLocation(m_programId, uniformName);
	glUniform2f(loc, value.x, value.y);
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