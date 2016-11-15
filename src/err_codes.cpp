//
// Created by Steven Imle on 11/14/16.
//

#include "err_codes.h"

void printErrorAndExit(ERR_CODE err_code) {
	std::cout << "ERROR:\t";

	switch (err_code) {
		case INVALID_VALUE_ARRAY:
			std::cout << "INVALID_VALUE_ARRAY";
			break;
		case FILE_FORMAT_INVALID:
			std::cout << "FILE_FORMAT_INVALID";
			break;
	}

	std::cout << std::endl;

	std::exit(err_code);
}