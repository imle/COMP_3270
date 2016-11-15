//
// Created by Steven Imle on 11/14/16.
//

#include <sstream>
#include <fstream>
#include "FileHandler.h"
#include "err_codes.h"

FileHandler::FileHandler(const std::string &file_name_input, const std::string &file_name_output) : file_name_input(
		file_name_input), file_name_output(file_name_output) {

}

std::vector<int> FileHandler::getInputValues() {
	std::ifstream in_file (this->file_name_input);

	std::vector<int> result;
	std::string line;
	std::getline(in_file, line);

	int length = std::stoi(line);

	std::getline(in_file, line);
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
