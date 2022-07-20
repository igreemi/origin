#include "counter.h"

int count = 0;

	int Counter::plus() {
		return count++;
	}

	int Counter::minus() {
		return count--;
	}

	int Counter::stat() {
		return count;
	}
	//--------------------------------------

	Counter::Counter(int num) {
		this->count = num;
	}
