

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
public:
	/// <summary>
	/// Ĭ�Ϲ���
	/// </summary>
	WindowSystem(entt::registry& registry_out):
		visitor_(nullptr),
		registry_(registry_out)
	{}


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
	void Initialize(const WindowConfig& config_)
	{
		auto entt_ = registry_.create();
		std::unique_ptr<WindowRuntime> window_runtime = 
			WindowFactory::CreateWindow(
			config_.mode_,											// ��С //
			config_.name_											// ���� //
		);
		visitor_.SetWindow(window_runtime->window_handle.get());	// ������
		registry_.emplace<std::unique_ptr<WindowRuntime>>
			(entt_, std::move(window_runtime));						// ����entity //
	}


public:
	/// <summary>
	/// ����һ�� window ���� ��Ⱦһ��
	/// </summary>
	/// 
	/// <param name="registry_">
	/// registry_ - ȫ��Ψһenttr::egister
	/// </param>
	void Update(RenderSystem&  render)
	{
		// ��ȡ����WindowRuntime��ʵ�� //
		auto view_runtime = registry_.view<std::unique_ptr<WindowRuntime>>();		

		// ����һ�����еĴ��� һ����һ�� //
		for (auto entity_ : view_runtime)							
		{

			// ��entity_ �����ȡstd::unique_ptr<WindowRuntime> //
			auto& window_runtime = 
				view_runtime.get<std::unique_ptr<WindowRuntime>>(entity_);	

			// ��ȡ���ھ�� // 
			auto& window_ = window_runtime->window_handle;

			// ����Ѿ��ر� ֱ�Ӵݻ�entity // 
			if (!window_->isOpen())									
			{
				registry_.destroy(entity_);
				continue;
			}
			window_->clear(window_runtime->clear_color);

			DLOG;
			render.DrawSquare();
			DLOG;

			//////////////////////////////////////////////////////////////////////////
			// ��Ҫ����
			//////////////////////////////////////////////////////////////////////////
			while (std::optional<sf::Event>&& e_ = window_->pollEvent()) {
				HandleEvent(*e_);												// ����ÿ���¼�
			}
			window_->display();
		}
	}


private: 
	/// <summary>
	/// HandleEvent - �����������
	/// </summary>
	void HandleEvent(const sf::Event& e_)
	{
		e_.visit(visitor_);
	}

private:

};