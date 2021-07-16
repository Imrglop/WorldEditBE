#pragma once
#include <vector>
#include <iostream>

class Command
{
public:
	std::string name;
	std::string description;
	std::vector<std::string> aliases;
	Command(std::string name, std::string description, std::vector<std::string> aliases = {});

	virtual bool run(std::string label, std::vector<std::string> args);
};

