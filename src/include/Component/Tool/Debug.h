
#pragma once
#include<iostream>
#include<fstream>

class MyDebug {
public:
	// ʵ��ʵ�֣����ܵ���λ�ò�����
	static void DprintImpl(const char* file, int line, const char* str_) {
		std::ofstream log_file("D:/����/Zephyrous/src/include/Component/Tool/debug.log", std::ios::app);
		if (log_file.is_open()) {
			log_file << "����λ��: " << file << ":" << line << std::endl;
			log_file.close();
		}
		else {
			std::cerr << "�޷�����־�ļ�" << std::endl;
		}
	}
};

// ������Զ����� __FILE__ �� __LINE__
#define DLOG do { \
    MyDebug::DprintImpl(__FILE__, __LINE__,""); \
} while(0)


