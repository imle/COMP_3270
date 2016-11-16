//
// Created by Steven Imle on 11/15/16.
//

#include "StrategyTester.h"
#include <chrono>
#include <sstream>

void StrategyTester::addStrategy(AbstractStrategy *strategy, const std::string strat_name) {
	this->strats.push_back(strategy);
	this->strat_names[strategy] = strat_name;

	this->time[strategy] = std::vector<double>();
}

void StrategyTester::runTest(std::vector<int> values) {
	std::stringstream s;

	for (std::vector<AbstractStrategy*>::iterator iter = this->strats.begin(); iter != this->strats.end(); iter++) {
		size_t ind_l = 0, ind_r = 0;
		std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

		s << "Running: " << this->strat_names[*iter];
		logger->info(s.str());
		s.str("");

		for (int i = 0; i < this->RUN_COUNT; i++) {
			(*iter)->run(values, ind_l, ind_r);
		}

		s << "Finished: " << this->strat_names[*iter];
		logger->info(s.str());
		s.str("");

		std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

		double total_time = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() / this->RUN_COUNT;

		this->time[*iter].push_back(total_time);
	}
}

strategy_time_map StrategyTester::getTimeValues() {
	return this->time;
}

StrategyTester::StrategyTester(Logger *logger) {
	this->logger = logger;
}
