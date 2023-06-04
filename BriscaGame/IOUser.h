#pragma once

#include <iostream>

void Log(const char* message)
{
	std::cout << message << std::endl;
}

int InputNumber(int options)
{
	int input;
	std::cin >> input;
	while (!std::isdigit(input) || (input < 1 || input > options))
	{
		Log("This is not an option!");
		std::cin >> input;
	}
	return input;

}

bool InputBool()
{
	char input;
	std::cin >> input;
	while (input != 'Y' && input != 'N')
	{
		Log("This is not a valid option!");
		std::cin >> input;
	}

	if (input == 'Y') return true;
	else return false;
}