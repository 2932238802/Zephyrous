
#pragma once
#include<iostream>
#include<string>
#include<string_view>

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
	static Kind ToKind(std::string_view str)
	{
		if()
		/*switch (str.c)
		{
		case "st":
		{
			return Kind::Stone;
			break;
		}
		case "so":
		{
			return Kind::Soil;
			break;
		}
		default:
			return Kind::Empty;
			break;
		} */
	}
};