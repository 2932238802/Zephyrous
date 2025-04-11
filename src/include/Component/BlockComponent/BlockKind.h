
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
};