
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
	/// static Kind ToKind - static �������ʹ�� - ת���ַ���Ϊ����
	/// </summary>
	/// 
	/// <param name="str">��������</param>
	/// 
	/// <returns>����Kind</returns>
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