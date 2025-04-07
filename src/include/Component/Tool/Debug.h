
#pragma once
#include<iostream>
#include<fstream>

class MyDebug {
public:
	// 实际实现（接受调用位置参数）
	static void DprintImpl(const char* file, int line, const char* str_) {
		std::ofstream log_file("D:/桌面/Zephyrous/src/include/Component/Tool/debug.log", std::ios::app);
		if (log_file.is_open()) {
			log_file << "调用位置: " << file << ":" << line << std::endl;
			log_file.close();
		}
		else {
			std::cerr << "无法打开日志文件" << std::endl;
		}
	}
};

// 定义宏自动传递 __FILE__ 和 __LINE__
#define DLOG do { \
    MyDebug::DprintImpl(__FILE__, __LINE__,""); \
} while(0)


