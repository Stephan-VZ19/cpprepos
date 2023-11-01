#include <iostream>

struct Mutex {
	bool m_locked = false;

	void lock() {
		m_locked = true;
	}

	void unlock() {
		m_locked = false;
	}
};