// from https://github.com/Imrglop/Latite/ 
// from https://github.com/Imrglop/PlatinumBDS/ 

#include "Config.h"
#include <fstream>
#include <iostream>
using std::vector;

namespace sa_utils {
	std::vector<std::string> splitString(std::string str, char delim) {
		vector<std::string> retVal = {};
		std::istringstream split(str);
		for (std::string each; std::getline(split, each, delim); retVal.push_back(each));
		return retVal;
	}
}

#define log std::cout<<"[Config] "
#define CONFIG_DEBUG false

using std::string;
using std::fstream;
using std::vector;

char splitChar = '=';

// constructor
Config::Config(std::string filePath, std::string defaults)
{
	this->fileDefault = defaults;
	this->filePath = filePath;
}

bool Config::load()
{
	fstream file;
	file.open(this->filePath, std::ios_base::in);
	string finalCollection = "";
	if (file.fail())
	{
		// file failed
		if (errno == ENOENT) {
			log << this->filePath << " doesn't exist, trying to make new one...\n";
			std::ofstream newFile(this->filePath);
			newFile << fileDefault;
			newFile.close();
			std::flush(newFile);
			this->load();
			return true;
		}
		else {
			log << "Couldn't load config! errno: " << errno << "\n";
			return false;
		}
		return false;
	}
	// file is good
	string line = "";
	for (string currentLine; std::getline(file, line);)
	{
		std::istringstream toSplit(line);
		if (line[0] == '#' || line[0] == '!') { // comment
			continue;
		}
		std::vector<string> sl;
		for (std::string each; std::getline(toSplit, each, splitChar);) {
			sl.push_back(each);
		};
		if (sl.size() < 2) continue; // empty line
		vars.insert({ sl[0], sl[1] });
	}
	file.close();
	this->loaded = true;
	return true;
}

int Config::findInList(std::vector<string> list, string item)
{
	for (unsigned int i = 0; i < list.size(); i++)
	{
		if (list[i].compare(item) == 0)
			return i;
	};
	return -1;
}

bool Config::getBool(string key)
{
	auto fli = vars.find(key);
	if (fli == vars.end()) return false;
	return fli->second.compare("true") == 0;
}

int Config::getInteger(string key)
{
	try {
		auto fli = vars.find(key);
		if (fli == vars.end()) return false;
		return std::stoi(fli->second);
	}
	catch (std::exception e)
	{
		log << "Config Error: cannot set " << key << " to integer\n";
		return 0;
	}
}

std::vector<int> Config::getIntegerList(string key)
{
	std::vector<int> retVal = {};
	auto fli = vars.find(key);
	std::vector<string> convertVector = sa_utils::splitString(fli->second, ',');
	for (unsigned int i = 0; i < convertVector.size(); i++)
	{
		try {
			retVal.push_back(std::stoi(convertVector[i]));
		}
		catch (std::exception)
		{
			std::cerr << "[Config] Could not convert string to int! From input: " 
				<< convertVector[i] << "\n at: " << this->filePath << std::endl;
			break;
		}
	}
	return retVal;
}

float Config::getNumber(string key)
{
	try {
		auto fli = vars.find(key);
		if (fli == vars.end()) return 0.0f;
		return std::stof(fli->second);
	}
	catch (std::exception e) {
		log << "Config Error: cannot set " << key << " to number\n";
		return 0.f;
	}
}

unsigned char Config::getByte(string key)
{
	try {
		auto fli = vars.find(key);
		if (fli == vars.end()) return false;
		return (unsigned char)std::stoi(fli->second);
	}
	catch (std::exception e)
	{
		log << "Config Error: cannot set " << key << " to byte\n";
		return 0ui8;
	}
}

std::vector<string> Config::getKeys()
{
	std::vector<string> retVal;
	for (std::map<string, string>::iterator it = vars.begin(); it != vars.end(); ++it)
	{
		retVal.push_back(it->first);
	}
	return retVal;
}

string Config::getString(string key)
{
	auto fli = vars.find(key);
	auto keys = getKeys();
	if (fli != vars.end()) return fli->second;
	return "";
}

void Config::set(string key, string value, bool reload)
{
	if (this->loaded)
	{
		fstream file;
		file.open(this->filePath, std::ios::in | std::ios::out);

		vector<string> lines = {};
		string line;

		for (string currentLine; std::getline(file, line);)
		{
			lines.push_back(line);
			//log << "Push_back: " << line << '\n';
		}

		file.close();

		// clear file
		std::ofstream tempClear;
		tempClear.open(this->filePath, std::ofstream::out | std::ofstream::trunc);
		tempClear.close();

		// rewrite file
		std::ofstream tempWrite;
		tempWrite.open(this->filePath);
		for (size_t i = 0; i < lines.size(); i++)
		{
#if CONFIG_DEBUG == true
			log << "@@ " << lines[i] << '\n';
#endif
			bool w = false;
			string ln = lines[i];
			if (ln[0] == '#' || ln[0] == '!') { // comment
#if CONFIG_DEBUG == true
				log << "Comment\n";
#endif
				w = true;
			}
			if (!w) {
				std::vector<string> sl = sa_utils::splitString(ln, '=');
				if (sl.size() < 2) {
#if CONFIG_DEBUG == true
					log << "SL is less than 2; rewrite\n";
#endif
					w = true;
				}
				else {
					if (sl[0] == key) {
						tempWrite << (key + "=" + value) << '\n';
#if CONFIG_DEBUG == true
						log << "Key matched! " << key << " & " << sl[0] << std::endl;
#endif
					}
					else {
#if CONFIG_DEBUG == true
						log << "Key not matched: " << sl[0] << " & " << key << std::endl;
#endif
						w = true;
					}
				}
			}
			if (w) {
#if CONFIG_DEBUG == true
				log << "Write: " << (ln + "\n");
#endif
				tempWrite << ln << "\n";
			}
		}
		tempWrite.close();
		std::flush(tempWrite);
		this->load();
	}
}