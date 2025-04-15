

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
	/// Ĭ�Ϲ���
	/// </summary>
	public:
	WindowManageSystem(entt::registry& registry_out):
		visitor_(registry_out, nullptr),
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
		window_ =
			WindowFactory::CreateWindow(
			config_.mode_,								// ��С //
			config_.name_								// ���� //
		);
		window_.clear_color = config_.clear_color;
		return window_.window_handle;
	}
	//////////////////////////////////////////////////////////////////////////

};