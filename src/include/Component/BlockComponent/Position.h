
#pragma once

// 位置组件
#pragma once
#include <utility>  

struct Position
{
	int x_;
	int y_;
    Position(int x = 0, int y = 0) noexcept : x_(x), y_(y) {}
    Position(Position&& other) noexcept
        : x_(std::exchange(other.x_, 0)),
        y_(std::exchange(other.y_, 0)) {
    }
    
	/// <summary>
    /// x,y
    /// </summary>
	/// <returns>
	/// 返回横坐标 纵坐标
	/// </returns>
    [[nodiscard]] int x() const noexcept { return x_; }
    [[nodiscard]] int y() const noexcept { return y_; }

    /// <summary>
    /// translate
    /// </summary>
    /// <param name="dx">移动位置移动</param>
    /// <param name="dy">纵坐标位置移动</param>
    void translate(int dx, int dy) noexcept { x_ += dx; y_ += dy; }
};
