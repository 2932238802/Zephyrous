

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
	/// 默认构造
	/// </summary>
	WindowSystem():
		visitor_(nullptr)
	{}

	/// <summary>
	/// Initialize - 配置 WindowRuntime 
	/// 放入到 全局唯一的 registry_ 里面
	/// 用config_ 来配置
	/// </summary>
	/// 
	/// <param name="registry_">
	/// 全局唯一的entt
	/// </param>
	/// 
	/// <param name="config_">
	/// 配置参数
	/// </param>
	void Initialize(entt::registry& registry_, const WindowConfig& config_)
	{
		auto entt_ = registry_.create();
		std::unique_ptr<WindowRuntime> window_runtime = 
			WindowFactory::CreateWindow(
			config_.mode_,											// 大小 //
			config_.name_											// 名字 //
		);
		visitor_.SetWindow(window_runtime->window_handle.get());	// 监听器
		registry_.emplace<std::unique_ptr<WindowRuntime>>
			(entt_, std::move(window_runtime));						// 放入entity //
	}


public:
	/// <summary>
	/// 更新一次 window 窗口 渲染一次
	/// </summary>
	/// 
	/// <param name="registry_">
	/// registry_ - 全局唯一enttr::egister
	/// </param>
	void Update(entt::registry& registry_)
	{
		auto view_runtime = registry_.view<WindowRuntime>();		// 获取WindowRuntime实体
		for (auto entity_ : view_runtime)							// 遍历一遍所有的窗口 一般是一个
		{
			auto& window_runtime = 
				view_runtime.get<WindowRuntime>(entity_);			// 从entity_ 里面获取实体
			auto& window_ = window_runtime.window_handle;			// 获取窗口句柄
			if (!window_->isOpen())									// 如果已经关闭 直接摧毁entity
			{
				registry_.destroy(entity_);
				MyDebug::Dprint();
				continue;
			}
			window_->clear(window_runtime.clear_color);
			//////////////////////////////////////////////////////////////////////////
			// 需要完善
			//////////////////////////////////////////////////////////////////////////
			while (std::optional<sf::Event>&& e_ = window_->pollEvent()) {
				HandleEvent(*e_);												// 处理每个事件
			}
			window_->display();
		}
	}

private: 
	/// <summary>
	/// HandleEvent - 处理各种输入
	/// </summary>
	void HandleEvent(const sf::Event& e_)
	{
		e_.visit(visitor_);
	}

private:

};