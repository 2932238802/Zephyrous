
#include<iostream>
#include<chrono>
#include"System/System.h"

int main()
{
	//////////////////////////////////////////////////////////////////////////
	// ȫ�� esc //
	entt::registry registry_;
	WindowManageSystem windowsystem_(registry_);			// ����ϵͳ
	std::shared_ptr<sf::RenderWindow> window_;
	{
		WindowConfig config_window;
		config_window.LoadData();
		window_ = windowsystem_.Init(config_window);
	}

	// ����ϵͳ //
	WindowVisitorSystem window_visitor(registry_, window_.get());

	// ���ϵͳ //
	PlayerVisitorSystem player_visitor(registry_, window_.get());

	// ��ײϵͳ //
	CollisionDetectionSystem collisystem(registry_);

	// ��ͼϵͳ //
	ViewSystem viewsystem_(registry_ ,window_.get());			

	// �ƶ�ϵͳ //
	MoveSystem movesystem_(registry_, window_.get());			

	// ��Ⱦϵͳ //
	RenderSystem rendersystem_(registry_, window_.get());		

	// ģ��ϵͳ //
	ChunkSystem chunksystem_(registry_, window_.get());

	// ���ϵͳ //
	PlayerSystem playersystem_(registry_);

	// ����ϵͳ //
	PhysicsSystem physicsystem_(registry_);

	// ����ϵͳ��� //
	DispatcherSystem dispatcherSystem_(registry_);	


	sf::Clock clock;

	chunksystem_.ChunkLoad();				// �������
	playersystem_.CreatePeopleChunk();		// �������
	{
		ViewConfig config_view;
		config_view.LoadData();
		viewsystem_.Init(config_view);
	}

	//////////////////////////////////////////////////////////////////////////
	// ��ѭ�� //
	while (true) {
		float delta_time = clock.restart().asSeconds();
		window_->clear();
		viewsystem_.SetView();								// ������ͼ
		rendersystem_.DrawPlayer();							// ��������
		rendersystem_.DrawSquare();							// ���Ʒ���


		while (std::optional<sf::Event> e_ = window_->pollEvent())
		{
			dispatcherSystem_.DisPatch(
				*e_,
				window_visitor,
				player_visitor
				);
		}
		physicsystem_.UpdatePlayer(delta_time);				// �������λ��
		collisystem.UpdatePlayer();						// ������ײ

		window_->display();
		if (!window_->isOpen()) {
			registry_.clear();  // �������ʵ������
			std::cout << "��������ʵ�壡" << std::endl;
			break;
		}
	}
	//////////////////////////////////////////////////////////////////////////


	return 0;
}


