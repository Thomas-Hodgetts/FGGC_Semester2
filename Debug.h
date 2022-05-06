#pragma once
#include <string>
#include <d3d11_1.h>
#include <Windows.h>

class Debug
{
public:

	void OutputString(std::string OutputString);
	void OutputString(int OutputString);
	void OutputString(float OutputString);
	void OutputString(double OutputString);

};

