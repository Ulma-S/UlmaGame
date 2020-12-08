#include "SpriteComponent.h"
#include "ShaderLoaderOpenGL.h"

using namespace Game::Core;

SpriteComponent::SpriteComponent(class Actor& owner, int drawOrder)
	: Component(owner)
	, m_spriteType(Rectangle)
{}


SpriteComponent::~SpriteComponent() {}


void SpriteComponent::Update(float deltaTime) {
}


void SpriteComponent::Draw(System::Core::ShaderLoaderOpenGL& shaderLoader) {
}