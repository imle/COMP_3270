//
// Created by Steven Imle on 11/15/16.
//

#include "StrategyTester.h"
#include <chrono>
#include <sstream>

void StrategyTester::addStrategy(AbstractStrategy *strategy, const std::string strat_name) {
	std::stringstream s;

	s << "Adding strategy: " << strat_name;
	logger->info(s.str());
	s.str("");

	this->strats.push_back(strategy);
	this->strat_names[strategy] = strat_name;

	this->time[strategy] = std::vector<double>();
}

void StrategyTester::runTest(int size, int run_times) {
	std::stringstream s;

	std::vector<int> values = this->vg->genRandomValues(size);

	for (std::vector<AbstractStrategy*>::iterator iter = this->strats.begin(); iter != this->strats.end(); iter++) {
		size_t ind_l = 0, ind_r = 0;
		double total_time = 0;

		s << "Running: " << this->strat_names[*iter];
		logger->info(s.str());
		s.str("");

		for (int i = 0; i < run_times; i++) {
			std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

			(*iter)->run(values, ind_l, ind_r);

			std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

			total_time += std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
		}

		s << "Finished: " << this->strat_names[*iter];
		logger->info(s.str());
		s.str("");

		total_time /= run_times;

		this->time[*iter].push_back(total_time);
	}
}

void StrategyTester::runTest(int size) {
	this->runTest(size, this->RUN_COUNT);
}

strategy_time_map StrategyTester::getTimeValues() {
	return this->time;
}

StrategyTester::StrategyTester(Logger *logger, ValueGenerator *vg) {
	this->logger = logger;
	this->vg = vg;
}

std::vector<AbstractStrategy *> StrategyTester::getStrategies() {
	return this->strats;
}

std::string StrategyTester::getStrategyName(AbstractStrategy *strategy) {
	return this->strat_names[strategy];
}
