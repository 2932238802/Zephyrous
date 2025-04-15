
#pragma once
#include<SFML/Graphics.hpp>
#include<entt/entt.hpp>

#include"ComComponent/ComStata.h"
#include"PlayerComponent/Player.h"

class PhysicsSystem
{
private: entt::registry& registry_;

public: 
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
			// v = v + at; //
			// x = v * t + 1/2 * a * t^2 //
			player_position.x =
				player_speed.speed_.x * time_ +
				0.5 * player_acceleration.a_ * time_ * time_;
		}
	}
	//////////////////////////////////////////////////////////////////////////
	


public:


private:

};