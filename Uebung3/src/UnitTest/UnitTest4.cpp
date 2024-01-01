#include "CppUnitTest.h"
#include "../PostfixInterpreter/VariadicInterpreter.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace VariadicInterpreter;

namespace UnitTestVariadicInterpreter {
	TEST_CLASS(UnitTestVariadicInterpreter) {

public:
	TEST_METHOD(TestIntegerInterpreter) {
		PostfixInterpreter<int> interpreter;
		const int sol = interpreter.evaluate(3, 2, std::plus<int>(), 4, std::divides<int>());
		Assert::AreEqual(1, sol);
	}

	TEST_METHOD(TestDoubleInterpreter) {
		PostfixInterpreter<double> interpreter;
		const double sol = interpreter.evaluate(3.0, 2.0, std::plus<double>(), 4.0, std::divides<double>());
		Assert::AreEqual(1.25, sol);
	}

	TEST_METHOD(TestLongInterpreter) {
		PostfixInterpreter<long long> interpreter;
		const long long sol = interpreter.evaluate(3LL, 1LL, std::plus<long long>(), 5LL, std::minus<long long>(), 2LL, 4LL, std::minus<long long>(), std::plus<long long>());
		Assert::AreEqual(-3LL, sol);
	}

	TEST_METHOD(TestSingleElement) {
		PostfixInterpreter<int> interpreter;
		const int sol = interpreter.evaluate(100);
		Assert::AreEqual(100, sol);
	}

	};

}
