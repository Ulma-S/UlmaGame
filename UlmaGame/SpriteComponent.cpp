#include "SpriteComponent.h"
#include "ShaderLoaderOpenGL.h"
#include "Actor.h"
#include "Math.h"
#include "Scene.h"
#include "Texture.h"
#include "TextureProvider.h"
#include "Debug.h"

using namespace Game::Core;

const int circleDiv = 64;	//‰~‚Ì•ªŠ„”
void SetCircleVertices();

SpriteComponent::SpriteComponent(Actor& owner, int drawOrder)
	: Component(owner)
	, m_spriteType(Rectangle)
	, m_drawOrder(drawOrder) 
	, m_assetName("noodle")
{
	m_owner->GetScene().AddSprite(*this);
	SetCircleVertices();
}


SpriteComponent::SpriteComponent(Actor& owner, ESpriteType type, int drawOrder)
	: Component(owner)
	, m_spriteType(type)
	, m_drawOrder(drawOrder) 
	, m_assetName("noodle")
{
	m_owner->GetScene().AddSprite(*this);
	SetCircleVertices();
}


SpriteComponent::SpriteComponent(Actor& owner, const char* assetName, ESpriteType type, int drawOrder) 
	: Component(owner)
	, m_spriteType(Rectangle)
	, m_drawOrder(drawOrder)
	, m_assetName(assetName)
{
	m_owner->GetScene().AddSprite(*this);
	SetCircleVertices();
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

static float circle_vertices[circleDiv * 3];

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


void SetCircleVertices() {
	for (int i = 0; i < circleDiv; ++i) {
		GLfloat angle = static_cast<GLfloat>((M_PI * 2.0 * i) / circleDiv);
		circle_vertices[i * 3] = 0.5f * std::sin(angle);
		circle_vertices[i * 3 + 1] = 0.5f * std::cos(angle);
		circle_vertices[i * 3 + 2] = 0.0f;
	}
}

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

		case Circle:
		{
			shader.SetAttributeVertices("inPosition", circle_vertices);
			shader.SetAttributeVertices("uv", uv_rectangle);
			System::Core::TextureProvider::GetInstance().UseTexture(m_assetName);
			shader.Activate();
			glDrawArrays(GL_TRIANGLE_FAN, 0, circleDiv);
			shader.SetUniformInt("uTexture", 0);
		}
			break;

		default:
			break;
		}

		Math::Matrix4 scale = Math::Matrix4::CreateScale((float)texture->GetWidth() / 2, (float)texture->GetHeight() / 2, 1.0f);
		scale = Math::Matrix4::CreateScale(300.0, 300.0, 1.0);
		Math::Matrix4 world = scale * m_owner->GetTransform().GetWorldTransform();
		shader.SetUniformMat4("uWorldTransform", world);
		shader.Activate();
	}
}
