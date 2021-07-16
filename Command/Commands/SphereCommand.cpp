#include "SphereCommand.h"
#include "../../Utils/Utils.h"
#include "../../Utils/Game.h"
#include "../../WorldEdit/WorldEdit.h"

SphereCommand::SphereCommand() : Command("sphere", "Generates a sphere.", {})
{
}

bool SphereCommand::run(std::string label, std::vector<std::string> args)
{
	if (args.size() < 2) {
		clientMessage("Usage: -sphere <block pattern> <radius>");
		return false;
	}

	std::vector<Minecraft::Block*> pattern;
	if (!Game::MakeBlockList(args[0], pattern)) {
		clientMessage("Invalid block pattern: " << args[0]);
		return false;
	}
	int radius = std::stoi(args[1]);

	BlockPos pos1 = getPos1();
	Minecraft::BlockSource* rg = global.localServerPlayer->getRegionConst();
	int blocksReplaced = 0;

	for (int y = -radius; y < radius; y++) {
		for (int x = -radius; x < radius; x++) {
			for (int z = -radius; z < radius; z++) {
				if (((x * x) + (y * y) + (z * z)) <= (radius * radius)) {
					BlockPos pos = BlockPos(x + pos1.x, y + pos1.y, z + pos1.z);
					if (pos.y < 0) y = 0;
					if (pos.y > 255) y = 255; // TODO: change this for 1.18
					Minecraft::Block* block = pattern[_rand() % pattern.size()];
					if (rg->getBlock(pos) != block) blocksReplaced++;
					rg->setBlock(&pos, block, 3, nullptr, nullptr);
				}
			}
		}
	}

	clientMessage("Replaced " << blocksReplaced << " blocks.");
	return true;
}
