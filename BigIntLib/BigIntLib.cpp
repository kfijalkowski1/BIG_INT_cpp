#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>
#include "C:\Users\gambo\source\repos\BigIntApp\BigIntLib\BigIntLib.h"

BigInt::BigInt()
{
}

BigInt::BigInt(std::vector<unsigned int> ints)
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

BigInt::BigInt(std::string const& number)
{
	//I take int-s of 7  
	//I start taking string at the lest important one becouse, the most imporatnt one has t be this shortest one
	//becouse then, when doing operations I can extend the most imporant one but not so much the least important one
	unsigned int currentPos = 0;
	

	//chceck if there is a sign
	if (number[0] == '-' or number[0] == '+') {
		if (number[0] == '-') {
			sign = -1;
		}
		currentPos += 1;

	}

	//get rid of 0 at the beggining
	while(number[currentPos] == '0') {
		currentPos++;
	}

	unsigned int additional = (number.length() - currentPos) % 7; //additional numbers that are to be the most important int
	//save this additional numbers -> the most important ones
	if (additional > 0) {
		std::string str_num = number.substr(currentPos, additional);
		currentPos += additional;
		myInt.push_back(stoi(str_num));
	}

	
	unsigned int no_ints = number.length() / 7;	// number of full numbers
	no_ints = (number.length() - currentPos) / 7;
	//save the rest of numbers
	for (size_t i = 0; i < no_ints; i++) {
		std::string str_num = number.substr(currentPos, 7);
		currentPos += 7;
		myInt.push_back(stoi(str_num));
	}
	std::reverse(myInt.begin(), myInt.end());
}

std::vector<unsigned int> BigInt::addMod(std::vector<unsigned int> v1, std::vector<unsigned int> v2)
{
	//because it's a private function for my use, I make an assumption that v1 is bigger
	//add mod just incrises the value by given biff BigInt
	//i start at the least important int, so that overload is easier
	//the least important ones are at the beggining
	int overload = 0;
	for (int i = 0; i < v2.size(); i++) 
	{
		v1[i] += (v2[i] + overload);
		overload = 0;
		
		//here I check if my current int is too big
		if (v1[i] > 9999999) {
			overload = v1[i] / pow(10, 7);
			v1[i] = v1[i] % 10000000;
		}
	}
	return v1;
}

std::vector<unsigned int> BigInt::subMod(std::vector<unsigned int> v1, std::vector<unsigned int> v2)
{
	//making an assuption that v1 is bigger than v2
	int underload = 0;
	int currentDif = 0;
	for (int i = 0; i < v2.size(); i++) {
		currentDif = v1[i] - v2[i] - underload;
		underload = 0;
		if (currentDif < 0) {
			underload = 1;
			currentDif += pow(10, 7);
		}
		v1[i] = currentDif;
	}
	if (underload == 1)
	{
		v1[v2.size()] = v1[v2.size()] - underload;
	}
	return v1;
}


std::vector<unsigned int> BigInt::getMyInt() const noexcept
{
	return myInt;
}

int BigInt::getSign() const noexcept
{
	return sign;
}

BigInt BigInt::copy() const noexcept
{
	BigInt c(myInt);
	c.sign = sign;
	return c;
}

bool moduloBiggerEq(std::vector<unsigned int> v1, std::vector<unsigned int> v2) {
	// returns true if v1 bigger or equal, its a private method for making addition and subtracting easier
	// most important at the end
	if (v1.size() > v2.size()) {
		return true;
	}
	else if (v1.size() < v2.size()) {
		return false;
	}
	for (int i = (v1.size() - 1); i >= 0; i--) {
		if (v1[i] > v2[i]) {
			return true;
		}
		if (v1[i] < v2[i]) {
			return false;
		}
	}
	return true;
}

void BigInt::operator+=(BigInt const& b) noexcept
{
	//equal signs -> adding modules
	if ((sign * b.sign) == 1)
	{
		if (moduloBiggerEq(myInt, b.myInt)) {
			myInt = addMod(myInt, b.myInt);
		}
		else {
			myInt = addMod(b.myInt, myInt);
		}
	}
	//diffrent signs -> subtracting modules
	else {
		if (moduloBiggerEq(myInt, b.myInt)) {
			myInt = subMod(myInt, b.myInt);
		}
		else {
			myInt = subMod(b.myInt, myInt);
			this->ChangeSign();
		}
		}
	}


void BigInt::operator-=(BigInt const& b) noexcept
{
	//firstly if sign are diffrent I have to add them
	if (sign == 1 && b.sign == -1) {
		BigInt c = b.copy();
		c.sign = 1;
		*this += c;
	}
	else if (sign == -1 && b.sign == 1) {
		sign = 1;
		*this += b;
		sign = -1;
	}
	else {
		if (moduloBiggerEq(myInt, b.myInt)) {
			myInt = subMod(myInt, b.myInt);
		}
		else {
			myInt = subMod(b.myInt, myInt);
			this->ChangeSign();
		}
	}
}


void BigInt::operator+=(int const& d) noexcept
{
	myInt[0] += d;
}

void BigInt::operator-=(int const& d) noexcept
{
	myInt[0] -= d;
}

BigInt BigInt::operator+(BigInt const& d) const noexcept
{
	BigInt c(myInt);
	c.sign = sign;
	c += d;
	return c;
}

BigInt BigInt::operator-(BigInt const& d) const noexcept
{
	BigInt c(myInt);
	c.sign = sign;
	c -= d;
	return c;
}

BigInt BigInt::operator+(int const& d) const noexcept
{
	BigInt c(myInt);
	c.sign = sign;
	c += d;
	return c;
}

BigInt BigInt::operator-(int const& d) const noexcept
{
	BigInt c(myInt);
	c.sign = sign;
	c -= d;
	return c;
}


void BigInt::ChangeSign() noexcept
{
	sign = (-1 * sign);
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

bool BigInt::operator!=(BigInt const& d) const noexcept
{
	if (*this == d) {
		return false;
	}
	return true;
}

bool BigInt::operator>(BigInt const& d) const noexcept
{
	if (d.sign < sign) {
		if (sign < 0) {
			return false;
		}
		return true;
	}
	if (myInt.size() > d.myInt.size()) {
		return true;
	}
	if (myInt.size() < d.myInt.size()) {
		return false;
	}
	for (int i = (myInt.size() - 1); i >= 0; i--) {
		if (myInt[i] > d.myInt[i]) {
			if (sign < 0) {
				return false;
			}
			return true;
		}
		else if (myInt[i] < d.myInt[i]) {
			if (sign < 0) {
				return true;
			}
			return false;
		}
	}
	return false;
	
}

bool BigInt::operator<(BigInt const& d) const noexcept
{
	if (d.sign < sign) {
		if (sign < 0) {
			return true;
		}
		return false;
	}
	if (myInt.size() > d.myInt.size()) {
		return false;
	}
	if (myInt.size() < d.myInt.size()) {
		return true;
	}
	for (int i = (myInt.size() - 1); i >= 0; i--) {
		if (myInt[i] < d.myInt[i]) {
			if (sign < 0) {
				return false;
			}
			return true;
		}
		else if (myInt[i] > d.myInt[i]) {
			if (sign < 0) {
				return true;
			}
			return false;
		}
	}
	return false;

}

bool BigInt::operator<=(BigInt const& d) const noexcept
{
	if (d.sign < sign) {
		if (sign < 0) {
			return true;
		}
		return false;
	}
	if (myInt.size() > d.myInt.size()) {
		return false;
	}
	if (myInt.size() < d.myInt.size()) {
		return true;
	}
	for (int i = (myInt.size() - 1); i >= 0; i--) {
		if (myInt[i] < d.myInt[i]) {
			if (sign < 0) {
				return false;
			}
			return true;
		}
		else if (myInt[i] > d.myInt[i]) {
			if (sign < 0) {
				return true;
			}
			return false;
		}
	}
	return true;
}

bool BigInt::operator>=(BigInt const& d) const noexcept
{
	if (d.sign < sign) {
		if (sign < 0) {
			return false;
		}
		return true;
	}
	if (myInt.size() > d.myInt.size()) {
		return true;
	}
	if (myInt.size() < d.myInt.size()) {
		return false;
	}
	for (int i = (myInt.size() - 1); i >= 0; i--) {
		if (myInt[i] > d.myInt[i]) {
			if (sign < 0) {
				return false;
			}
			return true;
		}
		else if (myInt[i] < d.myInt[i]) {
			if (sign < 0) {
				return true;
			}
			return false;
		}
	}
	return true;
}

std::ostream& operator<<(std::ostream& os, const BigInt& d)
{
	std::string numbers;
	for (int i = (d.myInt.size() - 1); i >= 0; i--) {
		numbers += std::to_string(d.myInt[i]);
	}
	if (d.sign == -1) {
		os << '-' << numbers;
		return os;
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
