#include "Command.h"
#include "../Core/Logger.h"

Command::Command(std::string name, std::string description, std::vector<std::string> aliases)
{
	this->name = name;
	this->description = description;
	this->aliases = aliases;
	this->aliases.push_back(name);
}

bool Command::run(std::string label, std::vector<std::string> args)
{
	logL("(Default command run)");
	return false;
}
