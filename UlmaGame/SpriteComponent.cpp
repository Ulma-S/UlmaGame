#include "SpriteComponent.h"
#include "ShaderLoaderOpenGL.h"
#include "Actor.h"
#include "Math.h"
#include "Scene.h"
#include "Texture.h"
#include "Debug.h"

using namespace Game::Core;

SpriteComponent::SpriteComponent(class Actor& owner, int drawOrder)
	: Component(owner)
	, m_spriteType(Rectangle)
	, m_texture(new System::Core::Texture())
	, m_drawOrder(drawOrder)
{
	m_owner->GetScene().AddSprite(*this);
	m_texture->CreateTexture();
}


SpriteComponent::~SpriteComponent() {
	delete m_texture;
}


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

static float uv_rectangle[] = {
	1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
};

void SpriteComponent::Draw(System::Core::ShaderLoaderOpenGL& shader) {
	switch (m_spriteType) {
	case Triangle:
		shader.SetAttributeVerticies("inPosition", triangle_verticies);
		shader.SetAttributeVerticies("uv", uv_rectangle);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		break;

	case Rectangle:
		shader.SetAttributeVerticies("inPosition", rectangle_verticies);
		shader.SetAttributeVerticies("uv", uv_rectangle);
		shader.SetUniformInt("texture", 0);
		m_texture->Activate();
		shader.Activate();
		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
		if (glGetError() != GL_NO_ERROR) {
			//System::Debug::Log(glGetError() == GL_NO_ERROR);
		}
		break;

	default:
		break;
	}

	Math::Matrix4 scale = Math::Matrix4::CreateScale(100.0f, 100.0f, 1.0f);
	Math::Matrix4 world = scale * m_owner->GetTransform().GetWorldTransform();
	//shader.SetUniformMat4("uWorldTransform", world);
	//shader.Activate();
}