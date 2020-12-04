#include "Player.h"
#include "Debug.h"
#include "ShaderLoaderOpenGL.h"
#include "InputManagerOpenGL.h"
#include <string>

using namespace System::Core::InputSystem;

Game::Player::Player(System::SceneManagement::Scene& scene) 
	: Game::Actor::Actor(scene)
{}


Game::Player::~Player(){}


void Game::Player::Initialize(){
	System::Debug::Log("Initialize player");
	programId = System::Core::ShaderLoaderOpenGL::GetInstance().LoadProgram("unlit.vert", "unlit.frag");
}


void Game::Player::UpdateActor(float deltaTime){

	// ���_�f�[�^
	float vertex_position[] = {
	   posx, posy + 0.5,
	   posx + 0.4, posy - 0.25,
	   posx - 0.4, posy - 0.25,
	};

	// ���Ԗڂ�attribute�ϐ���
	int attLocation = glGetAttribLocation(programId, "position");
	int sizeLoc = glGetUniformLocation(programId, "size");
	int scaleLoc = glGetUniformLocation(programId, "scale");

	// attribute������L���ɂ���
	glEnableVertexAttribArray(attLocation);

	// OpenGL����V�F�[�_�ɒ��_����n��
	glVertexAttribPointer(attLocation, 2, GL_FLOAT, false, 0, vertex_position);

	float size[] = {640.0f, 480.0f};
	float scale = 100.0f;
	glUniform2fv(sizeLoc, 1, size);
	glUniform1f(scaleLoc , scale);

	// ���f���̕`��
	glDrawArrays(GL_TRIANGLES, 0, 3);

	posx += InputManagerOpenGL::GetInstance().GetAxis(Horizontal) * deltaTime;
	posy += InputManagerOpenGL::GetInstance().GetAxis(Vertical) * deltaTime;
	System::Debug::Log("X : " + std::to_string(posx));
	System::Debug::Log("Y : " + std::to_string(posy));
	System::Debug::Log("");
}