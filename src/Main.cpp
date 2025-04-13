
#include<iostream>
#include<chrono>
#include"System/System.h"

int main()
{
	//////////////////////////////////////////////////////////////////////////
	// ȫ�� esc //
	entt::registry registry_;
	WindowSystem windowsystem_(registry_);			// ����ϵͳ
	std::shared_ptr<sf::RenderWindow> window_;
	{
		WindowConfig config_window;
		config_window.LoadData();
		window_ = windowsystem_.Init(config_window);
	}
	ViewSystem viewsystem_(registry_ ,window_);			// ��ͼϵͳ
	MoveSystem movesystem_(registry_, window_);			// �ƶ�ϵͳ	
	RenderSystem rendersystem_(registry_, window_);		// ��Ⱦϵͳ
	ChunkSysteem chunksystem_(registry_, window_);
	chunksystem_.ChunkLoad();
	{
		ViewConfig config_view;
		config_view.LoadData();
		viewsystem_.Init(config_view);
	}
	sf::Clock clock;
	



	//////////////////////////////////////////////////////////////////////////
	// ��ѭ�� //
	while(true)
	{
		float delta_time = clock.restart().asSeconds();
		viewsystem_.SetView();
		windowsystem_.Update(rendersystem_);
		movesystem_.Update(delta_time);

		if (!window_->isOpen())
		{
			registry_.clear();  // �������ʵ������
			std::cout << "��������ʵ�壡" << std::endl;
			break;
		}
	}
	//////////////////////////////////////////////////////////////////////////


	return 0;
}


