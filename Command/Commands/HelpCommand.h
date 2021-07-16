#pragma once
#include "../Command.h"

class HelpCommand : public Command
{
public:
	HelpCommand();
	~HelpCommand() {}

	virtual bool run(std::string label, std::vector<std::string> args) override;
};

