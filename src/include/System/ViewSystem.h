
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
public:
	ViewSystem(entt::registry& registry_out):
		registry_(registry_out)
	{
	}

	void Init(ViewConfig&&config_)
	{
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
	void SetView()const
	{
		auto contain_windowruntime_entity = registry_.view<std::unique_ptr<WindowRuntime>>();
		for (auto entity_ : contain_windowruntime_entity)
		{
			auto& window_ = contain_windowruntime_entity.get<std::unique_ptr<WindowRuntime>>(entity_);
			
			if (window_ != nullptr)
			{
				window_->window_handle->setView(view_.view);
			}
		}
	}
};