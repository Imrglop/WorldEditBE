#pragma once

#include "../Core/shared.h"
#include "../Depends/Config/Config.h"

class FileStorage
{
private:
	Config* settings;
	bool isLogFile = false;
	std::string appDataPath;
public:
	FileStorage(std::string appData);
	~FileStorage();
	bool init();
	Config* getSettings();
};
