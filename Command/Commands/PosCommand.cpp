#include "PosCommand.h"
#include "../../WorldEdit/WorldEdit.h"
#include "../../Utils/Game.h"
#include <sstream>

PosCommand::PosCommand() : Command("pos", "Set WorldEdit position", { "setpos", "position" })
{
}

bool PosCommand::run(std::string label, std::vector<std::string> args)
{
	if (args.size() != 4) {
		clientMessage("Usage: -pos <pos number> <new location>");
		return false;
	}
	int posNum = 1;
	BlockPos posToSet = BlockPos(std::stoi(args[1]), std::stoi(args[2]), std::stoi(args[3]));
	try {
		posNum = std::stoi(args[0]);
	}
	catch (std::exception) {
		clientMessage("Invalid pos number: " << posNum);
		return false;
	}

	if (posNum == 1) {
		setPos1(posToSet);
	}
	else if (posNum == 2) {
		setPos2(posToSet);
	}
	else {
		clientMessage("Position is not 1 or 2: " << posNum);
		return false;
	}
	return true;
}
