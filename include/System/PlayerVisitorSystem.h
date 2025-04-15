
#pragma once

#include<SFML/Graphics.hpp>
#include<entt/entt.hpp>

class PlayerVisitorSystem
{
public:
	std::shared_ptr<sf::RenderWindow> window_;
	entt::registry& registry_;

	
	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// 设置窗口指针
	/// </summary>
	/// 
	/// <param name="window">
	/// window - 传入窗口指针
	/// </param>
	void SetWindow(std::shared_ptr<sf::RenderWindow> window)
	{
		if (window != nullptr)
		{
			window_ = window;
		}
		else
		{
			DLOG("wrong in window(is nullptr!)");
		}
	}
	//////////////////////////////////////////////////////////////////////////



	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// 鼠标移动
	/// </summary>
	/// 
	/// <param name="e_">
	/// e_ 移动参数
	/// </param>
	void operator()(const sf::Event::MouseMoved&)
	{
	}
	//////////////////////////////////////////////////////////////////////////



	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	///  模板事件处理
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="_r"></param>
	template<class T>
	void operator()(T&& _r)											//其他事件
	{
	}
	//////////////////////////////////////////////////////////////////////////

};