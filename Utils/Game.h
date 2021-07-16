#pragma once
#include <future>
#include <sstream>
#include "../Minecraft/Block/Block.h"

namespace Game {
	void ForEachBlock(std::function<__int8(Minecraft::Block*)> func);
	// Finds a block by name.
	Minecraft::Block* FindBlock(std::string name);
	void ClientMessage(std::string s, bool prefix = true);
	bool MakeBlockList(std::string input, std::vector<Minecraft::Block*>& out);
}

#define clientMessage(ss) Game::ClientMessage((std::stringstream() << ss).str())
#define rawClientMessage(ss) Game::ClientMessage((std::stringstream() << ss).str(), false);