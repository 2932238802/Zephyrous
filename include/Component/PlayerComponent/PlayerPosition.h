

#pragma once
#include<SFML/Graphics.hpp>

struct PlayerPosition
{
	float x;
	float y;

	PlayerPosition(const sf::Vector2f& pos_)
	{
		x = pos_.x;
		y = pos_.y;
	}

};