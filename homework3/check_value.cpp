#include <iostream>
#include "random_value.h"
#include "check_value.h"

int check_value() {

	const int target_value = random_value();
	int current_value = 0;
	bool not_win = true;
	int attempts_count = 0;

	do {
		std::cout << "Enter your guess:" << std::endl;
		std::cin >> current_value;
		++attempts_count;

		if (current_value > target_value) {
			std::cout << "less than " << current_value << std::endl;
		}
		else if (current_value < target_value) {
			std::cout << "greater than " << current_value << std::endl;
		}
		else {
			std::cout << "you win!" << std::endl;
			not_win=false;
		}

	} while(not_win);

	return attempts_count;
}