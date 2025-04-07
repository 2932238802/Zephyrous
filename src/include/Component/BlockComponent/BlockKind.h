
#pragma once
#include<iostream>
#include<string>
#include<string_view>
#include<SFML/Graphics.hpp>

#include"Position.h"

struct BlockKind
{
	enum class Kind
	{
		Stone,
		Soil,
		Empty
	};

	/// <summary>
	/// static Kind ToKind - static 方便独立使用 - 转换字符串为类型
	/// </summary>
	/// 
	/// <param name="str">传入名字</param>
	/// 
	/// <returns>返回Kind</returns>
};