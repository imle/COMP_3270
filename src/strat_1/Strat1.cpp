//
// Created by Steven Imle on 10/24/16.
//

#include "Strat1.h"

int Strat1::run(int *int_arr, size_t count, size_t &index_l, size_t &index_r) {
	int smallest = NULL, current = 0;

	for (size_t i = 0; i < count; i++) {
		for (size_t j = i; j < count; j++) {
			for (size_t k = i; k < j; k++) {
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
