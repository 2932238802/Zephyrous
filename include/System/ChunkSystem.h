#pragma once
#include<SFML/Graphics.hpp>
#include<entt/entt.hpp>
#include<fstream>
#include<nlohmann/json.hpp> 

#include"ChunkComponent/ChunkConfig.h"
#include"ComComponent/ComCollision.h"



//////////////////////////////////////////////////////////////////////////
/// <summary>
/// ChunkSystem - 生成区块
/// 每一个chunksystem 就是一个区 main函数里面可以创建多个区
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
private:// 基本元素 //
	//////////////////////////////////////////////////////////////////////////
	// 全局唯一一个 //
	entt::registry& registry_;

	// 指针 //
	sf::RenderWindow* window_;

public: // 基本构造 //
	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// 
	/// </summary>
	/// <param name="regietry_out">
	/// 
	/// </param>
	/// 
	/// <param name="window_out">
	/// 外部窗口指针
	/// </param>
	ChunkSystem(entt::registry& regietry_out, sf::RenderWindow* window_out) :
		registry_(regietry_out),
		window_(window_out)
	{
	}
	//////////////////////////////////////////////////////////////////////////





	//////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// ChunkLoad - 区块加载
	/// </summary>
public:
	void ChunkLoad()
	{
		// 读取配置文件信息 //
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
		//reader_->close(); std::unique_ptr 会自动处理

		// 获取尺寸大小 //
		auto& block_config = json_file.at("blockconfig");
		float size_ = block_config.at("size").get<float>();
		// i 表示宽度 j 表示高度 //
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
	/// CreateSquare - 生成方块
	/// </summary>
	/// 
	/// <param name="registry_">
	/// registry_ - 全局唯一 
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
		registry_.emplace<BlockPosition>(entt_, pos_);                   // 位置
		registry_.emplace<BlockSquare>(entt_, square_);                  // 方形 大小
		registry_.emplace<BlockKind>(entt_, kind_out);                   // 泥土
		registry_.emplace<BlockDifficulty>(entt_, diffi_out);            // 难易
		registry_.emplace<ComCollision>(entt_);							  // 碰撞检测
	}

	//////////////////////////////////////////////////////////////////////////

};
//////////////////////////////////////////////////////////////////////////