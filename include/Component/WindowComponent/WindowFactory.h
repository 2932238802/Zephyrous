#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>

#include"WindowComponent/WindowRuntime.h"

struct WindowFactory
{
	/// <summary>
	/// 创建并返回一个新的 WindowRuntime 实例
	/// </summary>
	/// 
	/// <param name="mode_">
	/// 窗口视频模式
	/// </param>
	/// 
	/// <param name="title_">
	/// 窗口标题
	/// </param>
	/// 
	/// <param name="clear_color_out">
	/// 窗口清除颜色
	/// </param>
	/// 
	/// <returns>
	/// 指向 WindowRuntime的唯一指针
	/// </returns>
	static WindowRuntime CreateWindow(const sf::VideoMode& mode_, const std::string& title_, sf::Color clear_color_out = sf::Color::Black)
	{
		return WindowRuntime(mode_, title_, clear_color_out);
	}
};


//::Titlebar | sf::Style::Close