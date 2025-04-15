#pragma once
#include<iostream>

struct PlayerState
{
	int hp_;
	int energe_;
	PlayerState(int hp, int energe) :hp_(hp), energe_(energe) {}

	/// <summary>
	/// AlterAttr - 改变属性
	/// </summary>
	/// <param name="alter_hp">改变的生命</param>
	/// <param name="alter_energe">改变的能量</param>
	void AlterAttr(int alter_hp, int alter_energe) noexcept
	{
		hp_ += alter_hp;
		energe_ += alter_energe;
	}

	/// <summary>
	/// hp,energe - 返回对应属性（生命值，精力）
	/// </summary>
	/// <returns>属性</returns>
	[[nodiscard]] int hp() const noexcept { return hp_; }
	[[nodiscard]] int energe() const noexcept {return energe_;}
};