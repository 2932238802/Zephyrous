
#pragma once
#include<SFML/Graphics.hpp>

/// <summary>
/// 方块的捡拾的难易程度
/// </summary>
/// 
/// 
enum class Diffi
{
	Hard = 0,
		Medium,
		Easy,
};
struct BlockDifficulty
{
	
	Diffi diffi_;
};