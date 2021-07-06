#include <iostream>
#include "WindowOpenGL.h"

using namespace UlmaEngine::Core;

WindowOpenGL::WindowOpenGL() : m_window(nullptr), m_windowWidth(1080), m_windowHeight(720), m_scale(100.0f) {}


WindowOpenGL::WindowOpenGL(int windowWidth, int windowHeight) : m_window(nullptr), m_windowWidth(windowWidth), m_windowHeight(windowHeight), m_scale(100.0f) {}


WindowOpenGL::~WindowOpenGL() {}


bool WindowOpenGL::CreateWindow() {
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 4);

	//GLFW�̏�����
	if (!glfwInit()) {
		std::cout << "GLFW�̏������Ɏ��s���܂����B" << std::endl;
		return false;
	}
	
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);	//�E�B���h�E�̃T�C�Y�ύX�֎~


	//�E�B���h�E�쐬
	m_window = glfwCreateWindow(m_windowWidth, m_windowHeight, "Ulma Game", nullptr, nullptr);
	if (!m_window) {
		glfwTerminate();
		return false;
	}

	// ���j�^�Ƃ̓���
	glfwMakeContextCurrent(m_window);
	glfwSwapInterval(1);

	//GLEW�̏�����
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cout << "GLEW�̏������Ɏ��s���܂����B" << std::endl;
		return false;
	}
	glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);	//OpenGL ES 2.0�v���t�@�C���̐ݒ�
	
	glViewport(0, 0, m_windowWidth, m_windowHeight);
	return true;
}


void WindowOpenGL::ClearDisplayBuffer() const {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearDepth(1.0f);

	//�}���`�T���v�����O
	glEnable(GL_MULTISAMPLE);

	//�A���t�@�u�����f�B���O
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}


void WindowOpenGL::SwapBuffer() const {
	glfwSwapBuffers(m_window);
}


void WindowOpenGL::Finalize() const {
	glfwTerminate();
}


void WindowOpenGL::PollEvent() const {
	glfwPollEvents();
}


bool WindowOpenGL::CanLoop() const {
	return !glfwWindowShouldClose(m_window);
}


float WindowOpenGL::GetCurrentTime() const {
	return static_cast<float>(glfwGetTime());
}