#include <algorithm>
#include "TileMap.h"
#include "Actor.h"
#include "Vector.h"
#include "TextureProvider.h"
#include "ShaderLoaderOpenGL.h"
#include "Texture.h"

using namespace UlmaEngine;


TileMap::TileMap(Actor& owner, int row, int col, float width, float height)
	: SpriteComponent(owner)
	, m_row(row)
	, m_col(col)
	, m_width(width)
	, m_height(height)
{
	m_tileArray = std::vector(col, std::vector<std::string>(row));
}


TileMap::~TileMap() {
	m_tileArray.clear();
	m_tileArray.shrink_to_fit();
}

static float rectangle_vertices[] = {
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

void TileMap::Draw(const Core::ShaderLoaderOpenGL& shader) const {
	if (!enable) {
		return;
	}

	for (int i = 0; i < m_col; ++i) {
		for (int j = 0; j < m_row; ++j) {

			auto tex = Core::TextureProvider::GetInstance().GetTexture(m_tileArray[i][j]);
			if(tex == nullptr) {
				continue;
			}
			
			Core::TextureProvider::GetInstance().UseTexture(m_tileArray[i][j]);

			//300px‚ðŠî€‚Æ‚µ‚ÄŒvŽZ
			auto ts = new Transform();
			ts->position = Math::Vector3(m_width * static_cast<float>(j), m_height * static_cast<float>(i), 0.f);
			ts->position += m_owner->GetTransform().position;			
			ts->scale = m_owner->GetTransform().scale;
			
			auto tVec = Math::Vector3(static_cast<float>(tex->GetWidth()),static_cast<float>(tex->GetHeight()),1.f);
			auto min = std::min(tVec.x, tVec.y);
			auto tmp = m_owner->GetTransform().GetSize() / min;
			tmp.z = 1.f;

			Math::Vector3 sc = Math::Vector3(ts->scale.x * tmp.x, ts->scale.y * tmp.y, ts->scale.z * tmp.z);
			sc = Math::Vector3(sc.x * tVec.x, sc.y * tVec.y, sc.z * tVec.z);
			Math::Matrix4 scale = Math::Matrix4::CreateScale(sc.x, sc.y, sc.z);

			ts->ComputeWorldTransform();

			Math::Matrix4 world = scale * ts->GetWorldTransform();
			
			shader.SetUniformMat4("uWorldTransform", world);

			shader.SetAttributeVertices("inPosition", rectangle_vertices);
			shader.SetAttributeVertices("uv", uv_rectangle);
			shader.Activate();
			glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
			shader.SetUniformInt("uTexture", 0);
			
			delete ts;
		}
	}
}


void TileMap::Register(const std::vector<std::vector<std::string>>& tileArray) {
	m_tileArray = tileArray;
}

