
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

	// 窗口系统 //
	WindowVisitorSystem window_visitor(registry_, window_.get());

	// 玩家系统 //
	PlayerVisitorSystem player_visitor(registry_, window_.get());

	// 碰撞系统 //
	CollisionDetectionSystem collisystem(registry_);

	// 视图系统 //
	ViewSystem viewsystem_(registry_ ,window_.get());			

	// 移动系统 //
	MoveSystem movesystem_(registry_, window_.get());			

	// 渲染系统 //
	RenderSystem rendersystem_(registry_, window_.get());		

	// 模块系统 //
	ChunkSystem chunksystem_(registry_, window_.get());

	// 玩家系统 //
	PlayerSystem playersystem_(registry_);

	// 物理系统 //
	PhysicsSystem physicsystem_(registry_);

	// 分配系统检测 //
	DispatcherSystem dispatcherSystem_(registry_);	


	sf::Clock clock;

	chunksystem_.ChunkLoad();				// 区块加载
	playersystem_.CreatePeopleChunk();		// 任务加载
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
		viewsystem_.SetView();								// 设置视图
		rendersystem_.DrawPlayer();							// 绘制人物
		rendersystem_.DrawSquare();							// 绘制方块


		while (std::optional<sf::Event> e_ = window_->pollEvent())
		{
			dispatcherSystem_.DisPatch(
				*e_,
				window_visitor,
				player_visitor
				);
		}
		physicsystem_.UpdatePlayer(delta_time);				// 更新玩家位置
		collisystem.UpdatePlayer();						// 更新碰撞

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


