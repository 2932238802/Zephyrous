
#pragma once
#include<SFML/Graphics.hpp>
#include<entt/entt.hpp>

#include"BlockComponent/BlockPosition.h"
#include"BlockComponent/BlockSquare.h"
#include"WindowComponent/WindowRuntime.h"

#include"Tool/Debug.h"

/// <summary>
/// RenderSystem - �滭�����߼�
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
	/// UpdateSquare - ��Ⱦ����
	/// </summary>
	void DrawSquare()
	{
		// windowtunrime_all - ��ȡӵ������ //
		// block_position_square_all - BlockPosition, BlockSquare //
		auto windowruntime_all = register_.view<std::unique_ptr<WindowRuntime>>();
		auto block_position_square_all =
						register_.view<BlockPosition, BlockSquare>();
		
		// entity_ - ÿһ��ʵ�� block_position_square_all //
		for (auto entity_ : block_position_square_all)
		{
			// ��ȡÿһ��ʵ���ͼ�κ���״ //
			// square_.shape_.setPosition ������ //
			const auto& pos_ = block_position_square_all.get<BlockPosition>(entity_);
			auto& square_ = block_position_square_all.get<BlockSquare>(entity_);
			square_.shape_.setPosition({ pos_.x_, pos_.y_ });

			DLOG;

			// �滭 //
			if (!windowruntime_all.empty())
			{
				auto window_entity = *(windowruntime_all.begin());
				auto& window_ptr = windowruntime_all.get<std::unique_ptr<WindowRuntime>>(window_entity);
				window_ptr->window_handle->draw(square_.shape_);
			}
		}
	}

};