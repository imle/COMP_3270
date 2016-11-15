//
// Created by Steven Imle on 11/14/16.
//

#include <cstdlib>
#include "ValueGenerator.h"

std::vector<int> ValueGenerator::genRandomValues(int size, int value_min, int value_max) {
	std::vector<int> values;

	int top = value_max + 1 - value_min;

	for (int i = 0; i < size; i++) {
		values.push_back(std::rand() % top + value_min);
	}

	return values;
}

std::vector<int> ValueGenerator::genRandomValues(int size) {
	return this->genRandomValues(size, -1000, 1000);
}
