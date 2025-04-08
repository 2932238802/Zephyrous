
#pragma once
#include<SFML/Graphics.hpp>
#include<entt/entt.hpp>

#include"BlockComponent/BlockPosition.h"
#include"BlockComponent/BlockSquare.h"

class CreateSystem
{
private:
	entt::registry& registry_;

public:

	CreateSystem(entt::registry& registry_out):
		registry_(registry_out)
	{}

	/// <summary>
	/// CreateSquare - 生成方块
	/// </summary>
	/// 
	/// <param name="registry_">
	/// registry_ - 全局唯一 
	/// </param>
	void CreateSquare(
		BlockPosition pos_,
		const sf::Vector2f& size_,
		float thickness_,
		const sf::Color& color_in,
		const sf::Color& color_out
	)
	{
		BlockSquare square_(size_,thickness_ , color_in, color_out);
		auto entt_ = registry_.create();
		registry_.emplace<BlockPosition>(entt_, pos_);
		registry_.emplace<BlockSquare>(entt_, square_);
	}
};