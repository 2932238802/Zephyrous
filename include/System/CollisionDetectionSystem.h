
#pragma once
#include<SFML/Graphics.hpp>
#include<entt/entt.hpp>

#include"ChunkComponent/ChunkConfig.h"
#include"PlayerComponent/Player.h"
#include"ComComponent/ComCollision.h"
/// <summary>
/// 碰撞系统jiance
/// </summary>
class CollisionDetectionSystem
{
private:
	entt::registry & registry_;

	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// CollisionDetectionSystem 默认构造
	/// 传入全局唯一nett即可
	/// </summary>
public:
	CollisionDetectionSystem(entt::registry& registry_out):
		registry_(registry_out)
	{
	}

	/// <summary>
	/// UpdateForPlayer - 更新玩家碰撞体系 
	/// </summary>
	void UpdatePlayer()
	{
		// 存入数组 //
		// chunk_contain 存放实体 //
		auto entities_chunk = registry_.view<BlockSquare,BlockPosition>();
		std::vector<entt::entity> chunk_contain(entities_chunk.begin(), entities_chunk.end());
		auto entity_player = registry_.view<
			PlayerPosition,
			PlayerSpeed,
			PlayerAcceleration,
			BlockSquare,
			ComCollisionPlayer
		>();
		
		// 计算玩家面积和位置 //
		for (auto player_ : entity_player)
		{
			auto& position_player = registry_.get<PlayerPosition>(player_);
			auto& square_player = registry_.get<BlockSquare>(player_);
			auto& iscollision = registry_.get<ComCollisionPlayer>(player_);
			auto& player_v = registry_.get<PlayerSpeed>(player_);
			auto& player_a = registry_.get<PlayerAcceleration>(player_);


			for (int i = 0; i < chunk_contain.size(); i++)
			{
				auto& square_block = registry_.get<BlockSquare>(chunk_contain[i]);
				auto& position_block = registry_.get<BlockPosition>(chunk_contain[i]);

				bool overlap_x = (
					(
						position_player.x +
						square_player.shape_.getSize().x
					)
					<
					(
						position_block.x_
					)
					&&
					(
						position_player.x
					)
					>
					(
						position_block.x_ +
						square_block.shape_.getSize().x
						)
					);
				bool overlap_y = (
					(
						position_player.y +
						square_player.shape_.getSize().y
					)
					<
					(
						position_block.y_
					)
					&&
					(
						position_player.y
					)
					>
					(
						position_block.y_ +
						square_block.shape_.getSize().y
					)
					);
				iscollision.iscollision_ = (overlap_y && overlap_x);
			}

			// 如果碰撞 那么速度全部归零
			if (iscollision.iscollision_ == false)
			{
				player_v.speed_.x = 0;
				player_v.speed_.y = 0;
				player_a.a_x = 0;
				player_a.a_y = 0;
			}
		}
	}
};