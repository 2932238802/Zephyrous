
#pragma once
#include<SFML/Graphics.hpp>
#include<entt/entt.hpp>

#include"BlockComponent/BlockPosition.h"
#include"BlockComponent/BlockSquare.h"
#include"BlockComponent/BlockMovement.h"

/// <summary>
/// CreateSystem - 生成元素
/// </summary>
class CreateSystem
{
private:
	entt::registry& registry_;
	std::shared_ptr<sf::RenderWindow > window_;

public:
	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// 参数构造
	/// </summary>
	/// <param name="registry_out"></param>
	CreateSystem(entt::registry& registry_out,std::shared_ptr<sf::RenderWindow> window_out):
		registry_(registry_out),
		window_(std::move(window_out))
	{}
	//////////////////////////////////////////////////////////////////////////




	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// CreateSquare - 生成方块
	/// </summary>
	/// 
	/// <param name="registry_">
	/// registry_ - 全局唯一 
	/// </param>
	void CreateSquare(
		const BlockPosition&pos_,
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
		registry_.emplace<BlockMoveAble>(entt_);

		std::cout << pos_.x_ << pos_.y_ << std::endl;
	}
	//////////////////////////////////////////////////////////////////////////
};