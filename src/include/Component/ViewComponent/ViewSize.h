
#pragma once

struct ViewSize
{
	/// <summary>
	/// width_ - ���
	/// height_ - �߶�
	/// </summary>
	int width_;
	int height_;
	ViewSize(int x = 0, int y = 0) noexcept : width_(x), height_(y) {}

	/// <summary>
	/// x,y
	/// </summary>
	/// <returns>
	/// ���غ����� ������
	/// </returns>
	[[nodiscard]] int Width() const noexcept { return width_; }
	[[nodiscard]] int Height() const noexcept { return height_; }
};