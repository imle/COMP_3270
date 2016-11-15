//
// Created by Steven Imle on 11/14/16.
//

#ifndef COMP_3270_ERR_CODES_H
#define COMP_3270_ERR_CODES_H

#include <cstdlib>
#include <iostream>

enum ERR_CODE {
	INVALID_VALUE_ARRAY,
	FILE_FORMAT_INVALID,
	INPUT_FILE_NOT_FOUND
};

void printErrorAndExit(ERR_CODE err_code);

#endif //COMP_3270_ERR_CODES_H
