#pragma once
#include <iostream>
#include <vector>
#include "Command.h"

#include "Commands/PosCommand.h"
#include "Commands/SetCommand.h"
#include "Commands/CutCommand.h"
#include "Commands/WallsCommand.h"
#include "Commands/ReplaceCommand.h"
#include "Commands/EjectCommand.h"
#include "Commands/HelpCommand.h"
#include "Commands/UpCommand.h"
#include "Commands/SphereCommand.h"

class CommandManager
{
private:
public:
	std::vector<Command*> commands;

	void init();
	bool runCommand(std::string line);

	CommandManager();
	~CommandManager();
};