#include "HelpCommand.h"
#include "../CommandManager.h"
#include "../../Utils/Game.h"
#include "../../Core/main.h"

HelpCommand::HelpCommand() : Command("help", "Shows a list of commands", {"commands"})
{
}

bool HelpCommand::run(std::string label, std::vector<std::string> args)
{
    std::stringstream fss;
    fss << "List of commands:";
    for (auto& cmd : c_CommandMgr->commands) {
        fss << "\n " << cmd->name << " : " << cmd->description;
        if (cmd->aliases.size() > 1) {
            fss << " (Aliases:";
            for (auto& alias : cmd->aliases) {
                fss << " " + alias;
            }
            fss << ")";
        }
    }
    Game::ClientMessage(fss.str());
    return true;
}
