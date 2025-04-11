#pragma once
#include<SFML/Graphics.hpp>
#include<fstream>
#include<nlohmann/json.hpp>

#include"Tool/Debug.h"

struct ViewConfig
{	
	sf::FloatRect rect_;
	sf::Vector2f size_;
	sf::Vector2f center_;




	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// LoadData - 加载数据
	/// </summary>
	void LoadData()
	{
		std::ifstream read_file("viewconfig.json");
		std::ifstream read_window_file("windowconfig.json");

		try
		{
			if (!read_file.is_open()|| !read_window_file.is_open())
			{
				DLOG("wrong in open json");
			}
		}
		catch (std::runtime_error& e_)
		{
			DLOG(e_.what());
		}

		// 读取文件 到json 参数 //
		nlohmann::json json_file;
		nlohmann::json json_window_file;
		try {
			read_file >> json_file;
			read_window_file >> json_window_file;
		}
		catch (nlohmann::json::parse_error& e_)
		{
			DLOG("wrong in parsing!");
		}

		// 解析一下 //
		try
		{
			auto& view_mode = json_file.at("view_mode");

			rect_ = {
				{
					view_mode.at("mode_left").get<float>(),
					view_mode.at("mode_top").get<float>()
				},
				{
					view_mode.at("mode_width").get<float>(),
					view_mode.at("mode_height").get<float>()
				}
			};

			auto& size_window = json_window_file.at("windowmode");
			float size_s_width = size_window.at("width").get<float>();
			float size_s_height = size_window.at("height").get<float>();

			size_ = { size_s_width,size_s_height };
			center_ = { 0.0f,0.0f };

			std::cout << "view size_x:" << size_.x << "view size_y:" << size_.y << std::endl;
			std::cout << "view center_x:" << center_.x << "view center_y" << center_.y << std::endl;
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
	//////////////////////////////////////////////////////////////////////////

};