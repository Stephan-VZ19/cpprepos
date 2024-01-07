#include <iostream>
#include <vector>
#include <string>
#include <stack>

int main() {
	std::cout << "Hallo" << std::endl;


	std::vector<std::string> tok {"1", "3", "5", "/", "*", "+", "-"};

	std::cout << std::stoi(tok[2]) << std::endl;

	bool b = "/" == "/";

	std::cout << b << std::endl;

	std::stack<std::string> stk;
	stk.push("2");

	auto t = stk.top();

	std::cout << t << std::endl;

}