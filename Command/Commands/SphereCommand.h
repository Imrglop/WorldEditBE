#pragma once
#include "../Command.h"
class SphereCommand : public Command
{
public:
	SphereCommand();
	~SphereCommand() {};

	virtual bool run(std::string label, std::vector<std::string> args);
};

