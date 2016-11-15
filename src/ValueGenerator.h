//
// Created by Steven Imle on 11/14/16.
//

#ifndef COMP_3270_VALUEGENERATOR_H
#define COMP_3270_VALUEGENERATOR_H


#include <vector>

class ValueGenerator {
public:
	std::vector<int> genRandomValues(int size, int value_min, int value_max);

	std::vector<int> genRandomValues(int size);
};


#endif //COMP_3270_VALUEGENERATOR_H
