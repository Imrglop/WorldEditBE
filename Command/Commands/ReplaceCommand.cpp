#include "ReplaceCommand.h"
#include "../../Utils/Utils.h"
#include "../../Utils/Game.h"
#include "../../WorldEdit/WorldEdit.h"

ReplaceCommand::ReplaceCommand() : Command("replace", "Replace blocks", {})
{
}

ReplaceCommand::~ReplaceCommand()
{
}

bool ReplaceCommand::run(std::string label, std::vector<std::string> args)
{
	if (args.size() < 2) {
		clientMessage("Usage: -replace <block pattern 1> <block pattern 2>");
		return false;
	}

	std::vector<Minecraft::Block*> pattern1;
	std::vector<Minecraft::Block*> pattern2;

	if (!Game::MakeBlockList(args[0], pattern1)) {
		clientMessage("Block pattern 1 is invalid.");
		return false;
	}

	if (!Game::MakeBlockList(args[1], pattern2)) {
		clientMessage("Pattern 2 is invalid.");
		return false;
	}

	auto pos1 = getPos1();
	auto pos2 = getPos2();

	int minX = pos1.x; int minY = pos1.y; int minZ = pos1.z;
	int maxX = pos2.x; int maxY = pos2.y; int maxZ = pos2.z;

	Utils::CalcMinMax(minX, minY, minZ, maxX, maxY, maxZ);

	Minecraft::BlockSource* src = global.localServerPlayer->getRegionConst();

	int blocksReplaced = 0;

	for (int x = minX; x <= maxX; ++x) {
		for (int y = minY; y <= maxY; ++y) {
			for (int z = minZ; z <= maxZ; ++z) {
				BlockPos bp(x, y, z);
				Minecraft::Block* currentBlock = src->getBlock(bp);
				for (auto& block : pattern1) {
					if (block == currentBlock) {
						int rnd = _rand() % (pattern2.size());
						src->setBlock(&bp, pattern2[rnd], 3, nullptr, nullptr);
						blocksReplaced++;
						break;
					}
				}
			}
		}
	}

	clientMessage("Replaced " << blocksReplaced << " blocks.");

	return true;
}
