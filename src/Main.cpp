
#include<iostream>
#include"System/System.h"


int main()
{
	// ȫ�� esc //
	entt::registry registry_;
	WindowSystem windowsystemsystem_(registry_);
	ViewSystem viewsystem_(registry_);
	CreateSystem createsystem_(registry_);

	// ���ô��� //
	{
		WindowConfig config_;
		config_.mode_ = sf::VideoMode({ 600,600 });
		config_.name_ = "Zephyrous";
		windowsystemsystem_.Initialize(config_);
	}

	// ������ͼ //
	viewsystem_.SetView();

	// ��Ⱦ�߼� - ǰ�ù��� //
	createsystem_.CreateSquare(
		{50.f,50.f},
		{ 50.f,50.f },
		2.0f,
		sf::Color::White,
		sf::Color::White
	);

	// ��Ⱦ�߼� - ���� //
	RenderSystem rendersystem_(registry_);

	// ��ѭ�� //
	while(true)
	{
		windowsystemsystem_.Update(rendersystem_);

		if (registry_.view<std::unique_ptr<WindowRuntime>>().size() == 0)
		{
			registry_.clear();  // �������ʵ������
			break;
		}
	}


	return 0;
}


