//
// Created by Steven Imle on 11/14/16.
//

#ifndef COMP_3270_STRAT3_H
#define COMP_3270_STRAT3_H


#include <vector>
#include "../AbstractStrategy.h"

typedef std::vector<int>::iterator vec_iter;

class Strat3 : public AbstractStrategy {
public:
	int run(std::vector<int> values, size_t &index_l, size_t &index_r) override;
};


#endif //COMP_3270_STRAT3_H
