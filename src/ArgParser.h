//
// Created by Steven Imle on 11/14/16.
//

#ifndef COMP_3270_ARGPARSER_H
#define COMP_3270_ARGPARSER_H


#include <string>

class ArgParser {
private:
	std::string file_name_input;
	std::string file_name_output;
	std::string file_name_time;
public:
	ArgParser(int argc, char *argv[]);

	const std::string &getFileNameInput() const;

	const std::string &getFileNameOutput() const;

	const std::string &getFileNameTime() const;
};


#endif //COMP_3270_ARGPARSER_H
