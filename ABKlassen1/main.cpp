#include <iostream>
#include "Mutex.cpp"
#include "MutexGuard.cpp"

int main() {
	
	auto mg = new MutexGuard();

	mg->unlock();
	mg->lock();

	delete(mg);

}