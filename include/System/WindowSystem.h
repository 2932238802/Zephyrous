

#pragma once
#include<entt/entt.hpp>

#include"WindowComponent/WindowConfigBuilder.h"
#include"WindowComponent/WindowRuntime.h"
#include"WindowComponent/WindowFactory.h"
#include"WindowComponent/WindowVisitor.h"

#include"System/RenderSystem.h"

#include"Tool/Debug.h"

class WindowSystem
{
private:
	WindowVisitor visitor_;
	entt::registry& registry_;
	WindowRuntime window_;



	/// <summary>
	/// Ĭ�Ϲ���
	/// </summary>
	public:
	WindowSystem(entt::registry& registry_out):
		visitor_(nullptr),
		registry_(registry_out)
	{}



	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// Initialize - ���� WindowRuntime 
	/// ���뵽 ȫ��Ψһ�� registry_ ����
	/// ��config_ ������
	/// </summary>
	/// 
	/// <param name="registry_">
	/// ȫ��Ψһ��entt
	/// </param>
	/// 
	/// <param name="config_">
	/// ���ò���
	/// </param>
	public:
	std::shared_ptr<sf::RenderWindow> Init(const WindowConfig& config_)
	{
		auto entt_ = registry_.create();
		window_ =
			WindowFactory::CreateWindow(
			config_.mode_,											// ��С //
			config_.name_											// ���� //
		);
		window_.clear_color = config_.clear_color;
		
		visitor_.SetWindow(window_.window_handle);			// ������
		return window_.window_handle;
	}
	//////////////////////////////////////////////////////////////////////////



	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// ����һ�� window ���� ��Ⱦһ��
	/// </summary>
	/// 
	/// <param name="registry_">
	/// registry_ - ȫ��Ψһenttr::egister
	/// </param>
	public:
	void Update(RenderSystem&  render)
	{
		window_.window_handle->clear(window_.clear_color);
		render.DrawSquare();
		while (std::optional<sf::Event>&& e_ = window_.window_handle->pollEvent()) {
			HandleEvent(*e_);												// ����ÿ���¼�
		}
		window_.window_handle->display();
	}
	//////////////////////////////////////////////////////////////////////////




	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// HandleEvent - �����������
	/// </summary>
	private: 
	void HandleEvent(const sf::Event& e_)
	{
		e_.visit(visitor_);
	}
	//////////////////////////////////////////////////////////////////////////

private:

};