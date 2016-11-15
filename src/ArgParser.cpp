//
// Created by Steven Imle on 11/14/16.
//

#include "ArgParser.h"

ArgParser::ArgParser(int argc, char *argv[]) {
	this->file_name_input = "input.txt";
	this->file_name_output = "output.txt";
	this->file_name_time = "time.txt";
}

const std::string &ArgParser::getFileNameInput() const {
	return file_name_input;
}

const std::string &ArgParser::getFileNameOutput() const {
	return file_name_output;
}

const std::string &ArgParser::getFileNameTime() const {
	return file_name_time;
}
