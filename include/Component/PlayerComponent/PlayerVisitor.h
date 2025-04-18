
#pragma once
#include"Tool/Debug.h"
#include"PlayerComponent/PlayerAcceleration.h"
#include<SFML/Graphics.hpp>
#include<entt/entt.hpp>
#include<iostream>

namespace
{
	constexpr float a_x = 3000.f;
}


/// <summary>
/// PlayerVisitor - 检测外设输入
/// </summary>
struct PlayerVisitor
{
	using key_t = sf::Keyboard::Key;
	sf::RenderWindow* window_;
	entt::registry& registry_;


	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// 
	/// </summary>
	/// 
	/// <param name="window">
	/// 初始化window
	/// </param>
	PlayerVisitor(sf::RenderWindow* window_out
		, entt::registry& registry_out)
		:
		window_(window_out),
		registry_(registry_out)
	{
	}
	//////////////////////////////////////////////////////////////////////////




	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// 设置窗口指针
	/// </summary>
	/// 
	/// <param name="window">
	/// window - 传入窗口指针
	/// </param>
	void SetWindow(sf::RenderWindow* window)
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
	/// 键盘点击
	/// </summary>
	/// <param name="e_">
	/// e_ 键盘点击参数
	/// </param>
	void operator()(const sf::Event::KeyPressed& e_)
	{
		// 点击左右 要加速度的
		switch (e_.code)
		{
			// 向上 //
		case (key_t::W):
		{
			std::cout << "跳跃 还未能实现!" << std::endl;
			break;
		}
		// 向左 //
		case (key_t::A):
		{
			auto entities_ = registry_.view<PlayerAcceleration>();
			for (auto a : entities_)
			{
				auto& acc_ = registry_.get<PlayerAcceleration>(a);
				acc_.a_x = -a_x;
			}
			break;
		}
		// 向右 //
		case (key_t::D):
		{
			auto entities_ = registry_.view<PlayerAcceleration>();
			for (auto a : entities_)
			{
				auto& acc_ = registry_.get<PlayerAcceleration>(a);
				acc_.a_x = a_x;
			}
			break;
		}
		// 向下 //
		case (key_t::S):
		{
			std::cout << "向下 还未能实现" << std::endl;
			break;

		}
		case(key_t::Space):
		{

		}
		default:
		{
			break;
		}
		}
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