#pragma once
#include "../Command.h"
class WallsCommand : public Command
{
public:
	WallsCommand();
	~WallsCommand();

	virtual bool run(std::string label, std::vector<std::string> args) override;
};

