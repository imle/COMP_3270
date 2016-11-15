//
// Created by Steven Imle on 11/15/16.
//

#ifndef COMP_3270_STRATEGYTESTER_H
#define COMP_3270_STRATEGYTESTER_H


#include <map>
#include "AbstractStrategy.h"


typedef std::map<AbstractStrategy *, std::vector<double>> strategy_time_map;

class StrategyTester {
	const int RUN_COUNT = 50;

private:
	std::vector<AbstractStrategy *> strats;
	strategy_time_map time;

public:
	void addStrategy(AbstractStrategy *strategy);

	void runTest(std::vector<int> values);

	strategy_time_map getTimeValues();
};


#endif //COMP_3270_STRATEGYTESTER_H
