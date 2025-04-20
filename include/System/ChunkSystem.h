#pragma once
#include<SFML/Graphics.hpp>
#include<entt/entt.hpp>
#include<fstream>
#include<nlohmann/json.hpp> 

#include"ChunkComponent/ChunkConfig.h"
#include"ComComponent/ComCollision.h"



//////////////////////////////////////////////////////////////////////////
/// <summary>
/// ChunkSystem - ��������
/// ÿһ��chunksystem ����һ���� main����������Դ��������
/// </summary>
namespace Chunksize
{
	constexpr unsigned int CHUNK_WIDTH = 32;
	constexpr unsigned int CHUNK_HEIGHT = 20;
	constexpr float BASE_Y_POS = 100.f;
}

class ChunkSystem
{
	using usd = unsigned;
private:// ����Ԫ�� //
	//////////////////////////////////////////////////////////////////////////
	// ȫ��Ψһһ�� //
	entt::registry& registry_;

	// ָ�� //
	sf::RenderWindow* window_;

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
	ChunkSystem(entt::registry& regietry_out, sf::RenderWindow* window_out) :
		registry_(regietry_out),
		window_(window_out)
	{
	}
	//////////////////////////////////////////////////////////////////////////





	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// ChunkLoad - �������
	/// </summary>
public:
	void ChunkLoad()
	{
		// ��ȡ�����ļ���Ϣ //
		std::ifstream reader_("chunkconfig.json");
		if (!reader_.is_open())
		{
			DLOG("open json failed!");
		}
		nlohmann::json json_file;
		reader_ >> json_file;
		if (!json_file.contains("blockconfig"))
		{
			DLOG("json_file content is wrong!");
		}
		//reader_->close(); std::unique_ptr ���Զ�����

		// ��ȡ�ߴ��С //
		auto& block_config = json_file.at("blockconfig");
		float size_ = block_config.at("size").get<float>();
		// i ��ʾ��� j ��ʾ�߶� //
		for (int i = 0; i < Chunksize::CHUNK_WIDTH; i++)
		{
			for (int j = 0; j < Chunksize::CHUNK_HEIGHT; j++)
			{
				CreateSquare(
					{ (i - 16) * size_, Chunksize::BASE_Y_POS + j * size_ },
					Diffi::Easy,
					Kind::Empty,
					{ size_,size_ },
					2.f,
					sf::Color::White,
					sf::Color::Red
				);
			}
		}

		//////////////////////////////////////////////////////////////////////////
		// test //
		CreateSquare(
			{ 3 * size_ , 0.f },
			Diffi::Easy,
			Kind::Empty,
			{ size_,size_ },
			2.f,
			sf::Color::White,
			sf::Color::Red
		);
	}
			//////////////////////////////////////////////////////////////////////////
	
	



	



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
		registry_.emplace<BlockPosition>(entt_, pos_);                   // λ��
		registry_.emplace<BlockSquare>(entt_, square_);                  // ���� ��С
		registry_.emplace<BlockKind>(entt_, kind_out);                   // ����
		registry_.emplace<BlockDifficulty>(entt_, diffi_out);            // ����
		registry_.emplace<ComCollision>(entt_);							  // ��ײ���
	}

	//////////////////////////////////////////////////////////////////////////

};
//////////////////////////////////////////////////////////////////////////