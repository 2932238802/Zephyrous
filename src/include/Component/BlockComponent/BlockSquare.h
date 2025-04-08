
#pragma once
#include<SFML/Graphics.hpp>

struct BlockSquare
{
	BlockSquare(
		const sf::Vector2f& size_out,
			float thickness_out,
			const sf::Color& color_in_out,
			const sf::Color& color_out_out
	):
		color_in(color_in_out),
		color_out(color_out_out),
		thinkness_(thickness_out),
		width_(size_out.x),
		height_(size_out.y)
	{
		shape_.setFillColor(color_in);
		shape_.setOutlineColor(color_out);
		shape_.setOutlineThickness(thinkness_);
		shape_.setSize(size_out);
	}

	sf::RectangleShape shape_;
	sf::Color color_in;
	sf::Color color_out;
	float width_;
	float height_;
	float thinkness_;
};