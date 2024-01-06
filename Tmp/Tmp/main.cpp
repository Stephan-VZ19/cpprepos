#include <iostream>
#include <vector>
#include <string>

int main() {
	std::cout << "Hallo" << std::endl;


	std::vector<std::string> tok {"1", "3", "5", "/", "*", "+", "-"};

	std::cout << std::stoi(tok[2]) << std::endl;

	bool b = "/" == "/";

	std::cout << b << std::endl;


}