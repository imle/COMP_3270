//
// Created by Steven Imle on 10/24/16.
//

#ifndef COMP_3270_ABSTRACT_STRATEGY_H
#define COMP_3270_ABSTRACT_STRATEGY_H


#include <utility>

class AbstractStrategy {
protected:
	int smallest;

	std::pair<int, int> range;

public:
	void printFinalValues(void);

	virtual void run(int *int_arr, size_t count, unsigned int &index_lower, unsigned int &index_higher) = 0;
};


#endif //COMP_3270_ABSTRACT_STRATEGY_H
