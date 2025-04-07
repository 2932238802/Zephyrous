
#pragma once
#include"Tool/Debug.h"

#include<SFML/Graphics.hpp>
#include<iostream>

struct WindowVisitor
{
	sf::RenderWindow* window_;

	/// <summary>
	/// 
	/// </summary>
	/// 
	/// <param name="window">
	/// ��ʼ��window
	/// </param>
	WindowVisitor(sf::RenderWindow* window) :
		window_(window)
	{
	}

	/// <summary>
	/// ���ô���ָ��
	/// </summary>
	/// <param name="window">
	/// window - ���봰��ָ��
	/// </param>
	void SetWindow(sf::RenderWindow* window)
	{
		if (window != nullptr)
		{
			window_ = window;
		}
		else
		{
			MyDebug::Dprint();
		}
	}


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

	/// <summary>
	/// �رմ���
	/// </summary>
	/// 
	/// <param name="e_">
	/// e_ ������
	/// </param>
	void operator()(const sf::Event::Closed&)						
	{
		std::cout << "�û�����˹ر�" << std::endl;
		if (window_ != nullptr && window_->isOpen())
		{
			window_->close();
		}
	}

	/// <summary>
	/// �����
	/// </summary>
	/// 
	/// <param name="e_">
	/// e_ �������
	/// </param>
	void operator()(const sf::Event::MouseButtonPressed& )
	{
			std::cout << "�û�������" << std::endl;
	}

	/// <summary>
	/// ���̵��
	/// </summary>
	/// <param name="e_">
	/// e_ ���̵������
	/// </param>
	void operator()(const sf::Event::KeyPressed& e_)
	{
		(void)e_;
	}

	/// <summary>
	///  ģ���¼�����
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="_r"></param>
	template<class T>
	void operator()(T&& _r)											//�����¼�
	{}
};