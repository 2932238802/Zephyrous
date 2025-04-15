
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
	/// ���ô���ָ��
	/// </summary>
	/// 
	/// <param name="window">
	/// window - ���봰��ָ��
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
	/// ����ƶ�
	/// </summary>
	/// 
	/// <param name="e_">
	/// e_ �ƶ�����
	/// </param>
	void operator()(const sf::Event::MouseMoved&)
	{
	}
	//////////////////////////////////////////////////////////////////////////



	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	///  ģ���¼�����
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="_r"></param>
	template<class T>
	void operator()(T&& _r)											//�����¼�
	{
	}
	//////////////////////////////////////////////////////////////////////////

};