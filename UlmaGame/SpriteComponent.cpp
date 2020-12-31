#include "SpriteComponent.h"
#include "ShaderLoaderOpenGL.h"
#include "Actor.h"
#include "Math.h"
#include "Scene.h"
#include "Texture.h"
#include "TextureProvider.h"
#include "Debug.h"

using namespace Game::Core;

SpriteComponent::SpriteComponent(Actor& owner, int drawOrder)
	: Component(owner)
	, m_spriteType(Rectangle)
	, m_drawOrder(drawOrder) 
	, m_assetName("noodle")
{
	m_owner->GetScene().AddSprite(*this);
}


SpriteComponent::SpriteComponent(Actor& owner, ESpriteType type, int drawOrder)
	: Component(owner)
	, m_spriteType(type)
	, m_drawOrder(drawOrder) 
	, m_assetName("noodle")
{
	m_owner->GetScene().AddSprite(*this);
}


SpriteComponent::SpriteComponent(Actor& owner, const char* assetName, ESpriteType type, int drawOrder) 
	: Component(owner)
	, m_spriteType(Rectangle)
	, m_drawOrder(drawOrder)
	, m_assetName(assetName)
{
	m_owner->GetScene().AddSprite(*this);
}


SpriteComponent::~SpriteComponent() {
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
	0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
};

static float uv_triangle[] = {
	0.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	0.5f,   sq, 0.0f,
};

void SpriteComponent::Draw(System::Core::ShaderLoaderOpenGL& shader) {
	auto texture = System::Core::TextureProvider::GetInstance().GetTexture(m_assetName);

	if (texture != nullptr) {
		switch (m_spriteType) {
		case Triangle:
			shader.SetAttributeVertices("inPosition", triangle_verticies);
			shader.SetAttributeVertices("uv", uv_rectangle);
			shader.SetUniformInt("uTexture", 0);
			System::Core::TextureProvider::GetInstance().UseTexture(m_assetName);
			shader.Activate();
			glDrawArrays(GL_TRIANGLES, 0, 3);
			break;

		case Rectangle:
			shader.SetAttributeVertices("inPosition", rectangle_verticies);
			shader.SetAttributeVertices("uv", uv_rectangle);
			shader.SetUniformInt("uTexture", 0);
			System::Core::TextureProvider::GetInstance().UseTexture(m_assetName);
			shader.Activate();
			glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
			break;

		default:
			break;
		}

		Math::Matrix4 scale = Math::Matrix4::CreateScale((float)texture->GetWidth() / 2, (float)texture->GetHeight() / 2, 1.0f);
		Math::Matrix4 world = scale * m_owner->GetTransform().GetWorldTransform();
		shader.SetUniformMat4("uWorldTransform", world);
		shader.Activate();
	}
}
