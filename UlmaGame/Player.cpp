#include "Player.h"
#include "Debug.h"
#include "ShaderLoaderOpenGL.h"

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
	   0.0, 0.5,
	   0.4, -0.25,
	   -0.4,-0.25,
	};

	// ���Ԗڂ�attribute�ϐ���
	int attLocation = glGetAttribLocation(programId, "position");

	// attribute������L���ɂ���
	glEnableVertexAttribArray(attLocation);

	// OpenGL����V�F�[�_�ɒ��_����n��
	glVertexAttribPointer(attLocation, 2, GL_FLOAT, false, 0, vertex_position);

	// ���f���̕`��
	glDrawArrays(GL_TRIANGLES, 0, 3);
}