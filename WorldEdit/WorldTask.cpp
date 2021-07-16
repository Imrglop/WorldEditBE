#include "WorldTask.h"
#include "WorldEdit.h"
#include "all_minecraft_headers.h"
#include <chrono>

WorldTask::WorldTask()
{
}

WorldTask::~WorldTask()
{
}

WorldTask::TaskResult WorldTask::run(std::vector<BlockWrapper> blocks)
{
	TaskResult res = {};
	auto startTime = std::chrono::high_resolution_clock::now();
	Minecraft::BlockSource* src = global.localServerPlayer->getRegionConst();
	for (auto& blockEntry : blocks) {
		src->setBlock(&blockEntry.pos, blockEntry.block, 3, nullptr, nullptr);
	}
	auto endTime = std::chrono::high_resolution_clock::now();
	res.success = true;
	res.timeToComplete = static_cast<int>(std::chrono::duration<double, std::milli>(endTime - startTime).count());
	return res;
}
