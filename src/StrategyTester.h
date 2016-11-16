//
// Created by Steven Imle on 11/15/16.
//

#ifndef COMP_3270_STRATEGYTESTER_H
#define COMP_3270_STRATEGYTESTER_H


#include <map>
#include "AbstractStrategy.h"
#include "Logger.h"


typedef std::map<AbstractStrategy *, std::vector<double>> strategy_time_map;

class StrategyTester {
	const int RUN_COUNT = 5;

private:
	Logger *logger;

	std::vector<AbstractStrategy *> strats;
	std::map<AbstractStrategy *, std::string> strat_names;
	strategy_time_map time;

public:
	StrategyTester(Logger *logger);

	void addStrategy(AbstractStrategy *strategy, const std::string strat_name);

	void runTest(std::vector<int> values);

	strategy_time_map getTimeValues();
};


#endif //COMP_3270_STRATEGYTESTER_H
