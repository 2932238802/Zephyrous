

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
	/// 默认构造
	/// </summary>
	public:
	WindowSystem(entt::registry& registry_out):
		visitor_(nullptr),
		registry_(registry_out)
	{}



	//////////////////////////////////////////////////////////////////////////
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
	public:
	std::shared_ptr<sf::RenderWindow> Init(const WindowConfig& config_)
	{
		auto entt_ = registry_.create();
		window_ =
			WindowFactory::CreateWindow(
			config_.mode_,											// 大小 //
			config_.name_											// 名字 //
		);
		window_.clear_color = config_.clear_color;
		
		visitor_.SetWindow(window_.window_handle);			// 监听器
		return window_.window_handle;
	}
	//////////////////////////////////////////////////////////////////////////



	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// 更新一次 window 窗口 渲染一次
	/// </summary>
	/// 
	/// <param name="registry_">
	/// registry_ - 全局唯一enttr::egister
	/// </param>
	public:
	void Update(RenderSystem&  render)
	{
		window_.window_handle->clear(window_.clear_color);
		render.DrawSquare();
		while (std::optional<sf::Event>&& e_ = window_.window_handle->pollEvent()) {
			HandleEvent(*e_);												// 处理每个事件
		}
		window_.window_handle->display();
	}
	//////////////////////////////////////////////////////////////////////////




	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// HandleEvent - 处理各种输入
	/// </summary>
	private: 
	void HandleEvent(const sf::Event& e_)
	{
		e_.visit(visitor_);
	}
	//////////////////////////////////////////////////////////////////////////

private:

};