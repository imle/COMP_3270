//
// Created by Steven Imle on 10/24/16.
//

#ifndef COMP_3270_ABSTRACT_STRATEGY_H
#define COMP_3270_ABSTRACT_STRATEGY_H


#include <utility>
#include <vector>

class AbstractStrategy {
protected:
	int smallest;

	std::pair<size_t, size_t> range;

public:
	void printFinalValues(void);

	virtual int run(std::vector<int> values, size_t &index_l, size_t &index_r) = 0;
};


#endif //COMP_3270_ABSTRACT_STRATEGY_H
