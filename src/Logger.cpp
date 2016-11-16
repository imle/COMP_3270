//
// Created by Steven Imle on 11/15/16.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include "Logger.h"

void Logger::emergency(const std::string message) {
	this->log(LL_EMERGENCY, message);
}

void Logger::alert(const std::string message) {
	this->log(LL_ALERT, message);
}

void Logger::critical(const std::string message) {
	this->log(LL_CRITICAL, message);
}

void Logger::error(const std::string message) {
	this->log(LL_ERROR, message);
}

void Logger::warning(const std::string message) {
	this->log(LL_WARNING, message);
}

void Logger::notice(const std::string message) {
	this->log(LL_NOTICE, message);
}

void Logger::info(const std::string message) {
	this->log(LL_INFO, message);
}

void Logger::debug(const std::string message) {
	this->log(LL_DEBUG, message);
}

const std::string Logger::getLogString(LOG_LEVEL level, std::string message) {
	std::stringstream st;

	st << getDateString() << " | ";

	st << getLevelText(level) << ": ";

	st << message;

	return st.str();
}

const std::string Logger::getDateString() const {
	char date[80];
	time_t t = time(0);
	strftime(date, sizeof(date), "%F %T %z", localtime(&t));
	std::stringstream s;
	s << date;
	return s.str();
}

const std::string Logger::getLevelText(LOG_LEVEL &level) const {
	switch (level) {
		case LL_EMERGENCY:
			return "EMERGENCY";
		case LL_ALERT:
			return "ALERT";
		case LL_CRITICAL:
			return "CRITICAL";
		case LL_ERROR:
			return "ERROR";
		case LL_WARNING:
			return "WARNING";
		case LL_NOTICE:
			return "NOTICE";
		case LL_INFO:
			return "INFO";
		case LL_DEBUG:
			return "DEBUG";
		default:
			return "LOG";
	}
}

void ConsoleLogger::log(LOG_LEVEL level, const std::string message) {
	std::cout << this->getLogString(level, message) << std::endl;
}

FileLogger::FileLogger(const std::string &file_name) {
	this->file_name = file_name;

	std::ofstream log_file;
	log_file.open(this->file_name, std::ofstream::out | std::ofstream::trunc);
	log_file.close();
}

void FileLogger::log(LOG_LEVEL level, const std::string message) {
	std::ofstream log_file;
	log_file.open(this->file_name, std::ofstream::out | std::ofstream::app);

	log_file << this->getLogString(level, message) << std::endl;

	log_file.close();
}

FileConsoleLogger::FileConsoleLogger(const std::string &file_name) : FileLogger(file_name) {

}

void FileConsoleLogger::log(LOG_LEVEL level, const std::string message) {
	FileLogger::log(level, message);
	ConsoleLogger::log(level, message);
}
