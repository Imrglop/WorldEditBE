#include "FileStorage.h"
#include <fstream>

FileStorage::FileStorage(std::string appData)
{
	this->appDataPath = appData;
}

FileStorage::~FileStorage()
{
	delete this->settings;
}

bool FileStorage::init()
{
	// -------------- DIR --------------

	std::string dir = appDataPath + "\\WorldEdit";
	BOOL result = CreateDirectoryA(dir.c_str(), NULL);
	/*	if (!result) {
			if (result != ERROR_ALREADY_EXISTS) {
				return false;
			}
		}*/
		// -------------- FILES --------------

	std::string settingsFile = dir + "\\settings.txt";
	settings = new Config(settingsFile, "");
	if (!settings->load()) {
		return false;
	}

	isLogFile = settings->getBool("log-to-file");

	return true;
}

Config* FileStorage::getSettings()
{
	return this->settings;
}