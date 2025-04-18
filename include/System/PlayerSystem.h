#pragma once
#include<SFML/Graphics.hpp>
#include<entt/entt.hpp>

#include"ChunkComponent/ChunkConfig.h"
#include"ComComponent/ComStata.h"
#include"PlayerComponent/Player.h"

namespace
{
	constexpr float player_a_x =-0.9;					// ˮƽ���ٶ�
	constexpr float player_a_y =-0.9;					// ��ֱ���ٶ�
	constexpr sf::Vector2f pos_player{ 0.f,0.f };			// ����λ��
	constexpr sf::Vector2f size_player(100.f, 100.f);	// �������
	constexpr float	thickness_player = 0.f;				// �߿�ֶ�
	constexpr sf::Color color_in(sf::Color::Blue);		// ����������ɫ	
	constexpr sf::Color color_out(sf::Color::Blue);		// ����������ɫ	
	constexpr sf::Vector2f v_{0.f,0.f};					// ����������ɫ	
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
	/// ע��ȫ�� esc
	/// </param>
	PlayerSystem(entt::registry& registry_out):
		registry_(registry_out)
	{}



public:
	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// CreatePeopleChunk - ��������ʵ��
	/// 
	/// </summary>
	/// 
	///
	void CreatePeopleChunk()
	{
		// ����ʵ�� //
		auto entity_ = registry_.create();

		// ���������� //
		BlockSquare player_block(
			size_player,
			thickness_player,
			color_in,
			color_out
		);

		// ���뷽�� //
		registry_.emplace<BlockSquare>(entity_, player_block);

		// λ�ü���ʵ�� //
		registry_.emplace<PlayerPosition>(entity_, pos_player);

		// ������ٶ�
		PlayerAcceleration a_(player_a_x,player_a_y);
		registry_.emplace<PlayerAcceleration>(entity_, a_);

		// �����ٶ� //
		registry_.emplace<PlayerSpeed>(entity_, v_);

		// ������ƶ���ǩ
		registry_.emplace<MoveStata>(entity_);

		// ��ײ 
		registry_.emplace<ComCollisionPlayer>(entity_);

		// ��ǰ��Ⱦ����
		registry_.emplace<PlayerFront>(entity_);
	}
};