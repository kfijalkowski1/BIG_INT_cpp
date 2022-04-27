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
			std::vector<unsigned int> ints;
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
			int a = d.getMyInt()[2];
			int b = d.getMyInt()[1];
			int c = d.getMyInt()[0];
			Assert::AreEqual(a, 1267);
			Assert::AreEqual(b, 8912378);
			Assert::AreEqual(c, 9341208);
			Assert::AreEqual(1, d.getSign());
		}
		TEST_METHOD(StringInitNegativ)
		{
			std::string number = "-126789123789341208";
			BigInt d(number);
			int a = d.getMyInt()[2];
			int b = d.getMyInt()[1];
			int c = d.getMyInt()[0];
			Assert::AreEqual(a, 1267);
			Assert::AreEqual(b, 8912378);
			Assert::AreEqual(c, 9341208);
			Assert::AreEqual(-1, d.getSign());
		}
		TEST_METHOD(StringInitZeros)
		{
			std::string number = "-0000126789123789341208";
			BigInt d(number);
			int a = d.getMyInt()[2];
			int b = d.getMyInt()[1];
			int c = d.getMyInt()[0];
			Assert::AreEqual(a, 1267);
			Assert::AreEqual(b, 8912378);
			Assert::AreEqual(c, 9341208);
			Assert::AreEqual(-1, d.getSign());
		}
		TEST_METHOD(TestAddingPositiveSameLength)
		{
			std::string number = "412347788888894315865";
			std::string number2 = "473820109843128098993";
			std::string number3 = "886167898732022414858";
			BigInt d(number);
			BigInt d2(number2);
			BigInt a(number3);
			d += d2;
			Assert::IsTrue(a == d);
		}
		TEST_METHOD(TestAddingNegativSameLength)
		{
			std::string number = "-412347788888894315865";
			std::string number2 = "-473820109843128098993";
			std::string number3 = "-886167898732022414858";
			BigInt d(number);
			BigInt d2(number2);
			BigInt a(number3);
			d += d2;
			Assert::IsTrue(a == d);
		}
		TEST_METHOD(TestAddingPositiveDiffrentLength)
		{
			std::string number = "412347788888894315865";
			std::string number2 = "473820109843128098";
			std::string number3 = "412821608998737443963";
			BigInt d(number);
			BigInt d2(number2);
			BigInt a(number3);
			d += d2;
			Assert::IsTrue(a == d);
		}
		TEST_METHOD(TestAddingPositiveVeryDiffrentLength)
		{
			std::string number = "412347788888894315865";
			std::string number2 = "4738201098";
			std::string number3 = "412347788893632516963";
			BigInt d(number);
			BigInt d2(number2);
			BigInt a(number3);
			d += d2;
			Assert::IsTrue(a == d);
		}
		TEST_METHOD(TestAddingNegativDiffrentLength)
		{
			std::string number = "-412347788888894315865";
			std::string number2 = "-473820109843128098";
			std::string number3 = "-412821608998737443963";
			BigInt d(number);
			BigInt d2(number2);
			BigInt a(number3);
			d += d2;
			Assert::IsTrue(a == d);
		}
		TEST_METHOD(TestAddingNegativToPosoitivSameLength)
		{
			std::string number = "-412347788888894315865";
			std::string number2 = "473820109843128098993";
			std::string number3 = "61472320954233783128";
			BigInt d(number);
			BigInt d2(number2);
			BigInt a(number3);
			d += d2;
			Assert::IsTrue(a == d);
		}
		TEST_METHOD(TestAddingPositivToNegativSameLength)
		{
			std::string number = "412347788888894315865";
			std::string number2 = "-473820109843128098993";
			std::string number3 = "-61472320954233783128";
			BigInt d(number);
			BigInt d2(number2);
			BigInt a(number3);
			d += d2;
			Assert::IsTrue(a == d);
		}
		TEST_METHOD(TestAddingNegativToPosoitivDiffrentLength)
		{
			std::string number = "-412347788888894315865";
			std::string number2 = "4738201098431288993";
			std::string number3 = "-407609587790463026872";
			BigInt d(number);
			BigInt d2(number2);
			BigInt a(number3);
			d+= d2;
			Assert::IsTrue(a == d);
		}
		TEST_METHOD(TestSubPosoitivSameLength)
		{
			std::string number = "412347788888894315865";
			std::string number2 = "473825401098431288993";
			std::string number3 = "-61477612209536973128";
			BigInt d(number);
			BigInt d2(number2);
			BigInt a(number3);
			d -= d2;
			Assert::IsTrue(a == d);
		}
		TEST_METHOD(TestSubNegativSameLength)
		{
			std::string number = "-412347788888894315865";
			std::string number2 = "-473820109843128098993";
			std::string number3 = "61472320954233783128";
			BigInt d(number);
			BigInt d2(number2);
			BigInt a(number3);
			d -= d2;
			Assert::IsTrue(a == d);
		}
		TEST_METHOD(TestSubPositiveDiffrentLength)
		{
			std::string number = "412347788888894315865";
			std::string number2 = "473820109843128098";
			std::string number3 = "411873968779051187767";
			BigInt d(number);
			BigInt d2(number2);
			BigInt a(number3);
			d -= d2;
			Assert::IsTrue(a == d);
		}
		TEST_METHOD(TestSubPositiveNegativVeryDiffrentLength)
		{
			std::string number = "412347788888894315865";
			std::string number2 = "-4738201098";
			std::string number3 = "412347788893632516963";
			BigInt d(number);
			BigInt d2(number2);
			BigInt a(number3);
			d -= d2;
			Assert::IsTrue(a == d);
		}
		TEST_METHOD(TestSubNegativDiffrentLength)
		{
			std::string number = "-412347788888894315865";
			std::string number2 = "-473820109843128098";
			std::string number3 = "-411873968779051187767";
			BigInt d(number);
			BigInt d2(number2);
			BigInt a(number3);
			d -= d2;
			Assert::IsTrue(a == d);
		}
		TEST_METHOD(TestSubNegativToPosoitivSameLength)
		{
			std::string number = "-412347788888894315865";
			std::string number2 = "473820109843128098993";
			std::string number3 = "-886167898732022414858";
			BigInt d(number);
			BigInt d2(number2);
			BigInt a(number3);
			d -= d2;
			Assert::IsTrue(a == d);
		}
		TEST_METHOD(TestSubPositivToNegativSameLength)
		{
			std::string number = "412347788888894315865";
			std::string number2 = "-473820109843128098993";
			std::string number3 = "886167898732022414858";
			BigInt d(number);
			BigInt d2(number2);
			BigInt a(number3);
			d -= d2;
			Assert::IsTrue(a == d);
		}
		TEST_METHOD(TestSubNegativToSmallerPositiv)
		{
			std::string number = "412347788888894315865";
			std::string number2 = "-4738201098431288993";
			std::string number3 = "417085989987325604858";
			BigInt d(number);
			BigInt d2(number2);
			BigInt a(number3);
			d -= d2;
			Assert::IsTrue(a == d);
		}
		// in general every operator is based on += and -= 
		//operator so if += and -= operator works,
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
		TEST_METHOD(TestAddBigInt)
		{
			std::string number = "412347788888894315865";
			std::string number2 = "473820109843128098993";
			std::string number3 = "886167898732022414858";
			BigInt d1(number);
			BigInt d2(number2);
			BigInt a(number3);
			BigInt e;
			e = d1 + d2;
			Assert::IsTrue(e == a);
		}
		TEST_METHOD(TestDecriseBigInt)
		{
			std::string number = "412347788888894315865";
			std::string number2 = "473825401098431288993";
			std::string number3 = "-61477612209536973128";
			BigInt d1(number);
			BigInt d2(number2);
			BigInt a(number3);
			BigInt e;
			e = d1 - d2;
			Assert::IsTrue(e == a);
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
		TEST_METHOD(TestOutputStream)
		{
			std::string number = "412347788888894315865";
			BigInt d(number);
			std::stringstream ss;
			ss << d;
			std::string s = ss.str();
			std::string expect = "412347788888894315865";
			Assert::AreEqual(expect, s);
		}
		TEST_METHOD(TestNegativOutputStream)
		{
			std::string number = "-412347788888894315865";
			BigInt d(number);
			std::stringstream ss;
			ss << d;
			std::string s = ss.str();
			std::string expect = "-412347788888894315865";
			Assert::AreEqual(expect, s);
		}
		TEST_METHOD(TestInputStream)
		{
			std::string number = "412347788888894315865";
			BigInt e(number);
			BigInt d;
			std::stringstream ss;
			ss << "412347788888894315865";
			ss >> d;
			Assert::IsTrue(e == d);
		}
		TEST_METHOD(TestDiffPositivOperators)
		{
			std::string number1 = "412347788888894315865";
			std::string number2 = "473825401098431288993";
			BigInt d1(number1);
			BigInt d2(number2);
			Assert::IsTrue(d2 > d1);
			Assert::IsTrue(d2 >= d1);
			Assert::IsFalse(d2 < d1);
			Assert::IsFalse(d2 <= d1);
			Assert::IsFalse(d2 == d1);
			Assert::IsTrue(d2 != d1);
		}
		TEST_METHOD(TestDiffNegativOperators)
		{
			std::string number1 = "-473825401098431288993";
			std::string number2 = "-412347788888894315865";
			BigInt d1(number1);
			BigInt d2(number2);
			Assert::IsTrue(d2 > d1);
			Assert::IsTrue(d2 >= d1);
			Assert::IsFalse(d2 < d1);
			Assert::IsFalse(d2 <= d1);
			Assert::IsFalse(d2 == d1);
			Assert::IsTrue(d2 != d1);
		}
		TEST_METHOD(TestDiffSizeNegativOperators)
		{
			std::string number1 = "-473825401098431288993";
			std::string number2 = "-41234778888885865";
			BigInt d1(number1);
			BigInt d2(number2);
			Assert::IsTrue(d2 > d1);
			Assert::IsTrue(d2 >= d1);
			Assert::IsFalse(d2 < d1);
			Assert::IsFalse(d2 <= d1);
			Assert::IsFalse(d2 == d1);
			Assert::IsTrue(d2 != d1);
		}
		TEST_METHOD(TestDiffSizePositivOperators)
		{
			std::string number1 = "41234778888885865";
			std::string number2 = "473825401098431288993";
			BigInt d1(number1);
			BigInt d2(number2);
			Assert::IsTrue(d2 > d1);
			Assert::IsTrue(d2 >= d1);
			Assert::IsFalse(d2 < d1);
			Assert::IsFalse(d2 <= d1);
			Assert::IsFalse(d2 == d1);
			Assert::IsTrue(d2 != d1);
		}
		TEST_METHOD(TestSamePositivOperators)
		{
			std::string number1 = "41234778888885865";
			std::string number2 = "41234778888885865";
			BigInt d1(number1);
			BigInt d2(number2);
			Assert::IsFalse(d2 > d1);
			Assert::IsTrue(d2 >= d1);
			Assert::IsFalse(d2 < d1);
			Assert::IsTrue(d2 <= d1);
			Assert::IsTrue(d2 == d1);
			Assert::IsFalse(d2 != d1);
		}
		TEST_METHOD(TestSameNegativOperators)
		{
			std::string number1 = "-41234778888885865";
			std::string number2 = "-41234778888885865";
			BigInt d1(number1);
			BigInt d2(number2);
			Assert::IsFalse(d2 > d1);
			Assert::IsTrue(d2 >= d1);
			Assert::IsFalse(d2 < d1);
			Assert::IsTrue(d2 <= d1);
			Assert::IsTrue(d2 == d1);
			Assert::IsFalse(d2 != d1);
		}
	};
}
