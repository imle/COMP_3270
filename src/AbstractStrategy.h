//
// Created by Steven Imle on 10/24/16.
//

#ifndef COMP_3270_ABSTRACT_STRATEGY_H
#define COMP_3270_ABSTRACT_STRATEGY_H


#include <utility>
#include <vector>

class AbstractStrategy {
public:
	virtual int run(std::vector<int> values, size_t &index_l, size_t &index_r) = 0;
};


#endif //COMP_3270_ABSTRACT_STRATEGY_H
