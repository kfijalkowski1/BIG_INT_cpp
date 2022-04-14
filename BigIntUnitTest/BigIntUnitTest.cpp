#include "CppUnitTest.h"
#include <iostream>
#include "C:\Users\gambo\source\repos\BigIntApp\BigIntLib\BigIntLib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BigIntUnitTest
{
	TEST_CLASS(BigIntUnitTest)
	{
	public:
		
		TEST_METHOD(VectorInit)
		{
			std::vector<int> ints;
			ints.push_back(4123478);
			ints.push_back(1235675);
			ints.push_back(4315865);
			BigInt d(ints);
			int a = d.getMyInt()[0];
			int b = d.getMyInt()[1];
			int c = d.getMyInt()[2];
			Assert::AreEqual(a, 4123478);
			Assert::AreEqual(b, 1235675);
			Assert::AreEqual(c, 4315865);
		}
		TEST_METHOD(StringInit)
		{
			std::string number = "126789123789341208";
			BigInt d(number);
			int a = d.getMyInt()[0];
			int b = d.getMyInt()[1];
			int c = d.getMyInt()[2];
			Assert::AreEqual(a, 1267891);
			Assert::AreEqual(b, 2378934);
			Assert::AreEqual(c, 1208);
		}
		TEST_METHOD(StringInitNegativ)
		{
			std::string number = "-126789123789341208";
			BigInt d(number);
			int a = d.getMyInt()[0];
			int b = d.getMyInt()[1];
			int c = d.getMyInt()[2];
			Assert::AreEqual(a, -1267891);
			Assert::AreEqual(b, -2378934);
			Assert::AreEqual(c, -1208);
		}
		TEST_METHOD(BalanceTooLong)
		{
			std::string number = "412347912356754315865";
			BigInt d(number);
			std::vector<int> ints;
			ints.push_back(4123478);
			ints.push_back(11235675);
			ints.push_back(4315865);
			BigInt e(ints);
			e.balance();
			Assert::IsTrue(d == e);
		}
		TEST_METHOD(BalanceNegativ)
		{
			std::string number = "412347788888894315865";
			BigInt d(number);
			std::vector<int> ints;
			ints.push_back(4123478);
			ints.push_back(-1111111);
			ints.push_back(4315865);
			BigInt e(ints);
			e.balance();
			Assert::IsTrue(d == e);
		}
		TEST_METHOD(BalanceWholeNegativ)
		{
			std::string number = "-412347788888894315865";
			BigInt d(number);
			std::vector<int> ints;
			ints.push_back(-4123478);
			ints.push_back(1111111);
			ints.push_back(-4315865);
			BigInt e(ints);
			e.balance();
			Assert::IsTrue(d == e);
		}
		TEST_METHOD(TestAddingPositiveSameLength)
		{
			std::string number = "412347788888894315865";
			std::string number2 = "473820109843128098993";
			std::string number3 = "886167898732022414858";
			BigInt d(number);
			BigInt d2(number2);
			BigInt a(number3);
			BigInt e;
			e = d + d2;
			Assert::IsTrue(a == e);
		}
		TEST_METHOD(TestAddingNegativSameLength)
		{
			std::string number = "-412347788888894315865";
			std::string number2 = "-473820109843128098993";
			std::string number3 = "-886167898732022414858";
			BigInt d(number);
			BigInt d2(number2);
			BigInt a(number3);
			BigInt e;
			e = d + d2;
			Assert::IsTrue(a == e);
		}
		TEST_METHOD(TestAddingPositiveDiffrentLength)
		{
			std::string number = "412347788888894315865";
			std::string number2 = "473820109843128098";
			std::string number3 = "412821608998737443963";
			BigInt d(number);
			BigInt d2(number2);
			BigInt a(number3);
			BigInt e;
			e = d + d2;
			Assert::IsTrue(a == e);
		}
	};
}
