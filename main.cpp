#include <iostream>
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

	std::vector<int> values = fh->getInputValues();

	int smallest;
	size_t ind_l;
	size_t ind_r;

	Strat1 *s1 = new Strat1();
	Strat2 *s2 = new Strat2();
	Strat3 *s3 = new Strat3();

	smallest = s1->run(values, ind_l, ind_r);
	fh->addOutputValues(smallest, ind_l, ind_r);

	smallest = s2->run(values, ind_l, ind_r);
	fh->addOutputValues(smallest, ind_l, ind_r);

	smallest = s3->run(values, ind_l, ind_r);
	fh->addOutputValues(smallest, ind_l, ind_r);

	std::vector<int> size_set = { 100, 500, 1000,
	                              1500, 2000, 2500,
	                              3000, 3500, 4000,
	                              4500, 5000, 5500,
	                              6000, 6500, 7000,
	                              7500, 8000, 8500,
	                              9000, 9500, 10000
	};

	StrategyTester *st = new StrategyTester();
	st->addStrategy(s1);
	st->addStrategy(s2);
	st->addStrategy(s3);

	for (std::vector<int>::iterator iter = size_set.begin(); iter != size_set.end(); iter++) {
		values = vg->genRandomValues(*iter);

		st->runTest(values);
	}

	strategy_time_map times = st->getTimeValues();

	for (strategy_time_map::iterator iter = times.begin(); iter != times.end(); iter++) {
		fh->addTimeValues((*iter).second);
	}

	return 0;
}