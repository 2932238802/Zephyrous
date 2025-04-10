

#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>
#include<filesystem>

#include "Tool/Debug.h"   

struct WindowConfig
{
	/// <summary>
	/// mode_ - �ߴ�
	/// name_ - ��������
	/// style_  - ��Ļ
	/// vsync_ - ��ֱ
	/// clear_color - ˢ����ɫ
	/// </summary>
	sf::VideoMode mode_;
	std::string name_;
	uint32_t style_;
	bool vsync_;
	sf::Color clear_color;

	WindowConfig() = default;

	/// <summary>
	/// LoadData - ��������
	/// </summary>
	void LoadData()
	{
		// ���ļ� //
		std::ifstream read_file("windowconfig.json");

		try
		{
			if (!read_file.is_open())
			{
				DLOG("wrong in open json");
			}
		}
		catch(std::runtime_error& e_)
		{
			DLOG(e_.what());
		}

		// ��ȡ�ļ� ��json�� //
		nlohmann::json json_file;
		try {
			read_file >> json_file;
		}
		catch(nlohmann::json::parse_error & e_)
		{
			DLOG("wrong in parsing!");
		}

		// ��ȡ���ݵ����� // 
		try {
			// ��ȡ �߿� //
			auto& windowmode_ = json_file.at("windowmode");
			if (!windowmode_.contains("width") || !windowmode_.contains("height")) {
				DLOG("JSONȱ��width/height�ֶ�");
				return;
			}

			mode_.size.x = windowmode_.at("width").get<int>();
			mode_.size.y = windowmode_.at("height").get<int>();

			// ��ȡ���� //
			name_ = json_file.at("name").get<std::string>();

			// ��� //
			style_ = json_file.at("style").get<int>();

			// ������Ⱦ //
			vsync_ = json_file.at("vsync").get<bool>();

			// ��ɫ //
			auto& color = json_file.at("clear_color");
			clear_color = sf::Color(
				color.at("r").get<uint8_t>(),
				color.at("g").get<uint8_t>(),
				color.at("b").get<uint8_t>(),
				color.at("a").get<uint8_t>()
			);
		}
		// ������Χ //
		catch (nlohmann::json::out_of_range&)
		{
			DLOG("wrong in out of range��");
		}
		// ���ʹ��� //
		catch (nlohmann::json::type_error&)
		{
			DLOG("wrong in type��");
		}

	}
};
