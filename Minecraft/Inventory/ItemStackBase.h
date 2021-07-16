#pragma once

#include "../shared.h"
#include "../Block/BlockLegacy.h"
#include "../NBT/CompoundTag.h"
#include "Item.h"

namespace Minecraft {
	class ItemStackBase {
	public:
		Minecraft::Item** item; // 0
		CompoundTag* nbt; // 8
		short blockState; // 16
		short damage; // 24
		byte count; // 32
	};
}