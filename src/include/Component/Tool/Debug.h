
#pragma once
#include<iostream>

class MyDebug
{
public:
	static void Dprint()
	{
		std::cout << "File: " << __FILE__ << ", Line: " << __LINE__ << std::endl;
	}
};