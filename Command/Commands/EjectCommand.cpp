#include "EjectCommand.h"
#include "../../Core/main.h"

bool EjectCommand::run(std::string label, std::vector<std::string> args)
{
    main::eject();
    return true;
}
