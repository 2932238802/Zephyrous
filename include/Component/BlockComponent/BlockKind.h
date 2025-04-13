
#pragma once
#include<iostream>
#include<string>
#include<string_view>
#include<SFML/Graphics.hpp>

enum class Kind
{
	Stone,
	Soil,
	Empty
};

struct BlockKind
{
	
	Kind kind_;

	BlockKind(Kind&& kind_out):
		kind_(kind_out)
	{
	}

	BlockKind(const Kind& kind_out) :
		kind_(kind_out)
	{
	}
};