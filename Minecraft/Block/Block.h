#pragma once
#include "BlockLegacy.h"
#include "../shared.h"

namespace Minecraft {
	class Block {
	public:
		short tileData;
	private:
		byte pad_000[6];
	public:
		BlockLegacy* legacyBlock;
		virtual ~Block();
	};
}