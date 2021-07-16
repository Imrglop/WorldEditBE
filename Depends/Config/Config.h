#pragma once
#ifndef CONFIG_H
#define CONFIG_H
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

class Config
{
private:
	std::string filePath = "exampleConfig.txt";
	std::string fileDefault = "# Example Default\n";
	std::map<std::string, std::string> vars;
public:
	bool loaded = false;
	Config(std::string filePath, std::string defaults);
	bool load();
	std::vector<std::string> getKeys();
	std::string getString(std::string key);
	void set(std::string key, std::string value, bool reload = false);
	float getNumber(std::string key);
	unsigned char getByte(std::string key);
	bool getBool(std::string key);
	int getInteger(std::string key);
	std::vector<int> getIntegerList(std::string key);
	int findInList(std::vector<std::string> list, std::string item);
};

#endif
