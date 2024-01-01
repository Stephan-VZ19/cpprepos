# CMakeList.txt : CMake project for prcpp, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.14)

set(TARGET_NAME UnitTest2)

# Add source to this project's executable.
add_executable(${TARGET_NAME} "UnitTest1.cpp" "UnitTest2.cpp" "UnitTest3.cpp" "UnitTest4.cpp"
	"../PostfixInterpreter/IntegerInterpreter.h" "../PostfixInterpreter/GenericInterpreter.hpp" "../PostfixInterpreter/VariadicInterpreter.hpp" )
target_link_libraries(${TARGET_NAME} gtest_main)
target_include_directories(${TARGET_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/PostfixInterpreter")
gtest_discover_tests(${TARGET_NAME})