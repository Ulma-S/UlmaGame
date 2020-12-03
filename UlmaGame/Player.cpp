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
	// 頂点データ
	float vertex_position[] = {
	   0.0, 0.5,
	   0.4, -0.25,
	   -0.4,-0.25,
	};

	// 何番目のattribute変数か
	int attLocation = glGetAttribLocation(programId, "position");

	// attribute属性を有効にする
	glEnableVertexAttribArray(attLocation);

	// OpenGLからシェーダに頂点情報を渡す
	glVertexAttribPointer(attLocation, 2, GL_FLOAT, false, 0, vertex_position);

	// モデルの描画
	glDrawArrays(GL_TRIANGLES, 0, 3);
}