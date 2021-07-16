#include <chrono>
#include "Logger.h"

#define S (string)

static HANDLE consoleOutput = 0;

std::string Logger::digitize(int num, int r)
{
	std::string str = std::to_string(num);
	size_t digitsDiff = std::to_string(r).size() - str.size();
	if (num < std::pow(10, r)) {
		for (size_t i = 0; i < digitsDiff; i++) {
			str = "0" + str;
		}
	}
	return str;
}

void Logger::log(std::string function, int line, WORD color, std::string original)
{
	// COLOR SETTINGS

	CONSOLE_SCREEN_BUFFER_INFO info;

	if (color != -1) {
		GetConsoleScreenBufferInfo(consoleOutput, &info);
		SetConsoleTextAttribute(consoleOutput, color);
	}

	std::string f;

	// INITIALIZE TIME

	/*time_t timeNow;
	time(&timeNow);
	tm lt;
	localtime_s(&lt, &timeNow);

	// TIME SETUP

	f += "[" + digitize(lt.tm_hour, 2) +
		":" + digitize(lt.tm_min, 2) +
		":" + digitize(lt.tm_sec, 2) +
		"] ";*/

	// FUNCTION:LINE

	f += "(";
	f += function + S":" + std::to_string(line) + S") " + original;

	// MAIN

	std::cout << f << "\n";

	// RESTORE

	if (color != -1) {
		SetConsoleTextAttribute(consoleOutput, info.wAttributes);
	}
}

void Logger::init()
{
	consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
}
