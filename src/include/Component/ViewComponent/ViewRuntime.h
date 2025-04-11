#pragma once
#include<SFML/Graphics.hpp>

struct ViewRuntime
{
	sf::View view;
	ViewRuntime() = default;
	void Init(const sf::FloatRect& rect_out, const sf::Vector2f& size_out, const sf::Vector2f& center_out) {
		// 1. ������ͼ���߼��ߴ磨���ǵ���Ϸ���緶Χ��
		view.setSize(size_out);

		// 3. �����ӿڣ������������ڣ�
		view.setViewport(rect_out);

		// 2. ��������ϵԭ�㣺�� (0,0) ӳ�䵽��������
		sf::Vector2f originOffset = center_out;		// center_outӦΪ (750,750)
		view.setCenter(center_out);				// ��ͼ���Ķ�׼��Ϸ�����е� (750,750)

		std::cout << "View Size: " << size_out.x << ", " << size_out.y << std::endl;
		std::cout << "View Center: " << center_out.x << ", " << center_out.y << std::endl;
	}
};