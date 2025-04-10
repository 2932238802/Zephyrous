
#include<iostream>
#include<chrono>

#include"System/System.h"

int main()
{
	//////////////////////////////////////////////////////////////////////////
	// 全局 esc //
	entt::registry registry_;
	WindowSystem windowsystemsystem_(registry_);			// 窗口系统
	std::shared_ptr<sf::RenderWindow> window_;

		WindowConfig config_window;
		config_window.LoadData();
		window_ = windowsystemsystem_.Init(config_window);

	ViewSystem viewsystem_(registry_ ,window_);			// 视图系统
	CreateSystem createsystem_(registry_, window_);		// 模块系统
	MoveSystem movesystem_(registry_, window_);			// 移动系统	
	RenderSystem rendersystem_(registry_, window_);		// 渲染系统

		ViewConfig config_view;
		config_view.LoadData();
		viewsystem_.Init(config_view);

	sf::Clock clock;


	//////////////////////////////////////////////////////////////////////////
	



	//////////////////////////////////////////////////////////////////////////
	// 设置视图 //
	viewsystem_.SetView();
	//////////////////////////////////////////////////////////////////////////

	
	
	//////////////////////////////////////////////////////////////////////////
	// 模块 - 前置工作 //
	createsystem_.CreateSquare(
		{0.f,0.f},
		{ 50.f,50.f },
		2.0f,
		sf::Color::White,
		sf::Color::White
	);
	//////////////////////////////////////////////////////////////////////////


	
	
	//////////////////////////////////////////////////////////////////////////
	// 主循环 //
	while(true)
	{
		float delta_time = clock.restart().asSeconds();
		windowsystemsystem_.Update(rendersystem_);
		movesystem_.Update(delta_time);

		if (!window_->isOpen())
		{
			registry_.clear();  // 清除所有实体和组件
			std::cout << "清理所有实体！" << std::endl;
			break;
		}
	}
	//////////////////////////////////////////////////////////////////////////


	return 0;
}


