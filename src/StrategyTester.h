//
// Created by Steven Imle on 11/15/16.
//

#ifndef COMP_3270_STRATEGYTESTER_H
#define COMP_3270_STRATEGYTESTER_H


#include <map>
#include "AbstractStrategy.h"
#include "Logger.h"
#include "ValueGenerator.h"


typedef std::map<AbstractStrategy *, std::vector<double>> strategy_time_map;

class StrategyTester {
	const int RUN_COUNT = 5000;

private:
	Logger *logger;
	ValueGenerator *vg;

	std::vector<AbstractStrategy *> strats;
	std::map<AbstractStrategy *, std::string> strat_names;
	strategy_time_map time;

public:
	StrategyTester(Logger *logger, ValueGenerator * vg);

	void addStrategy(AbstractStrategy *strategy, const std::string strat_name);

	void runTest(int size, int run_times);

	void runTest(int size);

	std::vector<AbstractStrategy *> getStrategies();

	strategy_time_map getTimeValues();

	std::string getStrategyName(AbstractStrategy *strategy);
};


#endif //COMP_3270_STRATEGYTESTER_H
