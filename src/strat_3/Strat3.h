//
// Created by Steven Imle on 11/14/16.
//

#ifndef COMP_3270_STRAT3_H
#define COMP_3270_STRAT3_H


#include "../AbstractStrategy.h"

class Strat3 : public AbstractStrategy {
public:
	int run(int *int_arr, size_t count, size_t &index_l, size_t &index_r) override;
};


#endif //COMP_3270_STRAT3_H
