
#pragma once
#include<SFML/Graphics.hpp>
#include<entt/entt.hpp>

class MoveSystem
{
private:
	entt::registry&registry_;
public:
	MoveSystem(entt::registry& registry_out):
		registry_(registry_out)
	{
	}




private:

};