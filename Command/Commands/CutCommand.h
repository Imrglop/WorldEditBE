#pragma once
#include "../Command.h"

class CutCommand : public Command
{
public:
	CutCommand();
	~CutCommand();

	virtual bool run(std::string label, std::vector<std::string> args) override;
};

