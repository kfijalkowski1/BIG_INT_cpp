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
			Assert::AreEqual(a, 1267);
			Assert::AreEqual(b, 8912378);
			Assert::AreEqual(c, 9341208);
		}
		TEST_METHOD(StringInitNegativ)
		{
			std::string number = "-126789123789341208";
			BigInt d(number);
			int a = d.getMyInt()[0];
			int b = d.getMyInt()[1];
			int c = d.getMyInt()[2];
			Assert::AreEqual(a, -1267);
			Assert::AreEqual(b, -8912378);
			Assert::AreEqual(c, -9341208);
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
		TEST_METHOD(TestAddingNegativDiffrentLength)
		{
			std::string number = "-412347788888894315865";
			std::string number2 = "-473820109843128098";
			std::string number3 = "-412821608998737443963";
			BigInt d(number);
			BigInt d2(number2);
			BigInt a(number3);
			BigInt e;
			e = d + d2;
			Assert::IsTrue(a == e);
		}
		TEST_METHOD(TestAddingNegativToPosoitivSameLength)
		{
			std::string number = "-412347788888894315865";
			std::string number2 = "473820109843128098993";
			std::string number3 = "61472320954233783128";
			BigInt d(number);
			BigInt d2(number2);
			BigInt a(number3);
			BigInt e;
			e = d + d2;
			Assert::IsTrue(a == e);
		}
		TEST_METHOD(TestAddingNegativToPosoitivDiffrentLength)
		{
			std::string number = "-412347788888894315865";
			std::string number2 = "4738201098431288993";
			std::string number3 = "-407609587790463026872";
			BigInt d(number);
			BigInt d2(number2);
			BigInt a(number3);
			BigInt e;
			e = d + d2;
			Assert::IsTrue(a == e);
		}
		TEST_METHOD(TestSubPosoitivSameLength)
		{
			std::string number = "412347788888894315865";
			std::string number2 = "473825401098431288993";
			std::string number3 = "-61477612209536973128";
			BigInt d(number);
			BigInt d2(number2);
			BigInt a(number3);
			BigInt e;
			e = d - d2;
			Assert::IsTrue(a == e);
		}
		// in general every operator is based on + operator so if + operator works,
		//there is no need to chceck other operators as detiled
		TEST_METHOD(TestAddingInt)
		{
			std::string number = "412347788888894315865";
			std::string number2 = "412347788888894315867";
			int a = 2;
			BigInt d(number);
			BigInt d2(number2);
			BigInt e;
			e = d + a;
			Assert::IsTrue(e == d2);
		}
		TEST_METHOD(TestSubInt)
		{
			std::string number = "412347788888894315865";
			std::string number2 = "412347788888894315863";
			int a = 2;
			BigInt d(number);
			BigInt d2(number2);
			BigInt e;
			e = d - a;
			Assert::IsTrue(e == d2);
		}
		TEST_METHOD(TestIncreseBigInt)
		{
			std::string number = "412347788888894315865";
			std::string number2 = "473820109843128098993";
			std::string number3 = "886167898732022414858";
			BigInt d(number);
			BigInt d2(number2);
			BigInt a(number3);
			d += d2;
			Assert::IsTrue(d == a);
		}
		TEST_METHOD(TestDecriseBigInt)
		{
			std::string number = "412347788888894315865";
			std::string number2 = "473825401098431288993";
			std::string number3 = "-61477612209536973128";
			BigInt d(number);
			BigInt d2(number2);
			BigInt a(number3);
			d -= d2;
			Assert::IsTrue(d == a);
		}
		TEST_METHOD(TestIncreseInt)
		{
			std::string number = "412347788888894315865";
			int d2 = 3;
			std::string number3 = "412347788888894315868";
			BigInt d(number);
			BigInt a(number3);
			d += d2;
			Assert::IsTrue(d == a);
		}
		TEST_METHOD(TestDecriseInt)
		{
			std::string number = "412347788888894315865";
			int d2 = 3;
			std::string number3 = "412347788888894315862";
			BigInt d(number);
			BigInt a(number3);
			d -= d2;
			Assert::IsTrue(d == a);
		}
	};
}
