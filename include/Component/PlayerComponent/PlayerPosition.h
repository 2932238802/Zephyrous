

#pragma once
#include<SFML/Graphics.hpp>

/// <summary>
/// PlayerPosition - 玩家的位置信息
/// </summary>
struct PlayerPosition
{
	float x;
	float y;

	PlayerPosition(const sf::Vector2f& pos_)
	{
		x = pos_.x;
		y = pos_.y;
	}

	sf::Vector2f GetPosition()
	{
		return { x,y };
	}
};