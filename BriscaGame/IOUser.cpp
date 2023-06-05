#include <iostream>
#include "IOUser.h"
#include <cctype>

void Log(const char* message)
{
	std::cout << message << std::endl;
}

void Log(std::string& message)
{
	std::cout << message << std::endl;
}

int InputNumber(int options)
{
	char input;
	std::cin >> input;

	while (!(isdigit(input)) || ((input - '0') < 1 || (input - '0') > options))
	{
		Log("This is not an option!");
		std::cin >> input;
	}

	return input - '0';  // Convert char to int before returning
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