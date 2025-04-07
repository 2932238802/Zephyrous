
#include<iostream>
#include"System/MapSystem.h"
#include"System/PlayerSystem.h"
#include"System/WindowSystem.h"
#include"System/ViewSystem.h"

int main()
{
	// ȫ�� esc //
	entt::registry registry_;	

	// ���ô��� //
	WindowSystem system_;
	WindowConfig config_;
	config_.mode_ = sf::VideoMode({ 600,600 });
	config_.name_ = "Zephyrous";
	system_.Initialize(registry_, config_);
	
	// ������ͼ //
	ViewSystem viewsystem_;
	viewsystem_.SetView(registry_);

	// ��ѭ��
	while(true)
	{
		system_.Update(registry_);

		if (registry_.view<std::unique_ptr<WindowRuntime>>().size() == 0)
		{
			break;
		}
	}
	return 0;
}


