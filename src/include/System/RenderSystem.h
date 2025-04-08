
#pragma once
#include<SFML/Graphics.hpp>
#include<entt/entt.hpp>

#include"BlockComponent/BlockPosition.h"
#include"BlockComponent/BlockSquare.h"
#include"WindowComponent/WindowRuntime.h"

#include"Tool/Debug.h"

/// <summary>
/// RenderSystem - 绘画处理逻辑
/// </summary>
class RenderSystem
{
private:
	entt::registry& register_;

public:
	RenderSystem(
		entt::registry& register_out
	):
		register_(register_out)
	{}

public:
	/// <summary>
	/// UpdateSquare - 渲染方块
	/// </summary>
	void DrawSquare()
	{
		// windowtunrime_all - 获取拥有属性 //
		// block_position_square_all - BlockPosition, BlockSquare //
		auto windowruntime_all = register_.view<std::unique_ptr<WindowRuntime>>();
		auto block_position_square_all =
						register_.view<BlockPosition, BlockSquare>();
		
		// entity_ - 每一个实体 block_position_square_all //
		for (auto entity_ : block_position_square_all)
		{
			// 获取每一个实体的图形和形状 //
			// square_.shape_.setPosition 并设置 //
			const auto& pos_ = block_position_square_all.get<BlockPosition>(entity_);
			auto& square_ = block_position_square_all.get<BlockSquare>(entity_);
			square_.shape_.setPosition({ pos_.x_, pos_.y_ });

			DLOG;

			// 绘画 //
			if (!windowruntime_all.empty())
			{
				auto window_entity = *(windowruntime_all.begin());
				auto& window_ptr = windowruntime_all.get<std::unique_ptr<WindowRuntime>>(window_entity);
				window_ptr->window_handle->draw(square_.shape_);
			}
		}
	}

};