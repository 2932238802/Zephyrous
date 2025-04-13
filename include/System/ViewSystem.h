
#pragma once
#include<entt/entt.hpp>

#include"ViewComponent/ViewRuntime.h"
#include"WindowComponent/WindowRuntime.h"
#include"ViewComponent/ViewConfig.h"

class ViewSystem
{
private:
	ViewRuntime view_;
	entt::registry& registry_;
	std::shared_ptr<sf::RenderWindow> window_;
public:
	ViewSystem(entt::registry& registry_out,std:: shared_ptr<sf::RenderWindow> window_out):
		registry_(registry_out),
		window_(std::move(window_out))
	{
	}

	void Init(ViewConfig&config_)
	{
		/*std::cout << config_.rect_.size.x;
		std::cout << config_.rect_.size.y;
		std::cout << config_.size_.x;
		std::cout << config_.size_.y;
		std::cout << config_.center_.x;
		std::cout << config_.center_.y;*/
		view_.Init(
			config_.rect_,
			config_.size_,
			config_.center_
		);
	}

	/// <summary>
	/// SetView - 设置视图
	/// auto& window_ - 避免拷贝
	/// </summary>
	/// 
	/// <param name="registry_">
	/// registry_ - 全局唯一esc
	/// </param>
	void SetView()
	{
		if (window_)
		{
			window_->setView(view_.view);
		}
		else
		{
			DLOG("");
		}
	}
};