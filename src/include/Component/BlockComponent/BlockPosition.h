
#pragma once

// λ�����
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
	/// ���غ����� ������
	/// </returns>
	/*[[nodiscard]] int x() const noexcept { return x_; }
	[[nodiscard]] int y() const noexcept { return y_; }*/

    /// <summary>
    /// translate
    /// </summary>
    /// <param name="dx">�ƶ�λ���ƶ�</param>
    /// <param name="dy">������λ���ƶ�</param>
    void translate(int dx, int dy) noexcept { x_ += dx; y_ += dy; }
};
