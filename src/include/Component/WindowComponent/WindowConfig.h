

#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>
#include<filesystem>

#include "Tool/Debug.h"   

struct WindowConfig
{
	/// <summary>
	/// mode_ - 尺寸
	/// name_ - 窗口名字
	/// style_  - 屏幕
	/// vsync_ - 垂直
	/// clear_color - 刷新颜色
	/// </summary>
	sf::VideoMode mode_;
	std::string name_;
	uint32_t style_;
	bool vsync_;
	sf::Color clear_color;

	WindowConfig() = default;

	/// <summary>
	/// LoadData - 加载数据
	/// </summary>
	void LoadData()
	{
		// 打开文件 //
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

		// 读取文件 到json库 //
		nlohmann::json json_file;
		try {
			read_file >> json_file;
		}
		catch(nlohmann::json::parse_error & e_)
		{
			DLOG("wrong in parsing!");
		}

		// 读取数据到本地 // 
		try {
			// 获取 高宽 //
			auto& windowmode_ = json_file.at("windowmode");
			if (!windowmode_.contains("width") || !windowmode_.contains("height")) {
				DLOG("JSON缺少width/height字段");
				return;
			}

			mode_.size.x = windowmode_.at("width").get<int>();
			mode_.size.y = windowmode_.at("height").get<int>();

			// 获取名字 //
			name_ = json_file.at("name").get<std::string>();

			// 风格 //
			style_ = json_file.at("style").get<int>();

			// 竖型渲染 //
			vsync_ = json_file.at("vsync").get<bool>();

			// 颜色 //
			auto& color = json_file.at("clear_color");
			clear_color = sf::Color(
				color.at("r").get<uint8_t>(),
				color.at("g").get<uint8_t>(),
				color.at("b").get<uint8_t>(),
				color.at("a").get<uint8_t>()
			);
		}
		// 超过范围 //
		catch (nlohmann::json::out_of_range&)
		{
			DLOG("wrong in out of range！");
		}
		// 类型错误 //
		catch (nlohmann::json::type_error&)
		{
			DLOG("wrong in type！");
		}

	}
};
