
#include<iostream>
#include"System/System.h"


int main()
{
	// 全局 esc //
	entt::registry registry_;
	WindowSystem windowsystemsystem_(registry_);
	ViewSystem viewsystem_(registry_);
	CreateSystem createsystem_(registry_);

	// 配置窗口 //
	{
		WindowConfig config_;
		config_.mode_ = sf::VideoMode({ 600,600 });
		config_.name_ = "Zephyrous";
		windowsystemsystem_.Initialize(config_);
	}

	// 设置视图 //
	viewsystem_.SetView();

	// 渲染逻辑 - 前置工作 //
	createsystem_.CreateSquare(
		{50.f,50.f},
		{ 50.f,50.f },
		2.0f,
		sf::Color::White,
		sf::Color::White
	);

	// 渲染逻辑 - 绘制 //
	RenderSystem rendersystem_(registry_);

	// 主循环 //
	while(true)
	{
		windowsystemsystem_.Update(rendersystem_);

		if (registry_.view<std::unique_ptr<WindowRuntime>>().size() == 0)
		{
			registry_.clear();  // 清除所有实体和组件
			break;
		}
	}


	return 0;
}


