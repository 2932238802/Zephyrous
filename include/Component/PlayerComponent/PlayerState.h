#pragma once
#include<iostream>

struct PlayerState
{
	int hp_;
	int energe_;
	PlayerState(int hp, int energe) :hp_(hp), energe_(energe) {}

	/// <summary>
	/// AlterAttr - �ı�����
	/// </summary>
	/// <param name="alter_hp">�ı������</param>
	/// <param name="alter_energe">�ı������</param>
	void AlterAttr(int alter_hp, int alter_energe) noexcept
	{
		hp_ += alter_hp;
		energe_ += alter_energe;
	}

	/// <summary>
	/// hp,energe - ���ض�Ӧ���ԣ�����ֵ��������
	/// </summary>
	/// <returns>����</returns>
	[[nodiscard]] int hp() const noexcept { return hp_; }
	[[nodiscard]] int energe() const noexcept {return energe_;}
};