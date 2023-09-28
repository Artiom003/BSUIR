#include "pch.h"
#include "CppUnitTest.h"
#include "../Fraction.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
		TEST_METHOD(FractionTestGetNumPositive)
		{
			Fraction a(1, 2, 3);
			Assert::AreEqual(2, a.GetNum());
		}
		TEST_METHOD(FractionTestGetIntegPositive)
		{
			Fraction a(1, 2, 3);
			a.Print();
			Assert::AreEqual(1, a.GetInteg());
		}
		TEST_METHOD(FractionTestGetDenPositive)
		{
			Fraction a(1, 2, 3);
			Assert::AreEqual(3, a.GetDen());
		}
		TEST_METHOD(ProverkaOperatorov1)
		{
			Fraction a(9, 2, 5);
			Fraction b(2, 1, 4);
			a = a-- + 23 - ++a + 3 * a++ / --a - 3 / a + 2 * a;
			int c = (a < 1) + (a <= 2) + (a > 1) + (a >= 2) + (1 < a) + (1 > a) + (1 <= a) + (1 >= a);
			a += c;
			a -= 1;
			a /= 1;
			a *= 2;
			a += b;
			b -= a;
			Assert::AreEqual(95, a.GetInteg());
		}
		TEST_METHOD(ProverkaOperatorov2)
		{
			Fraction a(9, 2, 5);
			Fraction b(2, 1, 4);
			a.Print();
			a = b + a / b * a - a;
			a += (b < a) + (b > a) - (b >= a) / (b <= a);
			Assert::AreEqual(900, a.GetDen());
		}
		TEST_METHOD(TestConvert)
		{
			Fraction a(9, 2, 5);
			double c = 3./2;
			a.SetDen(2);
			a.SetNum(1);
			a.SetInteg(1);
			Assert::AreEqual(c, a.Convert());
		}
		TEST_METHOD(TestMultiplicationAndDivision)
		{
			Fraction a(9, 2, 5);
			Fraction b(2, 1, 4);
			b /= a;
			a *= b;
			Assert::AreEqual(940, a.GetDen());
		}
	public:		
	};
}
