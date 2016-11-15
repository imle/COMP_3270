//
// Created by Steven Imle on 11/14/16.
//

#include "ArgParser.h"

ArgParser::ArgParser(int argc, char *argv[]) {
	this->file_name_input = "input.txt";
	this->file_name_output = "output.txt";
}

const std::string &ArgParser::getFileNameInput() const {
	return file_name_input;
}

const std::string &ArgParser::getFileNameOutput() const {
	return file_name_output;
}
