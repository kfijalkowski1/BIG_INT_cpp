#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iterator>

class BigInt {
private:
	//ints have 7 in length (so that i can't overload int)
	//storages the most important int at the end(for example num: 1234567890) 1234567 would be at [1]
	std::vector<unsigned int> myInt; 
	int sign = 1;
	//two privat operators for adding and subtracting modules of numbers
	std::vector<unsigned int> addMod(std::vector<unsigned int> const& v1, std::vector<unsigned int> const& v2) const;
	std::vector<unsigned int> subMod(std::vector<unsigned int> v1, std::vector<unsigned int> v2);
public:
	
	BigInt();
	BigInt(std::vector<unsigned int> ints);
	BigInt(std::string const& number);
	BigInt(BigInt const& b);
	void ChangeSign() noexcept;
	std::vector<unsigned int> getMyInt() const noexcept;
	int getSign() const noexcept;
	
	

	void operator+=(BigInt const& d) noexcept;
	void operator-=(BigInt const& d) noexcept;
	void operator+=(int const& d) noexcept;
	void operator-=(int const& d) noexcept;



	BigInt operator+(BigInt const& d) const noexcept;
	BigInt operator-(BigInt const& d) const noexcept;
	BigInt operator+(int const& d) const noexcept;
	BigInt operator-(int const& d) const noexcept;



	// compere operations
	bool operator==(BigInt const& d) const noexcept;
	bool operator!=(BigInt const& d) const noexcept;
	bool operator>(BigInt const& d) const noexcept;
	bool operator<(BigInt const& d) const noexcept;
	bool operator>=(BigInt const& d) const noexcept;
	bool operator<=(BigInt const& d) const noexcept;


	//overloading stram operations for easier use in interface
	friend std::ostream& operator<<(std::ostream& os, const BigInt& d);
	friend std::istream& operator>>(std::istream& is, BigInt& d);
};
