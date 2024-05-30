#include "pch.h"
#include "CppUnitTest.h"
#include "../mai/processing.h"
#include<cstring>
#include<vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	Precipitation* build_prec(int d, int m, double a, char charac[50]) {
		Precipitation* prec = new Precipitation;
		prec->day = d;
		prec->month = m;
		prec->amount = a;
		strcpy_s(prec->characteristic, charac);
		return prec;
	}
	void delete_prec(vector<Precipitation*>& array)
	{
		for (auto precs : array) {
			delete precs;
		}
		array.clear();
	}
	TEST_CLASS(UnitTest1)
	{

	public:
		
		TEST_METHOD(TestMethod1)
		{
			vector<Precipitation*>precs;
			precs.push_back(build_prec(12, 5, 2.4, "дождь"));
			precs.push_back(build_prec(15, 7, 1.2, "дождь"));
			precs.push_back(build_prec(21, 1, 3.4, "снег"));
			precs.push_back(build_prec(10, 5, 2.4, "град"));
			precs.push_back(build_prec(21, 7, 1.9, "дождь"));
			precs.push_back(build_prec(2, 12, 3.4, "снег"));
			Assert::AreEqual(4.8, process(precs, 5));
			delete_prec(precs);
		}
		TEST_METHOD(TestMethod2)
		{
			vector<Precipitation*>precs;
			precs.push_back(build_prec(21, 4, 1.4, "дождь"));
			precs.push_back(build_prec(15, 8, 4.2, "дождь"));
			precs.push_back(build_prec(14, 2, 3.4, "снег"));
			precs.push_back(build_prec(2, 7, 2.0, "дождь"));
			precs.push_back(build_prec(1, 2, 1.4, "снег"));
			precs.push_back(build_prec(24, 2, 3.4, "снег"));
			Assert::AreEqual(8.2, process(precs, 2));
			delete_prec(precs);
		}
		TEST_METHOD(TestMethod3)
		{
			vector<Precipitation*>precs;
			precs.push_back(build_prec(21, 4, 1.4, "дождь"));
			precs.push_back(build_prec(15, 8, 4.2, "дождь"));
			precs.push_back(build_prec(14, 2, 3.4, "снег"));
			precs.push_back(build_prec(2, 7, 2.0, "дождь"));
			precs.push_back(build_prec(1, 2, 1.4, "снег"));
			precs.push_back(build_prec(24, 2, 3.4, "снег"));
			Assert::AreEqual(0.0, process(precs, 5));
			delete_prec(precs);
		}
	};
}
