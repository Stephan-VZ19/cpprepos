#include "CppUnitTest.h"
#include "../PostfixInterpreter/GenericInterpreter.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace GenericInterpreter;

namespace UnitTestGenericInterpreter {
	TEST_CLASS(UnitTestGenericInterpreter) {
public:

	TEST_METHOD(TestConvertStringInt) {
		const int value = convertString<int>("100");
		Assert::AreEqual(100, value);
	}

	TEST_METHOD(TestConvertStringDouble) {
		const double value = convertString<double>("100");
		Assert::AreEqual(100.0, value);
	}

	TEST_METHOD(TestConvertStringLong) {
		const long long value = convertString<long long>("100");
		Assert::AreEqual(100LL, value);
	}

	TEST_METHOD(TestConvertStringFloat) {
		const float value = convertString<float>("100");
		Assert::AreEqual(100.0f, value);
	}
	TEST_METHOD(TestIntegerInterpreter) {
		PostfixInterpreter<int> interpreter;
		const int sol = interpreter.evaluate({ "3", "2", "+", "4", "/" });
		Assert::AreEqual(1, sol);
	}

	TEST_METHOD(TestDoubleInterpreter) {
		PostfixInterpreter<double> interpreter;
		const double sol = interpreter.evaluate({ "3", "2", "+", "4", "/" });
		Assert::AreEqual(1.25, sol);
	}

	TEST_METHOD(TestLongInterpreter) {
		PostfixInterpreter<long long> interpreter;
		const long long sol = interpreter.evaluate({ "3", "2", "+", "4", "/" });
		Assert::AreEqual(1LL, sol);
	}

	TEST_METHOD(TestFloatInterpreter) {
		PostfixInterpreter<float> interpreter;
		const float sol = interpreter.evaluate({ "3", "2", "+", "4", "/" });
		Assert::AreEqual(1.25f, sol);
	}

	TEST_METHOD(TestSingleElement) {
		PostfixInterpreter<int> interpreter;
		const int sol = interpreter.evaluate({ "100" });
		Assert::AreEqual(100, sol);
	}

	};

}