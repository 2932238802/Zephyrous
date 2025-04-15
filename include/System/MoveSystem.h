
#pragma once
#include<SFML/Graphics.hpp>
#include<entt/entt.hpp>

#include"BlockComponent/BlockPosition.h"


class MoveSystem
{
private:
	/// <summary>
	/// 
	/// </summary>
	entt::registry&registry_;
	std::shared_ptr<sf::RenderWindow> window_;



public:
	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// MoveSystem - ªÒ»°esc
	/// </summary>
	/// <param name="registry_out"></param>
	MoveSystem(entt::registry& registry_out,std::shared_ptr<sf::RenderWindow> window_out):
		registry_(registry_out),
		window_(std::move(window_out))
	{
	}
	//////////////////////////////////////////////////////////////////////////


public:
	


private:

};