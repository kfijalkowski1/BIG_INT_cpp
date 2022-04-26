#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iterator>

//class BigIntIterator
//{
//	friend BigInt;
//
//public:
//	using PoiterType = int*;
//	using ReferenceType = int&;
//	BigIntIterator(PoiterType ptr)
//		: m_Ptr(ptr) {}
//private:
//	PoiterType m_Ptr;
//	
//};

class BigInt {
private:
	// no - number of
	std::vector<int> myInt; //storages the most important int at the end(for example num: 1234567890) 1234567 would be at the end 
	int sign;
public:

	BigInt();
	BigInt(std::vector<int> ints);
	BigInt(std::string number);
	void balance(); //balances number when int-s are not all in one sign
	std::vector<int> ChangeSign(std::vector<int> v) const noexcept;
	std::vector<int> getMyInt() const noexcept;
	
	

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

	/*BigIntIterator begin()
	{
		return BigIntIterator(myInt.begin());
	}

	BigIntIterator end()
	{
		return BigIntIterator(myInt.end());
	}*/
};
