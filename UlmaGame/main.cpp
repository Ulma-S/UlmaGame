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
	//�o�[�e�b�N�X�V�F�[�_�̃R���p�C��
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

	//�t���O�����g�V�F�[�_�̃R���p�C��
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

	//�v���O�����I�u�W�F�N�g�̍쐬
	GLuint programId = glCreateProgram();
	glAttachShader(programId, vShaderId);
	glAttachShader(programId, fShaderId);

	// �����N
	glLinkProgram(programId);

	glUseProgram(programId);

	return programId;
}

GLuint loadTexture(string filename) {
	// �e�N�X�`��ID�̐���
	GLuint texID;
	glGenTextures(1, &texID);

	// �t�@�C���̓ǂݍ���
	std::ifstream fstr(filename, std::ios::binary);
	const size_t fileSize = static_cast<size_t>(fstr.seekg(0, fstr.end).tellg());
	fstr.seekg(0, fstr.beg);
	char* textureBuffer = new char[fileSize];
	fstr.read(textureBuffer, fileSize);

	// �e�N�X�`����GPU�ɓ]��
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glBindTexture(GL_TEXTURE_2D, texID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, textureBuffer);

	// �e�N�X�`���̐ݒ�
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// �e�N�X�`���̃A���o�C���h
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

	// ���j�^�Ƃ̓���
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK) {
		return -1;
	}

	GLuint programId = crateShader();

	GLuint texID = loadTexture("Resource/cat.raw");

	// �Q�[�����[�v
	while (!glfwWindowShouldClose(window)) {

		// ��ʂ̏�����
		glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearDepth(1.0);

		// ���_�f�[�^
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

		// ���Ԗڂ�attribute�ϐ���
		int positionLocation = glGetAttribLocation(programId, "position");
		int uvLocation = glGetAttribLocation(programId, "uv");
		int textureLocation = glGetUniformLocation(programId, "texture");

		// attribute������L���ɂ���
		glEnableVertexAttribArray(positionLocation);
		glEnableVertexAttribArray(uvLocation);

		// uniform������ݒ肷��
		glUniform1i(textureLocation, 0);

		// attribute������o�^
		glVertexAttribPointer(positionLocation, 2, GL_FLOAT, false, 0, vertex_position);
		glVertexAttribPointer(uvLocation, 2, GL_FLOAT, false, 0, vertex_uv);


		// ���f���̕`��
		glBindTexture(GL_TEXTURE_2D, texID);
		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

		// �o�b�t�@�̓���ւ�
		glfwSwapBuffers(window);

		// �C�x���g�҂�
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}