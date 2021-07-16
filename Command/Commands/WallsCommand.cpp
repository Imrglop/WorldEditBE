#include "WallsCommand.h"
#include "../../Utils/Game.h"
#include "../../WorldEdit/WorldEdit.h"

WallsCommand::WallsCommand() : Command("walls", "Sets walls", {})
{
}

WallsCommand::~WallsCommand()
{
}

bool WallsCommand::run(std::string label, std::vector<std::string> args)
{
	if (args.size() < 1) {
		clientMessage("Usage: -walls <block pattern>");
		return false;
	}

	std::vector<Minecraft::Block*> pattern;

	if (!Game::MakeBlockList(args[0], pattern)) {
		clientMessage("Invalid block pattern: " << args[0]);
		return false;
	}

	auto pos1 = getPos1();
	auto pos2 = getPos2();

	int minX = pos1.x; int minY = pos1.y; int minZ = pos1.z;
	int maxX = pos2.x; int maxY = pos2.y; int maxZ = pos2.z;

	Utils::CalcMinMax(minX, minY, minZ, maxX, maxY, maxZ);

	Minecraft::BlockSource* src = global.localServerPlayer->getRegionConst();

	int blockCount = 0;

	for (int x = minX; x <= maxX; ++x) {
		for (int y = minY; y <= maxY; ++y) {
			for (int z = minZ; z <= maxZ; ++z) {
				if (x == minX || x == maxX || 
					z == minZ || z == maxZ) {
					BlockPos bp(x, y, z);
					int rnd = _rand() % (pattern.size());
					Minecraft::Block* block = pattern[rnd];
					if (src->getBlock(bp) != block) blockCount++;
					src->setBlock(&bp, block, 3, nullptr, nullptr);
				}
			}
		}
	}

	clientMessage("Updated " << blockCount << " blocks.");
	return true;
}
