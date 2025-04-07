#pragma once
#include<sfml/Graphics.hpp>
#include<iostream>

/// <summary>
/// WindowRuntime - ���ָ�� ˢ����ɫ �����Ƿ�ر�
/// </summary>
struct WindowRuntime
{
	std::unique_ptr<sf::RenderWindow> window_handle;
	sf::Color clear_color = sf::Color::Black;

	/// <summary>
	/// - ���캯������ʼ�����ھ������������
	/// </summary>
	/// 
	/// <param name="mode_">
	/// mode_ - ģ�ʹ�С
	/// </param>
	/// 
	/// <param name="title_">
	/// title_ - ���ڱ���
	/// </param>
	/// 
	/// <param name="clear_color_out">
	/// clear_color_out - ˢ����ɫ
	/// </param>
	WindowRuntime(const sf::VideoMode& mode_, const std::string& title_, sf::Color clear_color_out = sf::Color::Black)
		: 
		window_handle(std::make_unique<sf::RenderWindow>(mode_, title_, sf::Style::Titlebar | sf::Style::Close)),
		clear_color(clear_color_out)
	{
		if (window_handle)
		{
			window_handle->setFramerateLimit(60);
			window_handle->setKeyRepeatEnabled(false);			// ���ð����ظ�
			window_handle->setVerticalSyncEnabled(true);
			//////////////////////////////////////////////////////////////////////////
			//window_handle->setJoystickThreshold(0.5);			// �ֱ���ֵ
			//////////////////////////////////////////////////////////////////////////
		}
	}

	/// <summary>
	/// ��������
	/// </summary>
	WindowRuntime() = default;
	WindowRuntime(const WindowRuntime&) = delete;
	WindowRuntime& operator=(const WindowRuntime&) = delete;
	WindowRuntime(WindowRuntime&&) noexcept = default;
	WindowRuntime& operator=(WindowRuntime&&) noexcept = default;
};

