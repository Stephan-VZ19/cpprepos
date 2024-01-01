#include "gtest/gtest.h"
#include "../PostfixInterpreter/VariadicInterpreter.hpp"

using namespace VariadicInterpreter;

namespace UnitTestVariadicInterpreter {
	TEST(Variadic,TestIntegerInterpreter) {
		PostfixInterpreter<int> interpreter;
		const int sol = interpreter.evaluate(3, 2, std::plus<int>(), 4, std::divides<int>());
		ASSERT_EQ(1, sol);
	}

	TEST(Variadic,TestDoubleInterpreter) {
		PostfixInterpreter<double> interpreter;
		const double sol = interpreter.evaluate(3.0, 2.0, std::plus<double>(), 4.0, std::divides<double>());
		ASSERT_EQ(1.25, sol);
	}

	TEST(Variadic,TestLongInterpreter) {
		PostfixInterpreter<long long> interpreter;
		const long long sol = interpreter.evaluate(3LL, 1LL, std::plus<long long>(), 5LL, std::minus<long long>(), 2LL, 4LL, std::minus<long long>(), std::plus<long long>());
		ASSERT_EQ(-3LL, sol);
	}

	TEST(Variadic,TestSingleElement) {
		PostfixInterpreter<int> interpreter;
		const int sol = interpreter.evaluate(100);
		ASSERT_EQ(100, sol);
	}

}
