
#include<iostream>
#include<chrono>

#include"System/System.h"

int main()
{
	//////////////////////////////////////////////////////////////////////////
	// ȫ�� esc //
	entt::registry registry_;
	WindowSystem windowsystemsystem_(registry_);			// ����ϵͳ
	std::shared_ptr<sf::RenderWindow> window_;

		WindowConfig config_window;
		config_window.LoadData();
		window_ = windowsystemsystem_.Init(config_window);

	ViewSystem viewsystem_(registry_ ,window_);			// ��ͼϵͳ
	CreateSystem createsystem_(registry_, window_);		// ģ��ϵͳ
	MoveSystem movesystem_(registry_, window_);			// �ƶ�ϵͳ	
	RenderSystem rendersystem_(registry_, window_);		// ��Ⱦϵͳ

		ViewConfig config_view;
		config_view.LoadData();
		viewsystem_.Init(config_view);

	sf::Clock clock;


	//////////////////////////////////////////////////////////////////////////
	



	//////////////////////////////////////////////////////////////////////////
	// ������ͼ //
	viewsystem_.SetView();
	//////////////////////////////////////////////////////////////////////////

	
	
	//////////////////////////////////////////////////////////////////////////
	// ģ�� - ǰ�ù��� //
	createsystem_.CreateSquare(
		{0.f,0.f},
		{ 50.f,50.f },
		2.0f,
		sf::Color::White,
		sf::Color::White
	);
	//////////////////////////////////////////////////////////////////////////


	
	
	//////////////////////////////////////////////////////////////////////////
	// ��ѭ�� //
	while(true)
	{
		float delta_time = clock.restart().asSeconds();
		windowsystemsystem_.Update(rendersystem_);
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


