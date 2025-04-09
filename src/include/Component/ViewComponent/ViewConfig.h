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

	void LoadData()
	{
		std::ifstream read_file("viewconfig.json");

		try
		{
			if (!read_file.is_open())
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
		try {
			read_file >> json_file;
		}
		catch (nlohmann::json::parse_error& e_)
		{
			DLOG("wrong in parsing!");
		}

		// 解析一下 //
		try
		{
			auto& view_mode = json_file.at("view_mode");
			rect_.size.x = view_mode.at("width").get<float>();
			rect_.size.y = view_mode.at("height").get<float>();
			rect_.position.x = view_mode.at("left").get<float>();
			rect_.position.y = view_mode.at("top").get<float>();
			size_ = rect_.size;
			center_ = { rect_.size.x / 2.0f , rect_.size.y / 2.0f };
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