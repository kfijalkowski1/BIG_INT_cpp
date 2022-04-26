#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iterator>

class BigInt {
private:
	//ints have 7 in length (so that i can't overload int)
	//storages the most important int at the begining(for example num: 1234567890) 1234567 would be at [0]
	std::vector<int> myInt; 
	int sign = 1;
	void addMod(BigInt b);
	void addModSmaller(BigInt b);
	void subMod(BigInt b);
public:

	BigInt();
	BigInt(std::vector<int> ints);
	BigInt(std::string number);
	void ChangeSign() noexcept;
	std::vector<int> getMyInt() const noexcept;
	BigInt copy();
	
	

	// basic operators making new object
	BigInt operator+(BigInt const& d) const noexcept;
	BigInt operator-(BigInt const& d) const noexcept;
	BigInt operator+(int const& d) const noexcept;
	BigInt operator-(int const& d) const noexcept;


	//operators making actions on the object itself
	void operator+=(BigInt const& d) noexcept;
	void operator-=(BigInt const& d) noexcept;
	void operator+=(int const& d) noexcept;
	void operator-=(int const& d) noexcept;


	// compere operations, not making new object, returns a bool
	bool operator==(BigInt const& d) const noexcept;
	bool operator>(BigInt const& d) const noexcept;
	bool operator<(BigInt const& d) const noexcept;
	bool operator>=(BigInt const& d) const noexcept;
	bool operator<=(BigInt const& d) const noexcept;


	//overloading stram operations for easier use in interface
	friend std::ostream& operator<<(std::ostream& os, const BigInt& d);
	friend std::istream& operator>>(std::istream& is, BigInt& d);
};
