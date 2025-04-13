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
	/// SetResolution ���ø߿�
	/// </summary>
	/// <param name="width">
	/// ���
	/// </param>
	/// 
	/// <param name="height">
	/// �߶�
	/// </param>
	/// 
	/// <returns>
	/// ������ʽ��ʼ��
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
	/// title_out - ����
	/// </param>
	/// 
	/// <returns>
	/// ������ʽ��ʼ��
	/// </returns>
	WindowConfigBuilder& SetTitle(const std::string& title_out)
	{
		config_.name_ = title_out;
		return *this;
	}

	/// <summary>
	/// ��ֱ��Ⱦ
	/// </summary>
	/// 
	/// <param name="enable">
	/// enable - ����ֵ
	/// </param>
	/// 
	/// <returns>
	/// ������ʽ��ʼ��
	/// </returns>
	WindowConfigBuilder& EnableVSync(bool enable = true)
	{
		config_.vsync_ = enable;
		return *this;
	}

	/// <summary>
	/// EndBuild �ս���ʽ��ʼ��
	/// </summary>
	/// 
	/// <returns>
	///  ���س�ʼ���õ�����
	/// </returns>
	WindowConfig EndBuild() const {
		return config_;
	}
};
