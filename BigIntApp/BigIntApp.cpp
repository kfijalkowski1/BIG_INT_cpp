#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include "C:\Users\gambo\source\repos\BigIntApp\BigIntLib\BigIntLib.h"

std::vector<BigInt> openFile()
{
	std::ifstream file("TestNum.txt");
	std::string input;
	std::vector<std::string> numbers;
	while (file >> input)
	{
		numbers.push_back(input);
	}
	std::vector<BigInt> numbersReady;
	for (std::string number : numbers)
	{
		numbersReady.push_back(BigInt(number));
	}
	return numbersReady;
}

int main()
{
	BigInt Bignumber("-123456789012345678901234567");
	std::vector<BigInt> numbers = openFile();
	if (numbers[5] == (numbers[4] + numbers[3])) {
		std::cout << "true";
	}
	return 0;
}

