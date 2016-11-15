//
// Created by Steven Imle on 10/24/16.
//

#include <cstdlib>
#include "Strat1.h"

int Strat1::run(std::vector<int> values, size_t &index_l, size_t &index_r) {
	if (values.size() == 0) {
		std::exit(1);
	}

	int smallest = values[0], current = 0;
	size_t ind_l = 0, ind_r = values.size() - 1;

	if (values.size() != 1) {
		for (size_t i = 0; i < values.size(); i++) {
			for (size_t j = i; j < values.size(); j++) {
				for (size_t k = i; k <= j; k++) {
					current += values[k];
				}

				if (smallest > current) {
					smallest = current;
					ind_l = i;
					ind_r = j;
				}

				current = 0;
			}
		}
	}

	this->smallest = smallest;
	this->range.first = ind_l;
	this->range.second = ind_r;

	index_l = ind_l;
	index_r = ind_r;

	return smallest;
}
