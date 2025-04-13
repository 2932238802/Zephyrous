#pragma once
#include<SFML/Graphics.hpp>
#include<entt/entt.hpp>
#include<fstream>
#include <nlohmann/json.hpp> 

#include"ChunkComponent/ChunkConfig.h"

//////////////////////////////////////////////////////////////////////////
/// <summary>
/// ChunkSysteem - ��������
/// 1. ÿһ��chunksystem ����һ���� main����������Դ��������
/// </summary>
namespace Chunksize
{
	constexpr unsigned int CHUNK_WIDTH = 32;
	constexpr unsigned int CHUNK_HEIGHT = 14;
}
class ChunkSysteem
{
	
private:// ����Ԫ�� //
	//////////////////////////////////////////////////////////////////////////
	// ȫ��Ψһһ�� //
	entt::registry& registry_;

	// ָ�� //
	std::shared_ptr<sf::RenderWindow> window_;

	// ÿһ����������� //
	std::array<entt::entity, Chunksize::CHUNK_WIDTH* Chunksize::CHUNK_HEIGHT> chunk_contain;
	// ��������
	//////////////////////////////////////////////////////////////////////////



public: // �������� //
	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// 
	/// </summary>
	/// <param name="regietry_out">
	/// 
	/// </param>
	/// 
	/// <param name="window_out">
	/// �ⲿ����ָ��
	/// </param>
	ChunkSysteem(entt::registry& regietry_out,std::shared_ptr<sf::RenderWindow> window_out) :
		registry_(regietry_out),
		window_(window_out)
	{
	}
	//////////////////////////////////////////////////////////////////////////
	



public: // �������� //
	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// Init - ��ʼ�� С����
	/// </summary>
	/// <param name="config_">
	/// config_ - ��������
	/// </param>
	void Load()
	{
		ChunkLoad();
	}

	//////////////////////////////////////////////////////////////////////////




	//////////////////////////////////////////////////////////////////////////
private: // chunk������� //
	void ChunkLoad()
	{
		// ��ȡ�����ļ���Ϣ //
		auto reader_ = std::make_unique<std::ifstream>("chunkconfig.json");
		if (!reader_->is_open())
		{
			DLOG("open1 json failed!");
		}
		nlohmann::json json_file;
		*reader_ >> json_file;
		if (!json_file.contains("blockconfig"))
		{
			DLOG("json_file content is wrong!");
		}
		reader_->close();

		// ��ȡ�ߴ��С //
		auto& block_config = json_file.at("blockconfig");
		float size_ = block_config.at("size").get<float>();
		
		// i ��ʾ��� j ��ʾ�߶� //
		for (int i = 0; i < Chunksize::CHUNK_WIDTH;i++)
		{
			for (int j = 0; j < Chunksize::CHUNK_HEIGHT; j++)
			{
				// ����ʵ�� //
				CreateSquare(
					{ i * size_, 800.f + j * size_ },
					Diffi::Easy,
					Kind::Soil,
					{ size_,size_ },
					2.f,
					sf::Color::White,
					sf::Color::Red
				);
			}
		}
	}
	


	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// CreateSquare - ���ɷ���
	/// </summary>
	/// 
	/// <param name="registry_">
	/// registry_ - ȫ��Ψһ 
	/// </param>
	void CreateSquare(
		const BlockPosition& pos_,
		const Diffi& diffi_out,
		const Kind& kind_out,
		const sf::Vector2f& size_,
		float thickness_,
		const sf::Color& color_in,
		const sf::Color& color_out
	)
	{
		BlockSquare square_(size_, thickness_, color_in, color_out);
		auto entt_ = registry_.create();
		registry_.emplace<BlockPosition>(entt_, pos_);					// λ��
		registry_.emplace<BlockSquare>(entt_, square_);					// ���� ��С
		registry_.emplace<BlockMoveAble>(entt_);						// �����ƶ�
		registry_.emplace<BlockKind>(entt_, Kind::Soil);				// ����
		registry_.emplace <BlockDifficulty>(entt_, Diffi::Easy);		// ����
	}
	//////////////////////////////////////////////////////////////////////////

};
//////////////////////////////////////////////////////////////////////////