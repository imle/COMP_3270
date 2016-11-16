#include <iostream>
#include <sstream>
#include "src/strat_1/Strat1.h"
#include "src/strat_2/Strat2.h"
#include "src/strat_3/Strat3.h"
#include "src/ArgParser.h"
#include "src/FileHandler.h"
#include "src/ValueGenerator.h"
#include "src/StrategyTester.h"

int main(int argc, char *argv[]) {
	ArgParser *ap = new ArgParser(argc, argv);
	FileHandler *fh = new FileHandler(ap->getFileNameInput(), ap->getFileNameOutput(), ap->getFileNameTime());
	ValueGenerator *vg = new ValueGenerator();
	Logger *logger = new FileConsoleLogger("log.txt");

	std::stringstream s;

	std::vector<int> values = fh->getInputValues();

	int smallest;
	size_t ind_l;
	size_t ind_r;

	AbstractStrategy *s1 = new Strat1();
	AbstractStrategy *s2 = new Strat2();
	AbstractStrategy *s3 = new Strat3();

	StrategyTester *st = new StrategyTester(logger, vg);
	st->addStrategy(s1, "Strat1");
	st->addStrategy(s2, "Strat2");
	st->addStrategy(s3, "Strat3");

	std::vector<AbstractStrategy *> strats = st->getStrategies();

	for (std::vector<AbstractStrategy *>::iterator iter = strats.begin(); iter != strats.end(); iter++) {
		s << "Running file test: " << st->getStrategyName(*iter);
		logger->info(s.str());
		s.str("");

		smallest = (*iter)->run(values, ind_l, ind_r);
		fh->addOutputValues(smallest, ind_l, ind_r);
	}

	std::vector<int> size_set = { 100, 500, 1000,
	                              1500, 2000, 2500,
	                              3000, 3500, 4000,
	                              4500, 5000, 5500,
	                              6000, 6500, 7000,
	                              7500, 8000, 8500,
	                              9000, 9500, 10000
	};

	for (std::vector<int>::iterator iter = size_set.begin(); iter != size_set.end(); iter++) {
		s << "Running Set Size: " << *iter;
		logger->info(s.str());
		s.str("");

		st->runTest(*iter, 100);

		s << "Finished Set Size: " << *iter;
		logger->info(s.str());
		s.str("");
	}

	strategy_time_map times = st->getTimeValues();

	for (strategy_time_map::iterator iter = times.begin(); iter != times.end(); iter++) {
		fh->addTimeValues((*iter).second);
	}

	return 0;
}