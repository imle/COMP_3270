//
// Created by Steven Imle on 11/14/16.
//

#ifndef COMP_3270_FILEHANDLER_H
#define COMP_3270_FILEHANDLER_H


#include <string>
#include <vector>

class FileHandler {
public:
	FileHandler(const std::string &fn_input, const std::string &fn_output, const std::string &fn_time);

	std::vector<int> getInputValues();

	void addOutputValues(int smallest, size_t index_l, size_t index_r);

	void addTimeValues(std::vector<double> strat_time);

private:
	std::string file_name_input;
	std::string file_name_output;
	std::string file_name_time;

};


#endif //COMP_3270_FILEHANDLER_H
