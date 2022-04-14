#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>


class BigInt {
private:
	// no - number of
	;
	std::vector<int> myInt;
	std::vector<int> balances; // if somewhere there is int that starts with 0, it shows the number of this int
public:

	BigInt();
	BigInt(std::vector<int> ints);
	BigInt(std::string number);
	void balance(); //balances number when int-s are not all in one sign
	std::vector<int> ChangeSign(std::vector<int> v) const noexcept;
	std::vector<int> getMyInt() const noexcept;
	
	//class MyIterator
	//{
	//	friend BigInt;
	//private:
	//	myInt* m_ptr;

	//};

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


	//overloading stram operations for easier use in interface
	friend std::ostream& operator<<(std::ostream& os, const BigInt& d);
	friend std::istream& operator>>(std::istream& is, BigInt& d);
};
