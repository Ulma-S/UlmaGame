#include <iostream>
#include "WindowOpenGL.h"

System::Core::WindowOpenGL::WindowOpenGL() : m_window(nullptr), m_windowWidth(640), m_windowHeight(480) {}


System::Core::WindowOpenGL::WindowOpenGL(int windowWidth, int windowHeight) : m_window(nullptr), m_windowWidth(windowWidth), m_windowHeight(windowHeight) {}


System::Core:: WindowOpenGL::~WindowOpenGL() {}


bool System::Core::WindowOpenGL::CreateWindow() {
	//OpenGL ES 2.0�v���t�@�C���̐ݒ�
	glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	//GLFW�̏�����
	if (!glfwInit()) {
		std::cout << "GLFW�̏������Ɏ��s���܂����B" << std::endl;
		return false;
	}

	//�E�B���h�E�쐬
	m_window = glfwCreateWindow(m_windowWidth, m_windowHeight, "Ulma Game", nullptr, nullptr);
	if (!m_window) {
		glfwTerminate();
		return -1;
	}

	// ���j�^�Ƃ̓���
	glfwMakeContextCurrent(m_window);
	glfwSwapInterval(1);

	//GLEW�̏�����
	if (glewInit() != GLEW_OK) {
		return -1;
	}

	return true;
}


void System::Core::WindowOpenGL::Finalize() {
	glfwTerminate();
}


void System::Core::WindowOpenGL::PollEvent() {
	glfwPollEvents();
}


bool System::Core::WindowOpenGL::CanLoop() {
	return !glfwWindowShouldClose(m_window);
}