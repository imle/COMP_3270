//
// Created by Steven Imle on 10/24/16.
//

#ifndef COMP_3270_STRAT1_H
#define COMP_3270_STRAT1_H


#include <vector>
#include "../AbstractStrategy.h"

class Strat1 : public AbstractStrategy {
public:
	int run(std::vector values, size_t &index_l, size_t &index_r) override;
};


#endif //COMP_3270_STRAT1_H
