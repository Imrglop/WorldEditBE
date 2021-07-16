#pragma once
#include "../Command.h"

class UpCommand : public Command
{
public:
	UpCommand();
	~UpCommand();

	virtual bool run(std::string label, std::vector<std::string> args) override;
};

