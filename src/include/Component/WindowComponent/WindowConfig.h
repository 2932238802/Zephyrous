

#pragma once

#include <string>
#include <SFML/Graphics.hpp>

struct WindowConfig
{
	/// <summary>
	/// mode_ - �ߴ�
	/// name_ - ��������
	/// style_  - ��Ļ
	/// vsync_ - ��ֱ
	/// clear_color - ˢ����ɫ
	/// </summary>
	sf::VideoMode mode_;
	std::string name_;
	uint32_t style_;
	bool vsync_;
	sf::Color clear_color;

	WindowConfig()
		: mode_{ {600, 600} }, // ��ʼ��Ϊ 600x600
		name_{ "Zephyrous" },
		style_{ sf::Style::Default },
		vsync_{ true },
		clear_color{ sf::Color::Black }
	{
	}
};
