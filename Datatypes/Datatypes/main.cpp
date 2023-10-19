#include <iostream>
#include <cstdint>
#include <cassert>

enum class TicketStatus {
	open, inProgress, done
};

enum class TaskStatus {
	open, inProgress, review, done
};

std::ostream& operator<<(std::ostream& os, const TicketStatus& st) {
	switch (st) {
		case TicketStatus::open:
			return os << "open";
		case TicketStatus::inProgress:
			return os << "inProgress";
		case TicketStatus::done:
			return os << "done";
		default:
			assert(false);
	}
}

int main() {
	TicketStatus st1 = (TicketStatus) 0;
	st1 = TicketStatus::inProgress;
	TaskStatus st2 = TaskStatus::open;
	std::cout << st1 << std::endl;
	std::cout << (int) st2 << std::endl;
}