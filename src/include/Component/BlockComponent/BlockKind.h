
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
	/// static Kind ToKind - static �������ʹ�� - ת���ַ���Ϊ����
	/// </summary>
	/// 
	/// <param name="str">��������</param>
	/// 
	/// <returns>����Kind</returns>
};