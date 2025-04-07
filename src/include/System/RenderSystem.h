
#pragma once
#include<SFML/Graphics.hpp>
#include<entt/entt.hpp>

#include"BlockComponent/BlockPosition.h"
#include"BlockComponent/BlockSquare.h"
#include"Tool/Debug.h"
/// <summary>
/// RenderSystem - »æ»­´¦ÀíÂß¼­
/// </summary>
class RenderSystem
{
private:
	sf::RenderWindow* window_;
	entt::registry& register_;

public:
	RenderSystem(
		entt::registry& register_out,
		sf::RenderWindow* window_out
	):
		window_(window_out),
		register_(register_out)
	{}

	void Update()
	{
		auto block_position_square_all =
			register_.view<BlockPosition, BlockSquare>();
		for (auto entity_ : block_position_square_all)
		{
			const auto& pos_ = block_position_square_all.get<BlockPosition>(entity_);
			auto& square_ = block_position_square_all.get<BlockSquare>(entity_);

			square_.shape_.setPosition({ pos_.x_, pos_.y_ });

			if (window_ != nullptr)
			{
				window_->draw(square_.shape_);
			}
			else
			{
				DLOG;
			}
		}

	}

};