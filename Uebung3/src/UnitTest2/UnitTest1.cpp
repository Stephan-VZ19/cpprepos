#include "gtest/gtest.h"
#include "../PostfixInterpreter/IntegerInterpreter.h"

using namespace IntegerInterpreter;

namespace UnitTestIntegerInterpreter {
	static PostfixInterpreter interpreter;

	TEST(Postfix, TestSimpleEvaluation1) {
		const int sol = interpreter.evaluate({ "3", "2", "+", "2", "*" });

		ASSERT_EQ(10, sol);
	}

	TEST(Postfix, TestSimpleEvaluation2) {
		const int sol = interpreter.evaluate({ "3", "1", "+", "5", "-", "2", "4", "-", "+" });

		ASSERT_EQ(-3, sol);
	}

	TEST(Postfix, TestSimpleEvaluation3) {
		const int sol = interpreter.evaluate({ "5", "-2", "15", "13", "-", "*", "+" });

		ASSERT_EQ(1, sol);
	}

	TEST(Postfix, TestSimpleEvaluation4) {
		const int sol = interpreter.evaluate({ "-3", "-4", "*", "1", "5", "+", "2", "/", "-" });

		ASSERT_EQ(9, sol);
	}

	TEST(Postfix, TestSingleElement) {
		ASSERT_EQ(100, interpreter.evaluate({ "100" }));
	}

	TEST(Postfix, TestMultipleEvaluations) {
		ASSERT_EQ(5, interpreter.evaluate({ "3", "2", "+" }));
		ASSERT_EQ(7, interpreter.evaluate({ "10", "3", "-" }));
	}
}