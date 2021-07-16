#include "CutCommand.h"
#include "../../Utils/Utils.h"
#include "../../Utils/Game.h"
#include "../../WorldEdit/WorldEdit.h"

CutCommand::CutCommand() : Command("cut", "Removes blocks in an area.", { "remove", "air" })
{
}

CutCommand::~CutCommand()
{
}

bool CutCommand::run(std::string label, std::vector<std::string> args)
{
    BlockPos pos1 = getPos1();
    BlockPos pos2 = getPos2();

    int minX = pos1.x; int minY = pos1.y; int minZ = pos1.z;
    int maxX = pos2.x; int maxY = pos2.y; int maxZ = pos2.z;

    Utils::CalcMinMax(minX, minY, minZ, maxX, maxY, maxZ);

    int blockCount = 0;

    auto src = global.localServerPlayer->getRegionConst();

    for (int x = minX; x <= maxX; ++x) {
        for (int y = minY; y <= maxY; ++y) {
            for (int z = minZ; z <= maxZ; ++z) {
                BlockPos bp = BlockPos(x, y, z);
                static Minecraft::Block* block = Game::FindBlock("air");
                if (src->getBlock(bp) != block) {
                    blockCount++;
                }
                src->setBlock(&bp, block, 3, nullptr, nullptr);
            }
        }
    }

    clientMessage("Removed " << blockCount << " blocks.");
    return true;
}
