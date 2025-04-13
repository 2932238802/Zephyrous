
#pragma once
#include<SFML/Graphics.hpp>
#include<entt/entt.hpp>

#include"WindowComponent/WindowRuntime.h"
#include"ChunkComponent/ChunkConfig.h"
#include"Tool/Debug.h"

/// <summary>
/// RenderSystem - �滭�����߼�
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
	/// UpdateSquare - ��Ⱦ����
	/// </summary>
	void DrawSquare()
	{
		// windowtunrime_all - ��ȡӵ������ //
		// block_position_square_all - BlockPosition, BlockSquare //
		int i = 0;
		auto block_position_square_all =
			registry_.view<
			BlockPosition, 
			BlockSquare,
			BlockKind,
			BlockDifficulty,
			BlockMoveAble
			>();

		if (block_position_square_all.begin()== block_position_square_all.end())
		{
			std::cout << "entt is empty" << std::endl;
		}

		for (auto [entity_, pos_, square_,kind_,diffi_]:block_position_square_all.each())
		{
			square_.shape_.setPosition(pos_.GetPosition());
			std::cout << i++ << std::endl;
			window_->draw(square_.shape_);
		}
	}
	//////////////////////////////////////////////////////////////////////////
};