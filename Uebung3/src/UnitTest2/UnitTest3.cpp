#include "gtest/gtest.h"
#include "../PostfixInterpreter/GenericInterpreter.hpp"

using namespace GenericInterpreter;

namespace UnitTestGenericInterpreter {
	TEST(Generic, TestIncrementOperation1) {
		PostfixInterpreter<float> interpreter;
		const float sol = interpreter.evaluate({ "3", "2", "+", "4", "/", "++", "++" });
		ASSERT_EQ(3.25f, sol);
	}

	TEST(Generic, TestIncrementOperation2) {
		PostfixInterpreter<int> interpreter;
		const int sol = interpreter.evaluate({ "3", "++", "-3", "+", "++", "6", "*" });
		ASSERT_EQ(12, sol);
	}

}
