#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const int g_width = 640;
const int g_height = 480;

GLuint crateShader() {
	//バーテックスシェーダのコンパイル
	GLuint vShaderId = glCreateShader(GL_VERTEX_SHADER);
	string vertexShader = R"#(
    attribute vec3 position;
    attribute vec2 uv;
    varying vec2 vuv;
    void main(void){
        gl_Position = vec4(position, 1.0);
        vuv = uv;
    }
    )#";
	const char* vs = vertexShader.c_str();
	glShaderSource(vShaderId, 1, &vs, NULL);
	glCompileShader(vShaderId);

	//フラグメントシェーダのコンパイル
	GLuint fShaderId = glCreateShader(GL_FRAGMENT_SHADER);
	string fragmentShader = R"#(
    varying vec2 vuv;
    uniform sampler2D texture;
    void main(void){
        gl_FragColor = texture2D(texture, vuv);
    }
    )#";
	const char* fs = fragmentShader.c_str();
	glShaderSource(fShaderId, 1, &fs, NULL);
	glCompileShader(fShaderId);

	//プログラムオブジェクトの作成
	GLuint programId = glCreateProgram();
	glAttachShader(programId, vShaderId);
	glAttachShader(programId, fShaderId);

	// リンク
	glLinkProgram(programId);

	glUseProgram(programId);

	return programId;
}

GLuint loadTexture(string filename) {
	// テクスチャIDの生成
	GLuint texID;
	glGenTextures(1, &texID);

	// ファイルの読み込み
	std::ifstream fstr(filename, std::ios::binary);
	const size_t fileSize = static_cast<size_t>(fstr.seekg(0, fstr.end).tellg());
	fstr.seekg(0, fstr.beg);
	char* textureBuffer = new char[fileSize];
	fstr.read(textureBuffer, fileSize);

	// テクスチャをGPUに転送
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glBindTexture(GL_TEXTURE_2D, texID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, textureBuffer);

	// テクスチャの設定
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// テクスチャのアンバインド
	delete[] textureBuffer;
	glBindTexture(GL_TEXTURE_2D, 0);

	return texID;
}

int main() {
	glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	if (!glfwInit()) {
		return -1;
	}

	GLFWwindow* window = glfwCreateWindow(g_width, g_height, "Simple", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	// モニタとの同期
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK) {
		return -1;
	}

	GLuint programId = crateShader();

	GLuint texID = loadTexture("Resource/cat.raw");

	// ゲームループ
	while (!glfwWindowShouldClose(window)) {

		// 画面の初期化
		glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearDepth(1.0);

		// 頂点データ
		float vertex_position[] = {
			0.5f, 0.5f,
			-0.5f, 0.5f,
			-0.5f, -0.5f,
			0.5f, -0.5f
		};

		const GLfloat vertex_uv[] = {
			1, 0,
			0, 0,
			0, 1,
			1, 1,
		};

		// 何番目のattribute変数か
		int positionLocation = glGetAttribLocation(programId, "position");
		int uvLocation = glGetAttribLocation(programId, "uv");
		int textureLocation = glGetUniformLocation(programId, "texture");

		// attribute属性を有効にする
		glEnableVertexAttribArray(positionLocation);
		glEnableVertexAttribArray(uvLocation);

		// uniform属性を設定する
		glUniform1i(textureLocation, 0);

		// attribute属性を登録
		glVertexAttribPointer(positionLocation, 2, GL_FLOAT, false, 0, vertex_position);
		glVertexAttribPointer(uvLocation, 2, GL_FLOAT, false, 0, vertex_uv);


		// モデルの描画
		glBindTexture(GL_TEXTURE_2D, texID);
		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

		// バッファの入れ替え
		glfwSwapBuffers(window);

		// イベント待ち
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}