
#pragma once

// Î»ÖÃ×é¼þ
#pragma once
#include <utility>  
#include<SFML/Graphics.hpp>




//////////////////////////////////////////////////////////////////////////
/// <summary>
/// 
/// </summary>
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
};
//////////////////////////////////////////////////////////////////////////
