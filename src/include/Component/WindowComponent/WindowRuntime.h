#pragma once
#include<sfml/Graphics.hpp>
#include<iostream>


struct WindowRuntime
{
	std::unique_ptr<sf::RenderWindow> window_handle;
	sf::Color clear_color = sf::Color::Black;
	bool is_close = false;

	/// <summary>
	/// - 构造函数，初始化窗口句柄和其他参数
	/// </summary>
	/// 
	/// <param name="mode_">
	/// mode_ - 模型大小
	/// </param>
	/// 
	/// <param name="title_">
	/// title_ - 窗口标题
	/// </param>
	/// 
	/// <param name="clear_color_out">
	/// clear_color_out - 刷新颜色
	/// </param>
	WindowRuntime(const sf::VideoMode& mode_, const std::string& title_, sf::Color clear_color_out = sf::Color::Black)
		: 
		window_handle(std::make_unique<sf::RenderWindow>(mode_, title_, sf::Style::Titlebar | sf::Style::Close)),
		clear_color(clear_color_out),
		is_close(false)
	{
		if (window_handle)
		{
			window_handle->setVerticalSyncEnabled(true);
		}
	}

	/// <summary>
	/// 构造限制
	/// </summary>
	WindowRuntime() = default;
	WindowRuntime(const WindowRuntime&) = delete;
	WindowRuntime& operator=(const WindowRuntime&) = delete;
	WindowRuntime(WindowRuntime&&) noexcept = default;
	WindowRuntime& operator=(WindowRuntime&&) noexcept = default;
};

