#include "CppUnitTest.h"
#include "../PostfixInterpreter/GenericInterpreter.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace GenericInterpreter;

namespace UnitTestGenericInterpreter {
	TEST_CLASS(UnitTestGenericInterpreter) {
public:

	TEST_METHOD(TestIncrementOperation1) {
		PostfixInterpreter<float> interpreter;
		const float sol = interpreter.evaluate({ "3", "2", "+", "4", "/", "++", "++" });
		Assert::AreEqual(3.25f, sol);
	}

	TEST_METHOD(TestIncrementOperation2) {
		PostfixInterpreter<int> interpreter;
		const int sol = interpreter.evaluate({ "3", "++", "-3", "+", "++", "6", "*" });
		Assert::AreEqual(12, sol);
	}

	};

}
