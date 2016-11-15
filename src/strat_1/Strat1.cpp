//
// Created by Steven Imle on 10/24/16.
//

#include "Strat1.h"

int Strat1::run(std::vector values, size_t &index_l, size_t &index_r) {
	int smallest = NULL, current = 0;
	size_t ind_l = 0, ind_r = values.size() - 1;

	for (size_t i = 0; i < values.size() - 1; i++) {
		for (size_t j = i; j < values.size() - 1; j++) {
			for (size_t k = i; k < j; k++) {
				current += values[k];
			}

			if (smallest == NULL || smallest > current) {
				smallest = current;
				ind_l = i;
				ind_r = j;
			}

			current = 0;
		}
	}

	this->smallest = smallest;
	this->range.first = ind_l;
	this->range.second = ind_r;

	index_l = ind_l;
	index_r = ind_r;

	return smallest;
}
