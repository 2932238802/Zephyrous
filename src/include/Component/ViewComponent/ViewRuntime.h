#pragma once
#include<SFML/Graphics.hpp>

struct ViewRuntime
{
	sf::View view;

	ViewRuntime()
	{
		//////////////////////////////////////////////////////////////////////////
		// 这里可以json 优化
		//////////////////////////////////////////////////////////////////////////
		sf::FloatRect _viewport(									//归一化
			{ 0.f,0.f },
			{ 1.f,1.f }
		);

		view.setSize({ 600.f,600.f });
		view.setCenter({ 300.f, 300.f});
		view.setViewport(_viewport);
	}
};