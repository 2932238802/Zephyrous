
#pragma once
#include<SFML/Graphics.hpp>
#include<entt/entt.hpp>

#include"BlockComponent/BlockPosition.h"
#include"BlockComponent/BlockSquare.h"
#include"WindowComponent/WindowRuntime.h"

#include"Tool/Debug.h"

/// <summary>
/// RenderSystem - 绘画处理逻辑
/// </summary>
class RenderSystem
{
private:
	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// 
	/// </summary>
	entt::registry& registry_;
	std::shared_ptr<sf::RenderWindow> window_;

public:
	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// 
	/// </summary>
	/// <param name="register_out"></param>
	RenderSystem(
		entt::registry& register_out,
		std::shared_ptr<sf::RenderWindow> window_out
	) :
		registry_(register_out),
		window_(std::move(window_out))
	{
	}
	//////////////////////////////////////////////////////////////////////////




public:
	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// UpdateSquare - 渲染方块
	/// </summary>
	void DrawSquare()
	{
		// windowtunrime_all - 获取拥有属性 //
		// block_position_square_all - BlockPosition, BlockSquare //
		auto block_position_square_all =
			registry_.view<BlockPosition, BlockSquare,BlockMoveAble>();

		if (block_position_square_all.begin()== block_position_square_all.end())
		{
			std::cout << "entt is empty" << std::endl;
		}

		for (auto [entity_, pos_, square_ ]:block_position_square_all.each())
		{
			square_.shape_.setPosition(pos_.GetPosition());
			window_->draw(square_.shape_);
		}
	}
	//////////////////////////////////////////////////////////////////////////
};