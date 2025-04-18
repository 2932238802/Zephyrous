


#pragma once
#include<SFML/Graphics.hpp>
#include<entt/entt.hpp>

#include"System/PlayerVisitorSystem.h"
#include"System/WindowVisitorSystem.h"


/// <summary>
/// 任务分发系统 
/// </summary>
class DispatcherSystem
{
private:

	entt::registry& registry_;


public:
	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// 默认构造函数
	/// </summary>
	/// 
	/// <param name="registry_out">
	/// 全局唯一 registry
	/// </param>
	DispatcherSystem(entt::registry& registry_out):
		registry_(registry_out)
	{}
	//////////////////////////////////////////////////////////////////////////





	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// /
	/// </summary>
	/// <param name="event"></param>
	/// <param name="wvisitor_"></param>
	/// <param name="pvisitor_"></param>
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

