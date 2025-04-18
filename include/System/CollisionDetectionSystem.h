
#pragma once
#include<SFML/Graphics.hpp>
#include<entt/entt.hpp>

#include"ChunkComponent/ChunkConfig.h"
#include"PlayerComponent/Player.h"
#include"ComComponent/ComCollision.h"
/// <summary>
/// ��ײϵͳjiance
/// </summary>
class CollisionDetectionSystem
{
private:
	entt::registry & registry_;

	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// CollisionDetectionSystem Ĭ�Ϲ���
	/// ����ȫ��Ψһnett����
	/// </summary>
public:
	CollisionDetectionSystem(entt::registry& registry_out):
		registry_(registry_out)
	{
	}

	/// <summary>
	/// UpdateForPlayer - ���������ײ��ϵ 
	/// </summary>
	void UpdatePlayer()
	{
		// �������� //
		// chunk_contain ���ʵ�� //
		auto entities_chunk = registry_.view<BlockSquare,BlockPosition>();
		std::vector<entt::entity> chunk_contain(entities_chunk.begin(), entities_chunk.end());
		auto entity_player = registry_.view<
			PlayerPosition,
			PlayerSpeed,
			PlayerAcceleration,
			BlockSquare,
			ComCollisionPlayer
		>();
		
		// ������������λ�� //
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

			// �����ײ ��ô�ٶ�ȫ������
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