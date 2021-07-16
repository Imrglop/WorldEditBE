#include "Game.h"
#include "../Utils/Utils.h"
#include "../WorldEdit/WorldEdit.h"
#include "../Core/Logger.h"

void Game::ForEachBlock(std::function<__int8(Minecraft::Block*)> func)
{
	static uintptr_t unassignBlocksFunc = Utils::InstructionToAddress((void*)FindSignature("E8 ?? ?? ?? ?? E8 ?? ?? ?? ?? E8 ?? ?? ?? ?? E8 ?? ?? ?? ?? E8 ?? ?? ?? ?? E8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 48 8B 05"), 1);
	static Minecraft::Block** pAirBlock = reinterpret_cast<Minecraft::Block**>(Utils::InstructionToAddress((void*)FindSignature("48 8b 0d ? ? ? ? 48 8b f0 48 8b 50 ? 48 85 d2 0f 84")));
	if (unassignBlocksFunc != NULL) {
		static unsigned char* blockListIns = reinterpret_cast<unsigned char*>(unassignBlocksFunc + 2);
		bool shouldRun = true;
		if (func(*pAirBlock) == 2) {
			shouldRun = false;
		}
		if (shouldRun)
			for (unsigned char* i = blockListIns; *i == 0x48 /*start of instruction*/; i += 7 /*length of instruction*/) {
				Minecraft::Block* block = *reinterpret_cast<Minecraft::Block**>(Utils::InstructionToAddress(i));
				int res = func(block);
				if (res == 1) continue;
				if (res == 2) break;
			}
	}
}

Minecraft::Block* Game::FindBlock(std::string name)
{
	Minecraft::Block* result = nullptr;
	bool isNumParam = false;
	int _intParam = -1;
	try {
		_intParam = std::stoi(name);
		isNumParam = true;
	}
	catch (std::exception&) {
		isNumParam = false;
	}

	int i = 0;

	ForEachBlock([&](Minecraft::Block* block) {
		if (block == nullptr) return 1;
		if (block->legacyBlock == nullptr) return 1;
		if (IsBadReadPtr(block->legacyBlock, 1)) return 1;
		if (IsBadStringPtrA(block->legacyBlock->blockName.getText(), 128)) return 1;

		if (isNumParam) {
			if (i == _intParam) {
				result = block;
				return 2;
			}
		}

		i++;
		
		if (!isNumParam) {
			if (block->legacyBlock->blockName.str() == name) {
				result = block;
				return 2;
			}
			if (block->legacyBlock->blockName.str() == "tile." + name) {
				result = block;
				return 2;
			}
		}
		return 0;
	});
	return result;
}

void Game::ClientMessage(std::string s, bool prefix)
{
	if (global.clientInstance->localPlayer) {
		std::string str = prefix ? ("[WorldEditBE] " + s) : s;
		global.clientInstance->localPlayer->displayClientMessage(str);
		if (prefix) {
			logL("[CHAT] " + s);
		}
	}
}

bool Game::MakeBlockList(std::string input, std::vector<Minecraft::Block*>& out)
{
	std::string word = "";
	std::vector<std::string> words;

	for (size_t i = 0; i < input.size(); i++) {
		char ch = input[i];
		if (ch == ' ' || ch == ',') {
			words.push_back(word);
			word = "";
			continue;
		}
		word += ch;
	}

	words.push_back(word);
	out.clear();

	for (std::string& word : words) {
		Minecraft::Block* block = Game::FindBlock(word);
		if (block == nullptr && (word == "hand" || word == "hand_item")) {
			Minecraft::PlayerInventory* supplies = global.clientInstance->localPlayer->getSupplies();
			Minecraft::ItemStack* stack = supplies->inv->getItem(supplies->selectedSlot);
			if (stack->item == nullptr) {
				clientMessage(word + " - You are not holding an item.");
				continue;
			}
			Minecraft::Item* item = *stack->item;

			block = Game::FindBlock(item->_id.getText());
			if (block == nullptr) {
				clientMessage(word + " - The item in your hand, '" + item->getTypeID() + "', is not a valid block.");
			}
		}
		if (block == nullptr) {
			clientMessage(word + " - Invalid block.");
			return false;
		}
		out.push_back(block);
	}

	return true;
}
