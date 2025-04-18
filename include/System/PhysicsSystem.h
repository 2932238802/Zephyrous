
#pragma once
#include<SFML/Graphics.hpp>
#include<entt/entt.hpp>

#include"ComComponent/ComStata.h"
#include"PlayerComponent/Player.h"

namespace
{
	constexpr float friction_ = 0.8f;					// Ħ������
	constexpr float min_acceleration = 0.01f;			// ˮƽ���ٶ�
	constexpr float min_acceleration_y = 0.01f;			// ���µļ��ٶ� �������ٶ�
	constexpr float max_speed = 100.0f;					// ����ٶ�
	constexpr float min_speed = 1.f;					// ��С�ٶ�
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
	/// Update ���������ƶ�
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
			// �����ٶ�: v = v + a * t
			player_speed.speed_.x += player_acceleration.a_x * time_;

			// �ٶ����� //
			if (player_speed.speed_.x > max_speed) {
				player_speed.speed_.x = max_speed;
			}
			else if (player_speed.speed_.x < -max_speed) {
				player_speed.speed_.x = -max_speed;
			}


			// ����λ��: x = x + v * t
			player_position.x += player_speed.speed_.x * time_;

			// Ӧ��Ħ�������𽥼����ٶ�
			player_speed.speed_.x *= friction_;

			// ��鲢�����ٶȵ���С��ֵ
			if (std::abs(player_speed.speed_.x) < min_speed) {
				player_speed.speed_.x = 0.0f;
			}

			// ���ü��ٶ�
			player_acceleration.a_x = 0.0f;
		}
	}
	//////////////////////////////////////////////////////////////////////////


};