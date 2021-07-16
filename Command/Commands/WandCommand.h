#pragma once
#include "../Command.h"

class WandCommand : public Command
{
public:
	WandCommand();
	~WandCommand();

	virtual bool run(std::string label, std::vector<std::string> args) override;
};

