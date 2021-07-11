#pragma once
#include <string>
#include <vector>
#include "SpriteComponent.h"

namespace UlmaEngine {
	class Actor;
	
	class TileMap : public SpriteComponent {
	public:
		TileMap(Actor& owner, int row = 10, int col = 10, float width = 100, float height = 100);
		~TileMap() override;

		void Draw(const Core::ShaderLoaderOpenGL& shader) const override;
		
		void Register(const std::vector<std::vector<std::string>>& tileArray);

		inline int GetRow() const { return m_row; }
		inline int GetCol() const { return m_col; }
	
	private:
		int m_row;
		int m_col;
		float m_width;
		float m_height;
		std::vector<std::vector<std::string>> m_tileArray;
	};
}
