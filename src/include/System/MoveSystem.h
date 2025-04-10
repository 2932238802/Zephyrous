
#pragma once
#include<SFML/Graphics.hpp>
#include<entt/entt.hpp>

#include"BlockComponent/BlockMovement.h"
#include"BlockComponent/BlockPosition.h"

class MoveSystem
{
private:
	entt::registry&registry_;
	std::shared_ptr<sf::RenderWindow> window_;
public:
	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// MoveSystem - ��ȡesc
	/// </summary>
	/// <param name="registry_out"></param>
	MoveSystem(entt::registry& registry_out,std::shared_ptr<sf::RenderWindow> window_out):
		registry_(registry_out),
		window_(std::move(window_out))
	{
	}
	//////////////////////////////////////////////////////////////////////////




	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// Update - ��Ⱦ �˶� ����Ч��
	/// </summary>
	/// <param name="deltatime_"></param>
	void Update(float deltatime_)
	{
		// ��ȡ ���а���BlockMoveAble���Ե�ʵ��
		auto entities = registry_.view<BlockMoveAble,BlockPosition>();
		for (auto entity_ : entities)
		{
			auto& position_ = entities.get<BlockPosition>(entity_);
			position_.x_ += (deltatime_ * 1.0);
		}
	}
	//////////////////////////////////////////////////////////////////////////


private:

};