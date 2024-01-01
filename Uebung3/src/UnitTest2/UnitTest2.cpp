#include "gtest/gtest.h"
#include "../PostfixInterpreter/GenericInterpreter.hpp"

using namespace GenericInterpreter;

namespace UnitTestGenericInterpreter {

	TEST(ConvertString, TestConvertStringInt) {
		const int value = convertString<int>("100");
		ASSERT_EQ(100, value);
	}

	TEST(ConvertString, TestConvertStringDouble) {
		const double value = convertString<double>("100");
		ASSERT_EQ(100.0, value);
	}

	TEST(ConvertString, TestConvertStringLong) {
		const long long value = convertString<long long>("100");
		ASSERT_EQ(100LL, value);
	}

	TEST(ConvertString, TestConvertStringFloat) {
		const float value = convertString<float>("100");
		ASSERT_EQ(100.0f, value);
	}
	TEST(ConvertString, TestIntegerInterpreter) {
		PostfixInterpreter<int> interpreter;
		const int sol = interpreter.evaluate({ "3", "2", "+", "4", "/" });
		ASSERT_EQ(1, sol);
	}

	TEST(ConvertString, TestDoubleInterpreter) {
		PostfixInterpreter<double> interpreter;
		const double sol = interpreter.evaluate({ "3", "2", "+", "4", "/" });
		ASSERT_EQ(1.25, sol);
	}

	TEST(ConvertString, TestLongInterpreter) {
		PostfixInterpreter<long long> interpreter;
		const long long sol = interpreter.evaluate({ "3", "2", "+", "4", "/" });
		ASSERT_EQ(1LL, sol);
	}

	TEST(ConvertString, TestFloatInterpreter) {
		PostfixInterpreter<float> interpreter;
		const float sol = interpreter.evaluate({ "3", "2", "+", "4", "/" });
		ASSERT_EQ(1.25f, sol);
	}

	TEST(ConvertString, TestSingleElement) {
		PostfixInterpreter<int> interpreter;
		const int sol = interpreter.evaluate({ "100" });
		ASSERT_EQ(100, sol);
	}

}