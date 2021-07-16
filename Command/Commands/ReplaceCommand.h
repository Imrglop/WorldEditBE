#pragma once
#include "../Command.h"

class ReplaceCommand : public Command
{
public:
	ReplaceCommand();
	~ReplaceCommand();

	virtual bool run(std::string label, std::vector<std::string> args) override;
};

