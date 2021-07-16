#pragma once
#include "../shared.h"
#include <iostream>
#include "Block.h"
#include "BlockPos.h"

namespace Minecraft {
	class BlockActor;
	class ActorBlockSyncMessage;
	class BlockSource {
	public:
		Block* getBlock(BlockPos& pos);
		bool setBlock(BlockPos const* pos, Block const* block, int i1, std::shared_ptr<BlockActor> ba, ActorBlockSyncMessage const* absm);
		[[deprecated]]
		bool removeBlock(BlockPos& pos);
	};
}