
#pragma once
#include<SFML/Graphics.hpp>

/// <summary>
/// 方块的捡拾的难易程度
/// </summary>
struct BlockDifficulty
{
	enum class Diffi
	{
		Hard=0,
		Medium,
		Easy,
	};
};