#include "Player.h"
#include "Debug.h"
#include "ShaderLoaderOpenGL.h"
#include "InputManagerOpenGL.h"
#include "Vector.h"
#include <string>

using namespace System::Core::InputSystem;

Game::Player::Player(System::SceneManagement::Scene& scene) 
	: Game::Core::Actor::Actor(scene)
{}


Game::Player::~Player(){
	delete m_shader;
}


void Game::Player::Initialize(){
	System::Debug::Log("Initialize player");
	m_shader = new System::Core::ShaderLoaderOpenGL();
	m_shader->LoadProgram("unlit.vert", "unlit.frag");
	m_shader->Activate();
	GetTransform().localPosition = Math::Vector2(0.0f, 0.0f);
}


void Game::Player::UpdateActor(float deltaTime){
	float posx = GetTransform().localPosition.x;
	float posy = GetTransform().localPosition.y;

	// 頂点データ
	float vertex_position[] = {
	   posx, posy + 0.5f,
	   posx + 0.4f, posy - 0.25f,
	   posx - 0.4f, posy - 0.25f,
	};

	//シェーダーに値をセット
	m_shader->SetAttributeVerticies("position", vertex_position);
	m_shader->SetUniformVec2("size", Math::Vector2(640.0f, 480.0f));
	m_shader->SetUniformFloat("scale", 100.0f);
	m_shader->Activate();

	// モデルの描画
	glDrawArrays(GL_TRIANGLES, 0, 3);

	GetTransform().localPosition.x += InputManagerOpenGL::GetInstance().GetAxis(Horizontal) * deltaTime;
	GetTransform().localPosition.y += InputManagerOpenGL::GetInstance().GetAxis(Vertical) * deltaTime;
	System::Debug::Log("X : " + std::to_string(posx));
	System::Debug::Log("Y : " + std::to_string(posy));
	System::Debug::Log("");
}