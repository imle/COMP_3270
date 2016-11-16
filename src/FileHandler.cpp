//
// Created by Steven Imle on 11/14/16.
//

#include <sstream>
#include <fstream>
#include "FileHandler.h"
#include "err_codes.h"

FileHandler::FileHandler(const std::string &fn_input, const std::string &fn_output, const std::string &fn_time) {
	this->file_name_input = fn_input;
	this->file_name_output = fn_output;
	this->file_name_time = fn_time;

	std::ofstream out_file;
	out_file.open(this->file_name_output, std::ofstream::out | std::ofstream::trunc);
	out_file.close();

	out_file.open(this->file_name_time, std::ofstream::out | std::ofstream::trunc);
	out_file.close();
}

std::vector<int> FileHandler::getInputValues() {
	std::ifstream in_file(this->file_name_input);

	if (!in_file.is_open()) {
		printErrorAndExit(INPUT_FILE_NOT_FOUND);
	}

	std::vector<int> result;
	std::string line;
	std::getline(in_file, line);

	int length = std::stoi(line);

	std::getline(in_file, line);
	in_file.close();

	std::stringstream line_stream(line);
	std::string value;

	while (std::getline(line_stream, value, ',')) {
		result.push_back(std::stoi(value));
	}

	if (length != result.size()) {
		printErrorAndExit(FILE_FORMAT_INVALID);
	}

	return result;
}

void FileHandler::addOutputValues(int smallest, size_t index_l, size_t index_r) {
	std::ofstream out_file;
	out_file.open(this->file_name_output, std::ofstream::out | std::ofstream::app);

	out_file << smallest << ", " << index_l << ", " << index_r << std::endl;

	out_file.close();
}

void FileHandler::addTimeValues(std::vector<double> strat_time) {
	std::ofstream out_file;
	out_file.open(this->file_name_time, std::ofstream::out | std::ofstream::app);

	for (std::vector<double>::iterator iter_st = strat_time.begin(); iter_st != strat_time.end(); iter_st++) {
		out_file << std::fixed << *iter_st << std::scientific;

		if (iter_st + 1 != strat_time.end()) {
			out_file << ", ";
		}
	}

	out_file << std::endl;

	out_file.close();
}
