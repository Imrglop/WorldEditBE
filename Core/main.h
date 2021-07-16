#pragma once
#include "../File/FileStorage.h"
#include "../Command/CommandManager.h"

//#define CONSOLE

extern CommandManager* c_CommandMgr;

namespace main {
	void eject();
	FileStorage* getFileStorage();
}