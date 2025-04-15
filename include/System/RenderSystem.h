
#pragma once
#include<SFML/Graphics.hpp>
#include<entt/entt.hpp>

#include"WindowComponent/WindowRuntime.h"
#include"ChunkComponent/ChunkConfig.h"
#include"PlayerComponent/Player.h"

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
			registry_.view<
			BlockPosition,
			BlockSquare,
			BlockKind,
			BlockDifficulty
			>();

		if (block_position_square_all.begin() == block_position_square_all.end())
		{
			DLOG("entt is empty");		// 打印
			return;						// 避免不必要的循环
		}
		for (auto [entity_, pos_, square_, kind_, diffi_] : block_position_square_all.each())
		{
			square_.shape_.setPosition(pos_.GetPosition());
			window_->draw(square_.shape_);
		}
	}
	//////////////////////////////////////////////////////////////////////////



public:
	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// DrawPlayer - 人物绘制
	/// </summary>
	void DrawPlayer()
	{
		auto player_ = registry_.view<
			PlayerPosition,
			BlockSquare
		>();

		/*for (auto [entity_, position, square] : player_)
		{
			square.shape_.setPosition({ position.x, position.y });
			window_->draw(square.shape_);
		}*/

		for (auto entity_ : player_)
		{
			auto& position = registry_.get<PlayerPosition>(entity_);
			auto& square = registry_.get<BlockSquare>(entity_);
			square.shape_.setPosition({ position.x,position.y });
			window_->draw(square.shape_);
		}
	}
	//////////////////////////////////////////////////////////////////////////

};