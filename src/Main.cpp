
#include<iostream>
#include<chrono>
#include"System/System.h"

int main()
{
	//////////////////////////////////////////////////////////////////////////
	// 全局 esc //
	entt::registry registry_;
	WindowManageSystem windowsystem_(registry_);			// 窗口系统
	std::shared_ptr<sf::RenderWindow> window_;
	{
		WindowConfig config_window;
		config_window.LoadData();
		window_ = windowsystem_.Init(config_window);
	}

	WindowVisitorSystem window_visitor(registry_, window_.get());
	PlayerVisitorSystem player_visitor(registry_, window_.get());
	ViewSystem viewsystem_(registry_ ,window_);			// 视图系统
	MoveSystem movesystem_(registry_, window_);			// 移动系统	
	RenderSystem rendersystem_(registry_, window_);		// 渲染系统
	ChunkSystem chunksystem_(registry_, window_);
	PlayerSystem playersystem_(registry_);
	PhysicsSystem physicsystem_(registry_);
	DispatcherSystem dispatcherSystem_(registry_);		
	sf::Clock clock;

	chunksystem_.ChunkLoad();
	playersystem_.CreatePeopleChunk();
	{
		ViewConfig config_view;
		config_view.LoadData();
		viewsystem_.Init(config_view);
	}

	//////////////////////////////////////////////////////////////////////////
	// 主循环 //
	while (true) {
		float delta_time = clock.restart().asSeconds();
		window_->clear();
		viewsystem_.SetView();
		rendersystem_.DrawPlayer();
		rendersystem_.DrawSquare();

		while (std::optional<sf::Event> e_ = window_->pollEvent())
		{
			dispatcherSystem_.DisPatch(
				*e_,
				window_visitor,
				player_visitor
				);
		}

		physicsystem_.UpdatePlayer(delta_time);

		window_->display();
		if (!window_->isOpen()) {
			registry_.clear();  // 清除所有实体和组件
			std::cout << "清理所有实体！" << std::endl;
			break;
		}
	}
	//////////////////////////////////////////////////////////////////////////


	return 0;
}


