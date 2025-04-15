
#pragma once
#include"WindowComponent/WindowVisitor.h"
class WindowVisitorSystem
{
private:
	WindowVisitor visitor_;
	sf::RenderWindow* window_;
	entt::registry&registry_;

public:
	WindowVisitorSystem(
		entt::registry& registry_out,
		sf::RenderWindow* window_out
	) :
	window_(window_out),
	visitor_(window_out, registry_out),
	registry_(registry_out)
	{
	}


public:
	void HandleEvent(const sf::Event& e_)
	{
		e_.visit(visitor_);
	}
};