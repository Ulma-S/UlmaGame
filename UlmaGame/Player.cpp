#include "Player.h"
#include "Debug.h"
#include "ShaderLoaderOpenGL.h"
#include "InputManagerOpenGL.h"
#include "Math.h"
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
}


void Game::Player::UpdateActor(float deltaTime){
	float posx = GetTransform().GetPosition().x;
	float posy = GetTransform().GetPosition().y;
	float posz = GetTransform().GetPosition().z;

	// 頂点データ
	float vertex_position[] = {
	   posx, posy + 0.5f, posz,
	   posx + 0.4f, posy - 0.25f, posz,
	   posx - 0.4f, posy - 0.25f, posz,
	};

	//シェーダーに値をセット
	/*m_shader->SetAttributeVerticies("position", vertex_position);
	m_shader->SetUniformVec2("size", Math::Vector2(640.0f, 480.0f));
	m_shader->SetUniformFloat("scale", 100.0f);*/
	Math::Matrix4 scale = Math::Matrix4::CreateScale(100.0f, 100.0f, 1.0f);
	Math::Matrix4 world = scale * GetTransform().GetWorldTransform();
	m_shader->SetAttributeVerticies("inPosition", vertex_position);
	m_shader->SetUniformMat4("uWorldTransform", world);
	Math::Matrix4 viewProj = Math::Matrix4::CreateViewProj(640.0f, 480.0f);
	m_shader->SetUniformMat4("uViewProj", viewProj);
	m_shader->Activate();

	// モデルの描画
	glDrawArrays(GL_TRIANGLES, 0, 3);

	GetTransform().GetPosition().x += InputManagerOpenGL::GetInstance().GetAxis(Horizontal) * deltaTime;
	GetTransform().GetPosition().y += InputManagerOpenGL::GetInstance().GetAxis(Vertical) * deltaTime;
	System::Debug::Log("X : " + std::to_string(posx));
	System::Debug::Log("Y : " + std::to_string(posy));
	System::Debug::Log("");
}