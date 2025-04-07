
#pragma once

// λ�����
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
	/// ���غ����� ������
	/// </returns>
    [[nodiscard]] int x() const noexcept { return x_; }
    [[nodiscard]] int y() const noexcept { return y_; }

    /// <summary>
    /// translate
    /// </summary>
    /// <param name="dx">�ƶ�λ���ƶ�</param>
    /// <param name="dy">������λ���ƶ�</param>
    void translate(int dx, int dy) noexcept { x_ += dx; y_ += dy; }
};
