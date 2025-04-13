#pragma once

#include "WindowConfig.h" 

#include <string>
#include <utility> 
#include<SFML/Graphics.hpp>


class WindowConfigBuilder
{
	WindowConfig config_;
public:
	WindowConfigBuilder() = default;

	/// <summary>
	/// SetResolution 设置高宽
	/// </summary>
	/// <param name="width">
	/// 宽度
	/// </param>
	/// 
	/// <param name="height">
	/// 高度
	/// </param>
	/// 
	/// <returns>
	/// 用于链式初始化
	/// </returns>
	WindowConfigBuilder& SetResolution(unsigned int width, unsigned int height)
	{
		config_.mode_ = sf::VideoMode({ width, height });
		return *this;
	}

	/// <summary>
	/// SetTitle
	/// </summary>
	/// 
	/// <param name="title_out">
	/// title_out - 标题
	/// </param>
	/// 
	/// <returns>
	/// 用于链式初始化
	/// </returns>
	WindowConfigBuilder& SetTitle(const std::string& title_out)
	{
		config_.name_ = title_out;
		return *this;
	}

	/// <summary>
	/// 垂直渲染
	/// </summary>
	/// 
	/// <param name="enable">
	/// enable - 设置值
	/// </param>
	/// 
	/// <returns>
	/// 用于链式初始化
	/// </returns>
	WindowConfigBuilder& EnableVSync(bool enable = true)
	{
		config_.vsync_ = enable;
		return *this;
	}

	/// <summary>
	/// EndBuild 终结链式初始化
	/// </summary>
	/// 
	/// <returns>
	///  返回初始化好的配置
	/// </returns>
	WindowConfig EndBuild() const {
		return config_;
	}
};
