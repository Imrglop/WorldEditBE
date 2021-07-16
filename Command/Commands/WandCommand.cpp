#include "WandCommand.h"
#include "../../WorldEdit/WorldEdit.h"
#include "../../Utils/Game.h"

WandCommand::WandCommand() : Command("wand", "Gives you a wand.", {})
{
}

WandCommand::~WandCommand()
{
}

bool WandCommand::run(std::string label, std::vector<std::string> args)
{
    // TODO: item registry
    //auto supplies = global.localServerPlayer->getSupplies();
    //supplies->inv->addItem();
    clientMessage("Given wand!");
    return true;
}
