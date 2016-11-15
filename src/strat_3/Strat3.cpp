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

	size_t ind_l = 0, ind_r = values.size() - 1;

	int smallest = this->recursive_call(values.begin(), values.end(), ind_l, ind_r);

	ind_l -= 1;
	ind_r -= 1;

	index_l = ind_l;
	index_r = ind_r;

	this->smallest = smallest;
	this->range.first = ind_l;
	this->range.second = ind_r;

	return smallest;
}

int Strat3::recursive_call(vec_iter left, vec_iter right, size_t &index_l, size_t &index_r) {
	int smallest, current = 0;
	size_t ind_l = 0, ind_r = (size_t)(right - left - 1);

	if (right - left == 1) {
		smallest = *left;
		index_l = ind_l + 1;
		index_r = ind_r + 1;

		return smallest;
	}

	for (vec_iter cur = left; cur != right; ++cur) {
		current += *cur;
	}

	int top_smallest;
	size_t top_ind_l, top_ind_r;

	int bot_smallest;
	size_t bot_ind_l, bot_ind_r;

	top_smallest = this->recursive_call(left, right - 1, top_ind_l, top_ind_r);
	bot_smallest = this->recursive_call(left + 1, right, bot_ind_l, bot_ind_r);

	if (current < top_smallest && current < bot_smallest) {
		smallest = current;
		index_l = ind_l;
		index_r = ind_r;
	}
	else if (top_smallest < current && top_smallest < bot_smallest) {
		smallest = top_smallest;
		index_l = top_ind_l + 1;
		index_r = top_ind_r + 1;
	}
	else {
		smallest = bot_smallest;
		index_l = bot_ind_l + 1;
		index_r = bot_ind_r + 1;
	}

	return smallest;
}
