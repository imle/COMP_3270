//
// Created by Steven Imle on 11/14/16.
//

#include <cstdlib>
#include "Strat3.h"
#include "../err_codes.h"

int Strat3::run(std::vector<int> values, size_t &index_l, size_t &index_r) {
	if (values.size() == 0) {
		printErrorAndExit(INVALID_VALUE_ARRAY);
	}

	bool has_negative = false;

	int smallest = values[0];
	size_t ind_l = 0, ind_r = values.size() - 1;

	if (values.size() == 1) {
		return smallest;
	}

	for (size_t i = 0; i < values.size(); i++) {
		if (values[i] < 0) {
			has_negative = true;
			break;
		}

		if (values[i] < smallest) {
			smallest = values[i];
			ind_l = i;
			ind_r = i;
		}
	}

	if (!has_negative) {
		return smallest;
	}

	int smallest_ending_here = 0;
	size_t ind_l_ending_here = 0;

	for (size_t i = 0; i < values.size(); i++) {
		smallest_ending_here += values[i];

		if (smallest_ending_here > 0) {
			smallest_ending_here = 0;
			ind_l_ending_here = i + 1;
		}

		if (smallest > smallest_ending_here) {
			smallest = smallest_ending_here;
			ind_l = ind_l_ending_here;
			ind_r = i;
		}

		if (smallest > values[i]) {
			smallest = values[i];
			ind_l = i;
			ind_r = i;
		}
	}

	index_l = ind_l;
	index_r = ind_r;

	return smallest;
}
