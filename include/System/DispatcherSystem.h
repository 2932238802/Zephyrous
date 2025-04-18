


#pragma once
#include<SFML/Graphics.hpp>
#include<entt/entt.hpp>

#include"System/PlayerVisitorSystem.h"
#include"System/WindowVisitorSystem.h"


/// <summary>
/// ����ַ�ϵͳ 
/// </summary>
class DispatcherSystem
{
private:

	entt::registry& registry_;


public:
	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// Ĭ�Ϲ��캯��
	/// </summary>
	/// 
	/// <param name="registry_out">
	/// ȫ��Ψһ registry
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

