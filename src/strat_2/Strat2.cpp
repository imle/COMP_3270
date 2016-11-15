//
// Created by Steven Imle on 11/14/16.
//

#include <cstdlib>
#include "Strat2.h"
#include "../err_codes.h"

int Strat2::run(std::vector<int> values, size_t &index_l, size_t &index_r) {
	if (values.size() == 0) {
		printErrorAndExit(INVALID_VALUE_ARRAY);
	}

	int smallest = values[0], current = 0;
	size_t ind_l = 0, ind_r = values.size() - 1;

	if (values.size() != 1) {
		std::vector<size_t> negative_indices;

		for (size_t i = 0; i < values.size(); i++) {
			if (values[i] < 0) {
				negative_indices.push_back(i);
			}
		}

		for (size_t i = 0; i < negative_indices.size(); i++) {
			for (size_t j = i; j < negative_indices.size(); j++) {
				size_t temp_ind_l = negative_indices[i],
						temp_ind_r = negative_indices[j];

				for (size_t k = temp_ind_l; k <= temp_ind_r; k++) {
					current += values[k];
				}

				if (smallest > current) {
					smallest = current;
					ind_l = temp_ind_l;
					ind_r = temp_ind_r;
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
