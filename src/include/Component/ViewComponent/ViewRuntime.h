#pragma once
#include<SFML/Graphics.hpp>

struct ViewRuntime
{
	sf::View view;
	ViewRuntime() = default;
	void Init(const sf::FloatRect& rect_out, const sf::Vector2f& size_out, const sf::Vector2f& center_out) {
		// 1. 设置视图的逻辑尺寸（覆盖的游戏世界范围）
		view.setSize(size_out);

		// 3. 设置视口（覆盖整个窗口）
		view.setViewport(rect_out);

		// 2. 调整坐标系原点：将 (0,0) 映射到窗口中心
		sf::Vector2f originOffset = center_out;		// center_out应为 (750,750)
		view.setCenter(center_out);				// 视图中心对准游戏世界中的 (750,750)

		std::cout << "View Size: " << size_out.x << ", " << size_out.y << std::endl;
		std::cout << "View Center: " << center_out.x << ", " << center_out.y << std::endl;
	}
};