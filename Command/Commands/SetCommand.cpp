#include "SetCommand.h"
#include "../../WorldEdit/WorldEdit.h"
#include "../../Utils/Game.h"
#include "../../Utils/Utils.h"

SetCommand::SetCommand() : Command("set", "Set your WorldEdit selection to a block.", {})
{
}

SetCommand::~SetCommand()
{
}

bool SetCommand::run(std::string label, std::vector<std::string> args)
{
    if (args.size() < 1) {
        clientMessage("Usage: -set <block name> [aux]");
        return false;
    }
    
    std::string blockName = args[0];
    short aux = 0;
    if (args.size() > 1) {
        aux = std::stoi(args[1]);
    }

    std::vector<Minecraft::Block*> blocks;
    if (!Game::MakeBlockList(args[0], blocks)) {
        clientMessage("Invalid block list: " << args[0]);
        return false;
    }

    if (blocks.size() == 0) {
        clientMessage("No blocks are in the list you specified: " << args[0]);
        return false;
    }

    Minecraft::BlockSource* src = global.localServerPlayer->getRegionConst();
    BlockPos pos1 = getPos1();
    BlockPos pos2 = getPos2();

    int maxX = pos2.x;
    int maxY = pos2.y;
    int maxZ = pos2.z;

    int minX = pos1.x;
    int minY = pos1.y;
    int minZ = pos1.z;

    Utils::CalcMinMax(minX, minY, minZ, maxX, maxY, maxZ);

    int blockCount = 0;

    for (int x = minX; x <= maxX; ++x) {
        for (int y = minY; y <= maxY; ++y) {
            for (int z = minZ; z <= maxZ; ++z) {
                int rnd = _rand() % (blocks.size());
                BlockPos bp(x, y, z);
                if (src->getBlock(bp) != blocks[rnd])
                    blockCount++;
                src->setBlock(&bp, blocks[rnd], 3, nullptr, nullptr);
            }
        }
    }

    clientMessage("Updated " << blockCount << " block(s) to " << blockName << ".");
    return true;
}