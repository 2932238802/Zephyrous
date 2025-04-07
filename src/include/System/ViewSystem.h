
#pragma once
#include<entt/entt.hpp>

#include"ViewComponent/ViewRuntime.h"
#include"WindowComponent/WindowRuntime.h"


class ViewSystem
{
private:
	ViewRuntime view_;

public:

	/// <summary>
	/// SetView - 设置视图
	/// auto& window_ - 避免拷贝
	/// </summary>
	/// 
	/// <param name="registry_">
	/// registry_ - 全局唯一esc
	/// </param>3
	void SetView(entt::registry& registry_)const
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