#include "UpCommand.h"
#include "../../Utils/Utils.h"
#include "../../Utils/Game.h"
#include "../../WorldEdit/WorldEdit.h"

UpCommand::UpCommand() : Command("up", "Teleport up and place a block below you.", {})
{
}

UpCommand::~UpCommand()
{
}

bool UpCommand::run(std::string label, std::vector<std::string> args)
{
	if (args.empty()) {
		clientMessage("Usage: -up <number of blocks>");
		return false;
	}

	std::string numArg = args[0];
	int num = std::stoi(numArg); // exception will be catched

	Vec3 plrPos = global.clientInstance->localPlayer->getPos();
	plrPos.y += num + 0.5f;

	global.localServerPlayer->setPos(plrPos);
	global.clientInstance->localPlayer->setPos(plrPos);

	Minecraft::BlockSource* rg = global.localServerPlayer->getRegionConst();
	BlockPos pos;
	pos.set(global.clientInstance->localPlayer->getPos());
	static Minecraft::Block* glassBlock = Game::FindBlock("glass");
	pos.y -= 2;
	rg->setBlock(&pos, glassBlock, 3, nullptr, nullptr);

	if (pos.x < 0)
		pos.x -= 1;
	if (pos.z < 0)
		pos.z -= 1;

	clientMessage("Whoosh!");
	return true;
}