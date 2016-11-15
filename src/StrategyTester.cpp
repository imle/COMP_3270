//
// Created by Steven Imle on 11/15/16.
//

#include "StrategyTester.h"
#include <chrono>

void StrategyTester::addStrategy(AbstractStrategy *strategy) {
	this->strats.push_back(strategy);

	this->time[strategy] = std::vector<double>();
}

void StrategyTester::runTest(std::vector<int> values) {
	for (std::vector<AbstractStrategy*>::iterator iter = this->strats.begin(); iter != this->strats.end(); iter++) {
		size_t ind_l = 0, ind_r = 0;
		std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

		for (int i = 0; i < this->RUN_COUNT; i++) {
			(*iter)->run(values, ind_l, ind_r);
		}

		std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

		double total_time = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() / this->RUN_COUNT;

		this->time[*iter].push_back(total_time);
	}
}

strategy_time_map StrategyTester::getTimeValues() {
	return this->time;
}
