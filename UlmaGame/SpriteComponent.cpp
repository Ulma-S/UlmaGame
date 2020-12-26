#include "SpriteComponent.h"
#include "ShaderLoaderOpenGL.h"
#include "Actor.h"
#include "Math.h"
#include "Scene.h"
#include "Debug.h"

using namespace Game::Core;

SpriteComponent::SpriteComponent(class Actor& owner, int drawOrder)
	: Component(owner)
	, m_spriteType(Rectangle)
	, m_drawOrder(drawOrder)
{
	m_owner->GetScene().AddSprite(*this);
}


SpriteComponent::~SpriteComponent() {}


float sq = 1.0f * sqrt(3.0f) / 2.0f;
static float triangle_verticies[] = {
	 0.0f,  sq * 2.0f / 3.0f,  0.0f,
	 0.5f, -sq * 1.0f / 3.0f,  0.0f,
	-0.5f, -sq * 1.0f / 3.0f,  0.0f,
};

static float rectangle_verticies[] = {
	-0.5f,  0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.5f,  0.5f, 0.0f,
};

void SpriteComponent::Draw(System::Core::ShaderLoaderOpenGL& shader) {
	switch (m_spriteType) {
	case Triangle:
		shader.SetAttributeVerticies("inPosition", triangle_verticies);	
		glDrawArrays(GL_TRIANGLES, 0, 3);
		break;

	case Rectangle:
		shader.SetAttributeVerticies("inPosition", rectangle_verticies);
		glDrawArrays(GL_POLYGON, 0, 4);
		break;

	default:
		break;
	}

	Math::Matrix4 scale = Math::Matrix4::CreateScale(100.0f, 100.0f, 1.0f);
	Math::Matrix4 world = scale * m_owner->GetTransform().GetWorldTransform();
	shader.SetUniformMat4("uWorldTransform", world);
	shader.Activate();
}