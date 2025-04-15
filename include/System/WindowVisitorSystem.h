
#pragma once
#include"Tool/Debug.h"

#include<SFML/Graphics.hpp>
#include<entt/entt.hpp>
#include<iostream>

/// <summary>
/// WindowVisitor - �����������
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
	/// ��ʼ��window
	/// </param>
	WindowVisitor(sf::RenderWindow* window , entt::registry& registry_out) :
		window_(window),
		registry_(registry_out)
	{
	}
	//////////////////////////////////////////////////////////////////////////




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
	//////////////////////////////////////////////////////////////////////////




	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// �����
	/// </summary>
	/// 
	/// <param name="e_">
	/// e_ �������
	/// </param>
	void operator()(const sf::Event::MouseButtonPressed& e_)
	{
			std::cout << "�û�������" << std::endl;
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
	/// ���̵��
	/// </summary>
	/// <param name="e_">
	/// e_ ���̵������
	/// </param>
	void operator()(const sf::Event::KeyPressed& e_)
	{
		(void)e_;
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
	{}
	//////////////////////////////////////////////////////////////////////////
};