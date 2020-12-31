#include <iostream>
#include "WindowOpenGL.h"

System::Core::WindowOpenGL::WindowOpenGL() : m_window(nullptr), m_windowWidth(1080), m_windowHeight(720), m_scale(100.0f) {}


System::Core::WindowOpenGL::WindowOpenGL(int windowWidth, int windowHeight) : m_window(nullptr), m_windowWidth(windowWidth), m_windowHeight(windowHeight), m_scale(100.0f) {}


System::Core:: WindowOpenGL::~WindowOpenGL() {}


bool System::Core::WindowOpenGL::CreateWindow() {
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 4);

	//GLFWの初期化
	if (!glfwInit()) {
		std::cout << "GLFWの初期化に失敗しました。" << std::endl;
		return false;
	}
	
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);	//ウィンドウのサイズ変更禁止


	//ウィンドウ作成
	m_window = glfwCreateWindow(m_windowWidth, m_windowHeight, "Ulma Game", nullptr, nullptr);
	if (!m_window) {
		glfwTerminate();
		return false;
	}

	// モニタとの同期
	glfwMakeContextCurrent(m_window);
	glfwSwapInterval(1);

	//GLEWの初期化
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cout << "GLEWの初期化に失敗しました。" << std::endl;
		return false;
	}
	glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);	//OpenGL ES 2.0プロファイルの設定
	
	glViewport(0, 0, m_windowWidth, m_windowHeight);
	return true;
}


void System::Core::WindowOpenGL::ClearDisplayBuffer() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearDepth(1.0f);

	//マルチサンプリング
	glEnable(GL_MULTISAMPLE);

	//アルファブレンディング
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}


void System::Core::WindowOpenGL::SwapBuffer() {
	glfwSwapBuffers(m_window);
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


float System::Core::WindowOpenGL::GetCurrentTime() {
	return (float) glfwGetTime();
}