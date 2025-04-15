

#pragma once
#include<entt/entt.hpp>

#include"WindowComponent/WindowConfigBuilder.h"
#include"WindowComponent/WindowRuntime.h"
#include"WindowComponent/WindowFactory.h"

#include"System/WindowVisitorSystem.h"
#include"System/RenderSystem.h"
#include"Tool/Debug.h"

class WindowManageSystem
{
private:
	entt::registry& registry_;
	WindowRuntime window_;
	WindowVisitorSystem visitor_;
	
	/// <summary>
	/// 默认构造
	/// </summary>
	public:
	WindowManageSystem(entt::registry& registry_out):
		visitor_(registry_out, nullptr),
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
		window_ =
			WindowFactory::CreateWindow(
			config_.mode_,								// 大小 //
			config_.name_								// 名字 //
		);
		window_.clear_color = config_.clear_color;
		return window_.window_handle;
	}
	//////////////////////////////////////////////////////////////////////////

};