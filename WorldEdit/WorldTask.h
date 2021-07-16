#pragma once
#include "BlockWrapper.h"
#include "../Minecraft/Entity/Player.h"

class WorldTask
{
public:
	struct TaskResult {
		bool success;
		int timeToComplete;
	};

	WorldTask();
	~WorldTask();

	virtual TaskResult run(std::vector<BlockWrapper> blocks);
};

