#pragma once
#include<SFML/Graphics.hpp>
#include<entt/entt.hpp>

#include"ChunkComponent/ChunkConfig.h"
#include"ComComponent/ComStata.h"
#include"PlayerComponent/Player.h"

namespace
{
	constexpr float player_a_x =-0.9;					// 水平加速度
	constexpr float player_a_y =-0.9;					// 竖直加速度
	constexpr sf::Vector2f pos_player{ 0.f,0.f };			// 人物位置
	constexpr sf::Vector2f size_player(100.f, 100.f);	// 人物体积
	constexpr float	thickness_player = 0.f;				// 边框粗度
	constexpr sf::Color color_in(sf::Color::Blue);		// 人物内置颜色	
	constexpr sf::Color color_out(sf::Color::Blue);		// 人物外置颜色	
	constexpr sf::Vector2f v_{0.f,0.f};					// 人物外置颜色	
}

class PlayerSystem
{
private: entt::registry& registry_;

public:
	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// 
	/// </summary>
	/// <param name="registry_out">
	/// 注册全局 esc
	/// </param>
	PlayerSystem(entt::registry& registry_out):
		registry_(registry_out)
	{}



public:
	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// CreatePeopleChunk - 创造人物实体
	/// 
	/// </summary>
	/// 
	///
	void CreatePeopleChunk()
	{
		// 创造实体 //
		auto entity_ = registry_.create();

		// 创造物理方块 //
		BlockSquare player_block(
			size_player,
			thickness_player,
			color_in,
			color_out
		);

		// 加入方块 //
		registry_.emplace<BlockSquare>(entity_, player_block);

		// 位置加入实体 //
		registry_.emplace<PlayerPosition>(entity_, pos_player);

		// 加入加速度
		PlayerAcceleration a_(player_a_x,player_a_y);
		registry_.emplace<PlayerAcceleration>(entity_, a_);

		// 加入速度 //
		registry_.emplace<PlayerSpeed>(entity_, v_);

		// 加入可移动标签
		registry_.emplace<MoveStata>(entity_);

		// 碰撞 
		registry_.emplace<ComCollisionPlayer>(entity_);

		// 提前渲染区块
		registry_.emplace<PlayerFront>(entity_);
	}
};