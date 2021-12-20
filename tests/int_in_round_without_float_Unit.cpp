#include "pch.h"
#include "CppUnitTest.h"
#include "..\int_in_round_without_float.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(sqrti1)
	{
	public:
		
		TEST_METHOD(TestMethod1){
			Assert::IsTrue(sqrti(0) == 0);
			Assert::IsTrue(sqrti(1) == 1);
		}
		TEST_METHOD(TestMethod2) {
			Assert::IsTrue(sqrti(1024) == 32);
		}
		TEST_METHOD(TestMethod3) {
			Assert::IsTrue(sqrti(83521) == 289);
		}
		TEST_METHOD(TestMethod4) {
			Assert::IsTrue(sqrti(9223372030926249001) == 3037000499);
		}
	};
	TEST_CLASS(main1)
	{
	public:

		TEST_METHOD(TestMethod1) {
			Assert::IsTrue(answer(0) == 1);
			Assert::IsTrue(answer(1) == 5);
		}
		TEST_METHOD(TestMethod2) {
			Assert::IsTrue(answer(3) == 29);
		}
		TEST_METHOD(TestMethod3) {
			Assert::IsTrue(answer(5) == 81);
		}
	};
}
