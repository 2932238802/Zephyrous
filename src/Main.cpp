
#include<iostream>
#include"System/MapSystem.h"
#include"System/PlayerSystem.h"
#include"System/WindowSystem.h"

// test //
int main()
{
	entt::registry registry_;				
	WindowConfig config_;
	config_.mode_ = sf::VideoMode({ 600,600 });
	config_.name_ = "Zephyrous";
	WindowSystem system_;
	system_.Initialize(registry_, config_);

	while(true)
	{
		system_.Update(registry_);
		if (registry_.view<WindowRuntime>().size() == 0)
		{
			break;
		}
	}
	return 0;
}


