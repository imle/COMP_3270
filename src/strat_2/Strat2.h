//
// Created by Steven Imle on 11/14/16.
//

#ifndef COMP_3270_STRAT2_H
#define COMP_3270_STRAT2_H


#include "../AbstractStrategy.h"

class Strat2 : public AbstractStrategy {
public:
	int run(int *int_arr, size_t count, size_t &index_l, size_t &index_r) override;
};


#endif //COMP_3270_STRAT2_H
