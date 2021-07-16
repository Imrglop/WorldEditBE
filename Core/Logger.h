#pragma once

#include "shared.h"
#include <sstream>

#define logFC(col, ...) Logger::log(__func__, __LINE__, col, __VA_ARGS__)
#define logF(...) Logger::log(__func__, __LINE__, -1, __VA_ARGS__)
#define logLC(col, items) Logger::log(__func__, __LINE__, col, (std::ostringstream() << items).str())
#define logL(items) Logger::log(__func__, __LINE__, -1, (std::ostringstream() << items).str())


class Logger
{
public:
	static std::string digitize(int num, int r = 2);
	static void log(std::string function, int line, WORD color, std::string original);
	static void init();
};

