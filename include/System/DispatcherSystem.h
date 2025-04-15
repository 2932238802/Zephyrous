


#pragma once
#include<SFML/Graphics.hpp>
#include<entt/entt.hpp>

#include"System/PlayerVisitorSystem.h"
#include"System/WindowVisitorSystem.h"

class DispatcherSystem
{
private:

	entt::registry& registry_;


public:
	DispatcherSystem(entt::registry& registry_out):
		registry_(registry_out)
	{}

	void DisPatch(const sf::Event& event,
		WindowVisitorSystem& wvisitor_,
		PlayerVisitorSystem& pvisitor_
	)
	{
		wvisitor_.HandleEvent(event);
		pvisitor_.HandleEvent(event);
	}
private:

};

