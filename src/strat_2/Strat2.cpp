//
// Created by Steven Imle on 11/14/16.
//

#include <vector>
#include <cstdlib>
#include "Strat2.h"

int Strat2::run(std::vector<int> values, size_t &index_l, size_t &index_r) {
	if (values.size() == 0) {
		std::exit(1);
	}

	int smallest = values[0], current = 0;

	if (values.size() == 1) {
		return smallest;
	}

	std::vector<size_t> negative_indices;
	size_t ind_l = 0, ind_r = values.size() - 1;

	for (size_t i = 0; i < values.size(); i++) {
		if (values[i] < 0) {
			negative_indices.push_back(i);
		}
	}

	for (size_t i = 0; i < negative_indices.size(); i++) {
		for (size_t j = i; j < negative_indices.size(); j++) {
			for (size_t k = negative_indices[i]; k < negative_indices[j]; k++) {
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

	this->smallest = smallest;
	this->range.first = ind_l;
	this->range.second = ind_r;

	index_l = ind_l;
	index_r = ind_r;

	return smallest;
}
