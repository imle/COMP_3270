//
// Created by Steven Imle on 11/14/16.
//

#ifndef COMP_3270_FILEHANDLER_H
#define COMP_3270_FILEHANDLER_H


#include <string>
#include <vector>

class FileHandler {
public:
	FileHandler(const std::string &file_name_input, const std::string &file_name_output);

	std::vector<int> getInputValues();

private:
	std::string file_name_input;
	std::string file_name_output;

};


#endif //COMP_3270_FILEHANDLER_H
