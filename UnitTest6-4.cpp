#include "pch.h"
#include "CppUnitTest.h"
#include"C:\Users\Софія\source\repos\lab6-4\lab6-4\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64
{
	TEST_CLASS(UnitTest64)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int mas[3] = { 1,2,3 };
			Assert::AreEqual(mas[2], 3);
		}
	};
}
