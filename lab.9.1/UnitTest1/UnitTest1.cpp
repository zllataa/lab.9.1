#include "pch.h"
#include "CppUnitTest.h"
#include "../lab.9.1(zavd_1)/lab.9.1(zavd_1).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			
			string PH[] = { "markPHISICS1" , "markPHISICS2" , "markPHISICS3" , "markPHISICS4" };
		
			PH[0] = 4;
			int mark = 5; 
			PH[1] = 3;
			PH[2] = 2;
			PH[3] = 5;

			LineSearch1("hjkhjkj", 5);
			Assert::IsTrue;
		}
	};
}
