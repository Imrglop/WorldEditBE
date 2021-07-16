#pragma once
#include "../Command.h"

class PosCommand : public Command
{
public:
	PosCommand();

	virtual bool run(std::string label, std::vector<std::string> args) override;
};

