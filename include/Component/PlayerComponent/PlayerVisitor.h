
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
/// PlayerVisitor - �����������
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
	/// ��ʼ��window
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
	/// ���ô���ָ��
	/// </summary>
	/// 
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
			DLOG("wrong in window(is nullptr!)");
		}
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
		// ������� Ҫ���ٶȵ�
		switch (e_.code)
		{
			// ���� //
		case (key_t::W):
		{
			std::cout << "��Ծ ��δ��ʵ��!" << std::endl;
			break;
		}
		// ���� //
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
		// ���� //
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
		// ���� //
		case (key_t::S):
		{
			std::cout << "���� ��δ��ʵ��" << std::endl;
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
	///  ģ���¼�����
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="_r"></param>
	template<class T>
	void operator()(T&& _r)											//�����¼�
	{
	}
	//////////////////////////////////////////////////////////////////////////
};