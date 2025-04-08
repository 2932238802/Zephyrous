
#pragma once

// 位置组件
#pragma once
#include <utility>  
#include<SFML/Graphics.hpp>

struct BlockPosition
{
    float x_;
    float y_;
    BlockPosition(float x = 0, float y = 0) noexcept : x_(x), y_(y) {}
    BlockPosition(BlockPosition&& other) noexcept
    {
        x_ = other.x_;
        y_ = other.y_;
    }

    BlockPosition(const BlockPosition& other)
    {
        x_ = other.x_;
        y_ = other.y_;
    }

    sf::Vector2f GetPosition()
    {
        return { x_,y_ };
    }
    
	/// <summary>
    /// x,y
    /// </summary>
	/// <returns>
	/// 返回横坐标 纵坐标
	/// </returns>
	/*[[nodiscard]] int x() const noexcept { return x_; }
	[[nodiscard]] int y() const noexcept { return y_; }*/

    /// <summary>
    /// translate
    /// </summary>
    /// <param name="dx">移动位置移动</param>
    /// <param name="dy">纵坐标位置移动</param>
    void translate(int dx, int dy) noexcept { x_ += dx; y_ += dy; }
};
