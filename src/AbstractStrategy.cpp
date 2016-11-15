//
// Created by Steven Imle on 10/24/16.
//

#include <iostream>
#include "AbstractStrategy.h"

void AbstractStrategy::printFinalValues(void) {
	std::cout << "smallest: " << this->smallest << std::endl;
	std::cout << "range: (" << this->range.first << ", " << this->range.second << ")" << std::endl;
}
