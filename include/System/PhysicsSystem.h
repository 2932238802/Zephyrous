
#pragma once
#include<SFML/Graphics.hpp>
#include<entt/entt.hpp>

#include"ComComponent/ComStata.h"
#include"PlayerComponent/Player.h"

namespace
{
	constexpr float friction_ = 0.8f;
	constexpr float min_acceleration = 0.01f;
	constexpr float max_speed = 30.0f;
	constexpr float min_speed = 1.f;
}

class PhysicsSystem
{
private: entt::registry& registry_;

public: 
	PhysicsSystem(entt::registry& registry_out):
		registry_(registry_out)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// Update 更新人物移动
	/// </summary>
	void UpdatePlayer(float time_)
	{
		auto player_ = registry_.view<
			MoveStata, 
			PlayerPosition,
			PlayerAcceleration,
			PlayerSpeed
		>();
		for (auto && [
			entity_,
			player_position, 
			player_acceleration,
			player_speed
			]: player_.each())
		{
			// 更新速度: v = v + a * t
			player_speed.speed_.x += player_acceleration.a_ * time_;

			// 速度限制 //
			if (player_speed.speed_.x > max_speed) {
				player_speed.speed_.x = max_speed;
			}
			else if (player_speed.speed_.x < -max_speed) {
				player_speed.speed_.x = -max_speed;
			}


			// 更新位置: x = x + v * t
			player_position.x += player_speed.speed_.x * time_;

			// 应用摩擦力，逐渐减少速度
			player_speed.speed_.x *= friction_;

			// 检查并设置速度的最小阈值
			if (std::abs(player_speed.speed_.x) < min_speed) {
				player_speed.speed_.x = 0.0f;
			}

			// 重置加速度
			player_acceleration.a_ = 0.0f;
		}
	}
	//////////////////////////////////////////////////////////////////////////


};