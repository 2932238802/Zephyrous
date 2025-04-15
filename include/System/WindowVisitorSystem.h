
#pragma once
#include"Tool/Debug.h"

#include<SFML/Graphics.hpp>
#include<entt/entt.hpp>
#include<iostream>

/// <summary>
/// WindowVisitor - 检测外设输入
/// </summary>
class WindowVisitor
{
public:



	std::shared_ptr<sf::RenderWindow> window_;
	entt::registry& registry_;
	

	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// 
	/// </summary>
	/// 
	/// <param name="window">
	/// 初始化window
	/// </param>
	WindowVisitor(sf::RenderWindow* window , entt::registry& registry_out) :
		window_(window),
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
	/// 关闭窗口
	/// </summary>
	/// 
	/// <param name="e_">
	/// e_ 无意义
	/// </param>
	void operator()(const sf::Event::Closed&)						
	{
		std::cout << "用户点击了关闭" << std::endl;
		if (window_ != nullptr && window_->isOpen())
		{
			window_->close();
		}
	}
	//////////////////////////////////////////////////////////////////////////




	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// 鼠标点击
	/// </summary>
	/// 
	/// <param name="e_">
	/// e_ 点击参数
	/// </param>
	void operator()(const sf::Event::MouseButtonPressed& e_)
	{
			std::cout << "用户左击鼠标" << std::endl;
			std::cout <<
				"x: " <<
				e_.position.x <<
				"y: " <<
				e_.position.y <<
				std::endl;
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
		(void)e_;
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
	{}
	//////////////////////////////////////////////////////////////////////////
};