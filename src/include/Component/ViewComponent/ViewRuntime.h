#pragma once
#include<SFML/Graphics.hpp>

struct ViewRuntime
{
	sf::View view;
	
	ViewRuntime() = default;


	const void Init(const sf::FloatRect&rect_out ,const sf::Vector2f&size_out , const sf::Vector2f&center_out)
	{
		view.setSize(size_out);
		view.setCenter(size_out);
		view.setViewport(rect_out);
	}
};