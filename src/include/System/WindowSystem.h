

#pragma once
#include<entt/entt.hpp>

#include"WindowComponent/WindowConfigBuilder.h"
#include"WindowComponent/WindowRuntime.h"
#include"WindowComponent/WindowFactory.h"
#include"WindowComponent/WindowVisitor.h"

#include"Tool/Debug.h"

class WindowSystem
{
private:
	WindowVisitor visitor_;

public:
	/// <summary>
	/// Ĭ�Ϲ���
	/// </summary>
	WindowSystem():
		visitor_(nullptr)
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
	void Initialize(entt::registry& registry_, const WindowConfig& config_)
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
	void Update(entt::registry& registry_)
	{
		auto view_runtime = registry_.view<WindowRuntime>();		// ��ȡWindowRuntimeʵ��
		for (auto entity_ : view_runtime)							// ����һ�����еĴ��� һ����һ��
		{
			auto& window_runtime = 
				view_runtime.get<WindowRuntime>(entity_);			// ��entity_ �����ȡʵ��
			auto& window_ = window_runtime.window_handle;			// ��ȡ���ھ��
			if (!window_->isOpen())									// ����Ѿ��ر� ֱ�Ӵݻ�entity
			{
				registry_.destroy(entity_);
				MyDebug::Dprint();
				continue;
			}
			window_->clear(window_runtime.clear_color);
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