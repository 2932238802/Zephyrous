
#pragma once
#include<entt/entt.hpp>

#include"ViewComponent/ViewRuntime.h"
#include"WindowComponent/WindowRuntime.h"
#include"ViewComponent/ViewConfig.h"

class ViewSystem
{
	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// 
	/// </summary>
	private:
	ViewRuntime view_;
	entt::registry& registry_;
	sf::RenderWindow* window_;
	//////////////////////////////////////////////////////////////////////////




	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// 
	/// </summary>
	public:
	ViewSystem(entt::registry& registry_out,sf::RenderWindow* window_out):
		registry_(registry_out),
		window_(window_out)
	{
	}
	//////////////////////////////////////////////////////////////////////////




	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// 
	/// </summary>
	/// <param name="config_">
	/// 
	/// </param>
	public:
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
	//////////////////////////////////////////////////////////////////////////





	//////////////////////////////////////////////////////////////////////////
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
			auto player_position = registry_.view<PlayerPosition>();
			for (auto a : player_position)
			{
				auto& position_ = registry_.get<PlayerPosition>(a);
				view_.view.setCenter({position_.x,position_.y});
				window_->setView(view_.view);
			}
		}
		else
		{
			DLOG("window is nullptr");
		}
	}
	//////////////////////////////////////////////////////////////////////////
};