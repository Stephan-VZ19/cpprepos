#include "CppUnitTest.h"
#include "../PostfixInterpreter/IntegerInterpreter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace IntegerInterpreter;

namespace UnitTestIntegerInterpreter {
	TEST_CLASS(UnitTestIntegerInterpreter) {
		PostfixInterpreter interpreter;

public:
	TEST_METHOD(TestSimpleEvaluation1) {
		const int sol = interpreter.evaluate({ "3", "2", "+", "2", "*" });

		Assert::AreEqual(10, sol);
	}

	TEST_METHOD(TestSimpleEvaluation2) {
		const int sol = interpreter.evaluate({ "3", "1", "+", "5", "-", "2", "4", "-", "+" });

		Assert::AreEqual(-3, sol);
	}

	TEST_METHOD(TestSimpleEvaluation3) {
		const int sol = interpreter.evaluate({ "5", "-2", "15", "13", "-", "*", "+" });

		Assert::AreEqual(1, sol);
	}

	TEST_METHOD(TestSimpleEvaluation4) {
		const int sol = interpreter.evaluate({ "-3", "-4", "*", "1", "5", "+", "2", "/", "-" });

		Assert::AreEqual(9, sol);
	}

	TEST_METHOD(TestSingleElement) {
		Assert::AreEqual(100, interpreter.evaluate({ "100" }));
	}

	TEST_METHOD(TestMultipleEvaluations) {
		Assert::AreEqual(5, interpreter.evaluate({ "3", "2", "+" }));
		Assert::AreEqual(7, interpreter.evaluate({ "10", "3", "-" }));
	}

	};
}