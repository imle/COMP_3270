//
// Created by Steven Imle on 11/15/16.
//

#ifndef COMP_3270_LOGGER_H
#define COMP_3270_LOGGER_H


#include <string>

enum LOG_LEVEL {
	LL_EMERGENCY,
	LL_ALERT,
	LL_CRITICAL,
	LL_ERROR,
	LL_WARNING,
	LL_NOTICE,
	LL_INFO,
	LL_DEBUG,
};

class Logger {
public:
	void emergency(const std::string message);

	void alert(const std::string message);

	void critical(const std::string message);

	void error(const std::string message);

	void warning(const std::string message);

	void notice(const std::string message);

	void info(const std::string message);

	void debug(const std::string message);

	virtual void log(LOG_LEVEL level, const std::string message)= 0;

protected:
	const std::string getLogString(LOG_LEVEL level, std::string message);

	const std::string getLevelText(LOG_LEVEL &level) const;

	const std::string getDateString() const;
};

class ConsoleLogger : virtual public Logger {
public:
	void log(LOG_LEVEL level, const std::string message) override;
};

class FileLogger : virtual public Logger {
protected:
	std::string file_name;
public:
	FileLogger(const std::string &file_name);

public:
	void log(LOG_LEVEL level, const std::string message) override;
};

class FileConsoleLogger : virtual public FileLogger, virtual public ConsoleLogger {
public:
	FileConsoleLogger(const std::string &file_name);

	void log(LOG_LEVEL level, const std::string message) override;
};


#endif //COMP_3270_LOGGER_H
