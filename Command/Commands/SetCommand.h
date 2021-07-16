#pragma once
#include "../Command.h"
class SetCommand : public Command
{
public:
	SetCommand();
	~SetCommand();

	virtual bool run(std::string label, std::vector<std::string> args) override;
};

