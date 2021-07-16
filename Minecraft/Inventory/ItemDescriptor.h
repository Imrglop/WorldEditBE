#pragma once
#include "Item.h"
#include "../Block/Block.h"

namespace Minecraft {
	class ItemDescriptor {
	public:
		Item* item;
		Block* block;
		short damage;
		bool isItem;
	};
}