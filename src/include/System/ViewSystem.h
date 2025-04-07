
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
	/// SetView - ������ͼ
	/// auto& window_ - ���⿽��
	/// </summary>
	/// 
	/// <param name="registry_">
	/// registry_ - ȫ��Ψһesc
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