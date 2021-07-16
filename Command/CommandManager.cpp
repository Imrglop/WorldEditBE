#include "CommandManager.h"
#include "../Core/Logger.h"
#include "../Utils/Game.h"

void CommandManager::init()
{
	this->commands.push_back(new PosCommand());
	this->commands.push_back(new SetCommand());
	this->commands.push_back(new CutCommand());
	this->commands.push_back(new WallsCommand());
	this->commands.push_back(new ReplaceCommand());
	this->commands.push_back(new EjectCommand());
	this->commands.push_back(new HelpCommand());
	this->commands.push_back(new UpCommand());
	this->commands.push_back(new SphereCommand());
}

bool CommandManager::runCommand(std::string line)
{
	bool isQuoted = false;
	bool isEscaped = false;
	std::vector<std::string> newArgs = {};

	std::string word = "";

	// parser
	for (size_t i = 0; i < line.size(); i++) {
		char ch = line[i];
		if (ch == '\\' && !isEscaped) {
			isEscaped = true;
			continue;
		}
		if (!isEscaped) {
			if (ch == '"') {
				if (isQuoted) {
					newArgs.push_back(word);
					word = "";
				}
				isQuoted = !isQuoted;
				continue;
			}
		}
		if (isQuoted) {
			word += ch;
			continue;
		}
		if (!isEscaped) {
			if (ch == ' ' || line.size() - i < 2) {
				if (line.size() - i < 2) {
					word += ch;
				}
				newArgs.push_back(word);
				word = "";
				continue;
			}
		}

		word += ch;
		isEscaped = false;
	}

	for (Command* cmd : this->commands) {
		for (std::string alias : cmd->aliases) {
			if (alias == newArgs[0] /*label*/) {
				std::vector<std::string> args;
				for (size_t k = 1; k < newArgs.size(); k++) {
					args.push_back(newArgs[k]);
				}
				try {
					return cmd->run(newArgs[0], args);
				}
				catch (std::exception&e) {
					logL("An unhandled exception occured while running this command.");
					rawClientMessage("An unhandled exception occured while running this command.");
					logLC(0xC, e.what());
					return false;
				}
			}
		}
	}

	clientMessage("Unknown command: " << newArgs[0] << ". Type '-help' for a list of commands.");

	return false;
}

CommandManager::CommandManager()
{
}

CommandManager::~CommandManager()
{
	for (auto& cmd : this->commands) {
		if (cmd != nullptr) {
			delete cmd;
		}
	}
}
