//
// Created by Steven Imle on 11/14/16.
//

#include <vector>
#include "Strat2.h"

int Strat2::run(int *int_arr, size_t count, size_t &index_l, size_t &index_r) {
	std::vector<size_t> negative_indices;

	for (size_t i = 0; i < count; i++) {
		if (int_arr[i] < 0) {
			negative_indices.push_back(i);
		}
	}

	int smallest = NULL, current = 0;

	for (size_t i = 0; i < negative_indices.size(); i++) {
		for (size_t j = i; j < negative_indices.size(); j++) {
			for (size_t k = negative_indices[i]; k < negative_indices[j]; k++) {
				current += int_arr[k];
			}

			if (smallest == NULL || smallest > current) {
				smallest = current;
				index_l = i;
				index_r = j;
			}

			current = 0;
		}
	}

	return smallest;
}
