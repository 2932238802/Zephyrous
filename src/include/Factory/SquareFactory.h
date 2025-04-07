


#pragma once
#include<SFML/Graphics.hpp>

#include"BlockComponent/BlockSquare.h"
#include"BlockComponent/BlockPosition.h"

class SquareFactory
{
public:
	/// <summary>
	/// 
	/// </summary>
	/// <param name="square_">
	/// square_ - ·½¿é
	/// </param>
	/// 
	/// <param name="pos_">
	/// pos_ - Î»ÖÃ
	/// </param>
	/// 
	/// <param name="size_">
	/// size_ - ³ß´ç
	/// </param>
	/// 
	/// <param name="thickness_">
	/// thickness_ - ºñ¶È
	/// </param>
	void SetSquare(
		BlockSquare&square_,
		BlockPosition& pos_,
		sf::Vector2f size_,
		float thickness_
	)
	{
		square_.shape_.setPosition(pos_.GetPosition());
		square_.shape_.setSize(size_);
		square_.shape_.setFillColor(square_.color_in);
		square_.shape_.setOutlineColor(square_.color_out);
		square_.shape_.setOutlineThickness(thickness_);
	}
};