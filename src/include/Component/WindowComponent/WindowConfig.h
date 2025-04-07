

#pragma once

#include <string>
#include <SFML/Graphics.hpp>

struct WindowConfig
{
	/// <summary>
	/// mode_ - 尺寸
	/// name_ - 窗口名字
	/// style_  - 屏幕
	/// vsync_ - 垂直
	/// clear_color - 刷新颜色
	/// </summary>
	sf::VideoMode mode_;
	std::string name_;
	uint32_t style_;
	bool vsync_;
	sf::Color clear_color;

	WindowConfig()
		: mode_{ {600, 600} }, // 初始化为 600x600
		name_{ "Zephyrous" },
		style_{ sf::Style::Default },
		vsync_{ true },
		clear_color{ sf::Color::Black }
	{
	}
};
