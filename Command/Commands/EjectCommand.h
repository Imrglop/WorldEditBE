#pragma once
#include "../Command.h"

class EjectCommand : public Command
{
public:
	EjectCommand() : Command("eject", "Un-inject", {"stop", "uninject"}) {}
	~EjectCommand() { }

	virtual bool run(std::string label, std::vector<std::string> args);
};

