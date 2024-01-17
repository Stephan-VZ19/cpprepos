#include "Person.h"
#include <stdexcept>
#include <iostream>

int main() {
	try {
		{
			// test writing
			FileStorage fs1(std::cout);
			FileStorage fs2("fs.txt", FileStorage::Write);

			Person hanspi("Hans Peter", false,
				Address("Bahnhofstrasse", 6, "Windisch"));
			Person moni("Monika", true,
				Address("Steinackerstrasse", 43, "Windisch"));

			fs1 << "hanspi" << hanspi;
			fs1 << "moni" << moni;

			fs2 << "hanspi" << hanspi;
			fs2 << "moni" << moni;
		}
		{
			// test reading
			FileStorage fs("fs.txt", FileStorage::Read);

			auto& m = fs["moni"];
			std::string name;
			m["name"] >> name;
			std::cout << name << std::endl;
			Address a;
			m["address"] >> a;

			Person p;
			fs["hanspi"] >> p;
		}
	}
	catch (std::runtime_error& ex) {
		std::cout << ex.what() << std::endl;
	}
}