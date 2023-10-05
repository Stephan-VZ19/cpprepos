#pragma once
#include <iostream>
#include <string>

class Person {
	std::string m_name;
	int m_age;

public:
	Person(const std::string& name, int age)
		: m_name(name)
		, m_age(age)
	{}

	std::string getName() const;

	void setAge(int age);

	int getAge() const;

	friend std::ostream& operator<<(std::ostream& os, const Person& p) {
		return os << p.m_name << " ist " << p.m_age << " Jahre alt.";
	}
};