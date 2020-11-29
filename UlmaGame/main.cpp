#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <string>

const int g_width = 640;
const int g_height = 480;

GLuint crateShader() {
	//�o�[�e�b�N�X�V�F�[�_�̃R���p�C��
	GLuint vShaderId = glCreateShader(GL_VERTEX_SHADER);
	std::string vertexShader = R"#(
                            attribute vec3 position;
                            void main(void){
                                gl_Position = vec4(position, 1.0);
                            }
                            )#";
	const char* vs = vertexShader.c_str();
	glShaderSource(vShaderId, 1, &vs, NULL);
	glCompileShader(vShaderId);

	//�t���O�����g�V�F�[�_�̃R���p�C��
	GLuint fShaderId = glCreateShader(GL_FRAGMENT_SHADER);
	std::string fragmentShader = R"#(
                            void main(void){
                                gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);
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

int main() {
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

	GLenum err = glewInit();
	if (err == GLEW_OK) {
		std::cout << "GLEW OK : Glew Ver. " << glewGetString(GLEW_VERSION) << std::endl;
	}
	else {
		std::cout << "GLEW Error : " << glewGetErrorString(err) << std::endl;
	}

	GLuint programId = crateShader();

	// �Q�[�����[�v
	while (!glfwWindowShouldClose(window)) {

		// ��ʂ̏�����
		glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearDepth(1.0);

		// ���f���̕`��
		glDrawArrays(GL_TRIANGLES, 0, 3);

		// �o�b�t�@�̓���ւ�
		glfwSwapBuffers(window);

		// Poll for and process events
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}