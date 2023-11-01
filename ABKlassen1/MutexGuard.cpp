#include <iostream>
#include "Mutex.cpp"
#include <memory>


class MutexGuard {
	std::unique_ptr<Mutex> mut;

public:
	MutexGuard() {
		mut = std::make_unique<Mutex>();
	}
	~MutexGuard() {
		lock();
		std::cout << "dtor" << std::endl;
	}
	void lock() {
		mut.get()->lock();
		std::cout << "lock" << std::endl;
	}
	void unlock() {
		mut.get()->unlock();
		std::cout << "unlock" << std::endl;
	}
};