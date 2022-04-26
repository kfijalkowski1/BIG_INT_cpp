#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include<algorithm>
#include <math.h>
#include "C:\Users\gambo\source\repos\BigIntApp\BigIntLib\BigIntLib.h"

BigInt::BigInt()
{
}

BigInt::BigInt(std::vector<int> ints)
{
	// for loop to assure that im not loading any negativ ints
	for (int some_int : ints)
	{
		if (some_int < 0) {
			some_int = -1 * some_int;
			sign = -1;
		}
	}
	myInt = ints;
}

BigInt::BigInt(const std::string number)
{
	//I take int-s of 7  
	//I start taking string at the lest important one becouse, the most imporatnt one has t be this shortest one
	//becouse then, when doing operations I can extend the most imporant one but not so much the least important one
	size_t current_pos = 0;
	size_t additional = (number.length() - current_pos) % 7; //additional numbers that are to be the most important int
	size_t no_ints = number.length() / 7;	// number of full numbers

	//chceck if there is a sign
	if (number[0] == '-' or number[0] == '+') {
		if (number[0] == '-') {
			sign = -1;
		}
		current_pos += 1;
	}

	//get rid of 0 at the beggining
	while(number[current_pos] == '0') {
		current_pos++;
	}

	//save this additional numbers -> the most important ones
	if (additional > 0) {
		std::string str_num = number.substr(current_pos, additional);
		current_pos += additional;
		myInt.push_back(stoi(str_num));
	}

	//save the rest of numbers
	for (size_t i = 0; i < no_ints; i++) {
		std::string str_num = number.substr(current_pos, 7);
		current_pos += 7;
		myInt.push_back(stoi(str_num));
	}
}

std::vector<int> BigInt::addMod(BigInt b)
{
	// because it's a private function for my use, I make an assumption that myInt is bigger
	// add mod just incrises the value by given biff BigInt
	//i start at the least important int, so that overload is easier
	int overload = 0;
	for (int i = myInt.size(); i > (myInt.size() - b.myInt.size()); i--) {
		if (overload > 0) {
			myInt[i] += (b.myInt[i] + overload);
			overload = 0;
		}
		else {
			myInt[i] += b.myInt[i];
		}
		//here I check if my current int is too big
		if (myInt[i] > 9999999) {
			int overload = myInt[i] / pow(10, 7);
			myInt[i] = myInt[i] % 10000000;
		}
	}
}

std::vector<int> BigInt::getMyInt() const noexcept
{
	return myInt;
}

BigInt BigInt::copy()
{
	BigInt c(myInt);
	c.sign = sign;
	return c;
}

void BigInt::operator+=(BigInt const& b) noexcept
{
	if (*this >= b) {
		addMod(b);
	}
	else {

	}
}

BigInt BigInt::operator+(BigInt const& d) const noexcept
{
	BigInt c(myInt);
	c += d;
	return c;
}

void BigInt::ChangeSign() noexcept
{
	sign = (-1 * sign);
}


void BigInt::operator-=(BigInt const& d) noexcept
{
	BigInt c(myInt);
	c = c - d;
	myInt = c.myInt;
}

void BigInt::operator+=(int const& d) noexcept
{
	BigInt c(myInt);
	c = c + d;
	myInt = c.myInt;
}

void BigInt::operator-=(int const& d) noexcept
{
	BigInt c(myInt);
	c = c - d;
	myInt = c.myInt;
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

bool BigInt::operator>(BigInt const& d) const noexcept
{
	if (myInt.size() > d.myInt.size()) {
		return true;
	}
	for (int i = 0; i < myInt.size(); i++) {
		if (myInt[i] > d.myInt[i]) {
			return true;
		}
	}
	return false;
}

bool BigInt::operator<(BigInt const& d) const noexcept
{
	if (myInt.size() < d.myInt.size()) {
		return true;
	}
	for (int i = 0; i < myInt.size(); i++) {
		if (myInt[i] < d.myInt[i]) {
			return true;
		}
	}
	return false;
}

bool BigInt::operator<=(BigInt const& d) const noexcept
{
	if (myInt.size() < d.myInt.size()) {
		return true;
	}
	for (int i = 0; i < myInt.size(); i++) {
		if (myInt[i] <= d.myInt[i]) {
			return true;
		}
	}
	return false;
}

bool BigInt::operator>=(BigInt const& d) const noexcept
{
	if (myInt.size() < d.myInt.size()) {
		return true;
	}
	for (int i = 0; i < myInt.size(); i++) {
		if (myInt[i] >= d.myInt[i]) {
			return true;
		}
	}
	return false;
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
