#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include<algorithm>
#include "C:\Users\gambo\source\repos\BigIntApp\BigIntLib\BigIntLib.h"

BigInt::BigInt()
{
}

BigInt::BigInt(std::vector<int> ints)
{
	myInt = ints;
}

BigInt::BigInt(const std::string number)
{
	// i try to keep int i number less than thair max size, so that i don't have problems with too big int-s
	int count = (number.size() / 10);
	std::string str_num;
	int sign = 1;
	int a = 0;
	if (number[0] == '-') {
		sign = -1;
		a = 1;
	}
	int e = 0;
	for (std::string::size_type i = number.size() - 1; i > a; i--) {
		str_num += number[i];
		if ((e + 1) % 7 == 0) {
			std::reverse(str_num.begin(), str_num.end());
			myInt.push_back(sign * stoi(str_num));
			str_num.clear();
		}
		e++;
	}
	if (not str_num.empty()) {
		str_num += number[a];
		std::reverse(str_num.begin(), str_num.end());
		myInt.push_back(sign * stoi(str_num));
	}
	std::reverse(myInt.begin(), myInt.end());
	myInt.shrink_to_fit();
}

std::vector<int> BigInt::getMyInt() const noexcept
{
	return myInt;
}

int intLen(int num) {
	int length = std::to_string(num).length();
	if (num < 0) {
		length--;
	}
	return length;
}

void BigInt::balance()
{
	// situation where one int is at the same time bigger than others(8)
	// and has a diffrent sign is not possible
	int sign = 1;
	if (myInt[0] < 0) {
		sign = -1;
	}
	// firstly I chceck the length of each int, if it is too great 
	for (int i = 1; i < myInt.size(); i++) {
		if (intLen(myInt[i]) > 7) {
			int diffrence = myInt[i] / 10000000; // 10^7
			myInt[i - 1] += diffrence;
			myInt[i] -= diffrence * 10000000;
		}
	}
	// secondly I chceck if somethink has diffrent sign then the gratest number
	for (int i = 1; i < myInt.size(); i++) {
		if (myInt[i] * sign < 0) {
			myInt[i - 1] -= sign;
			myInt[i] += 10000000 * sign;
		}
	}
}

BigInt BigInt::operator+(BigInt const& d) const noexcept
{
	BigInt c;
	std::vector<int> v1 = myInt;
	std::vector<int> v2 = d.myInt;
	int size_diff = v1.size() - v2.size();
	if (size_diff >= 0) {
		for (int i = v1.size(); i > v2.size(); i--) {
			c.myInt.push_back(v1[i]);
		}
		for (int i = 0; i < v2.size(); i++) {
			c.myInt.push_back(v1[i] + v2[i]);
		}
	}
	else {
		for (int i = v2.size(); i > v1.size(); i--) {
			c.myInt.push_back(v2[i]);
		}
		for (int i = 0; i < v1.size(); i++) {
			c.myInt.push_back(v2[i] + v1[i]);
		}
	}
	c.balance();
	return c;
}

std::vector<int> BigInt::ChangeSign(std::vector<int> v) const noexcept
{
	std::vector<int> c;
	c = v;
	for (int a = 0; a < v.size(); ++a) {
		c[a] = v[a] * -1;
	}
	return c;
}

BigInt BigInt::operator-(BigInt const& d) const noexcept
{
	BigInt c, d1, d2;
	d1.myInt = myInt;
	d2.myInt = ChangeSign(d.myInt);
	c = d1 + d2;
	return c;
}

BigInt BigInt::operator+(int const& d) const noexcept
{
	BigInt c;
	c.myInt = myInt;
	c.myInt[myInt.size() - 1] += d;
	c.balance();
	return c;
}

BigInt BigInt::operator-(int const& d) const noexcept
{
	BigInt c;
	c.myInt = myInt;
	c.myInt[myInt.size() - 1] -= d;
	c.balance();
	return c;
}

void BigInt::operator+=(BigInt const& d) noexcept
{
	BigInt c(myInt);
	c = c + d;
	myInt = c.myInt;
	balances = c.balances;
}

void BigInt::operator-=(BigInt const& d) noexcept
{
	BigInt c(myInt);
	c = c - d;
	myInt = c.myInt;
	balances = c.balances;
}

void BigInt::operator+=(int const& d) noexcept
{
	BigInt c(myInt);
	c = c + d;
	myInt = c.myInt;
	balances = c.balances;
}

void BigInt::operator-=(int const& d) noexcept
{
	BigInt c(myInt);
	c = c - d;
	myInt = c.myInt;
	balances = c.balances;
}

bool BigInt::operator==(BigInt const& d) const noexcept
{
	for (int i = 0; i < myInt.size(); i++) {
		if (!(myInt[i] == d.myInt[i])) {
			return false;
		}
	}
	return true;
}

std::ostream& operator<<(std::ostream& os, const BigInt& d)
{
	std::string numbers;
	for (int i = 0; i < d.myInt.size(); i++) {
		numbers += std::to_string(d.myInt[i]);
	}
	os << numbers;
	return os;
}

std::istream& operator>>(std::istream& is, BigInt& d)
{
	std::string input;
	is >> input;
	d = BigInt(input);
	return is;
}
