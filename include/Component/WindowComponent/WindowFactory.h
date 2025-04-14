#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>

#include"WindowComponent/WindowRuntime.h"

struct WindowFactory
{
	/// <summary>
	/// ����������һ���µ� WindowRuntime ʵ��
	/// </summary>
	/// 
	/// <param name="mode_">
	/// ������Ƶģʽ
	/// </param>
	/// 
	/// <param name="title_">
	/// ���ڱ���
	/// </param>
	/// 
	/// <param name="clear_color_out">
	/// ���������ɫ
	/// </param>
	/// 
	/// <returns>
	/// ָ�� WindowRuntime��Ψһָ��
	/// </returns>
	static WindowRuntime CreateWindow(const sf::VideoMode& mode_, const std::string& title_, sf::Color clear_color_out = sf::Color::Black)
	{
		return WindowRuntime(mode_, title_, clear_color_out);
	}
};


//::Titlebar | sf::Style::Close