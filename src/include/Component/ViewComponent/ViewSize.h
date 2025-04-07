
#pragma once

struct ViewSize
{
	/// <summary>
	/// width_ - 宽度
	/// height_ - 高度
	/// </summary>
	int width_;
	int height_;
	ViewSize(int x = 0, int y = 0) noexcept : width_(x), height_(y) {}

	/// <summary>
	/// x,y
	/// </summary>
	/// <returns>
	/// 返回横坐标 纵坐标
	/// </returns>
	[[nodiscard]] int Width() const noexcept { return width_; }
	[[nodiscard]] int Height() const noexcept { return height_; }
};