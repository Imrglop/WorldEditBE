#include "BlockSource.h"
#include "../../WorldEdit/WorldEdit.h"

Minecraft::Block* Minecraft::BlockSource::getBlock(BlockPos& pos)
{
	using get_block_t = Block*(__fastcall*)(BlockSource* _this, BlockPos& pos);
	static get_block_t oFunc = (get_block_t)FindSignature("48 89 5c 24 ? 57 48 83 ec ? 48 8b f9 48 8b da 8b 4a ? 0f bf 47 ? 3b c8 0f 8c ? ? ? ? 0f bf 47 ? 3b c8 0f 8d ? ? ? ? 8b 02 48 8b cf c1 f8 ? 89 44 24 ? 8b 42 ? 48 8d 54 24 ? c1 f8 ? 89 44 24 ? e8 ? ? ? ? 48 85 c0 74 ? 0f b7 4b ? 66 2b 4f ? 44 0f b6 13 44 0f b7 c9 44 0f b6 5b ? 41 80 e2 ? 66 c1 f9 ? 41 80 e3 ? 48 0f bf d1 48 8d 88 ? ? ? ? 48 8b 80 ? ? ? ? 48 3b d0 73 ? 48 8d 04 d2 48 8d 0c c1 48 85 c9 74 ? 48 8b 49 ? 66 41 83 e1");
	return oFunc(this, pos);
}

bool Minecraft::BlockSource::setBlock(BlockPos const* pos, Block const* block, int i1, std::shared_ptr<BlockActor> ba, ActorBlockSyncMessage const* absm)
{
	using set_block_t = bool(__fastcall*)(BlockSource* _this, BlockPos const* pos, Block const* block, int, std::shared_ptr<BlockActor>, ActorBlockSyncMessage const*);
	static set_block_t oFunc = (set_block_t)FindSignature("4c 8b dc 49 89 5b ? 55 56 57 41 54 41 55 41 56 41 57 48 83 ec ? 45 8b e9");
	return oFunc(this, pos, block, i1, ba, absm);
}

bool Minecraft::BlockSource::removeBlock(BlockPos& pos)
{
	using remove_block_t = bool(__fastcall*)(BlockSource* _this, BlockPos& pos);
	static remove_block_t oFunc = reinterpret_cast<remove_block_t>(Utils::InstructionToAddress(reinterpret_cast<void*>(FindSignature("e8 ? ? ? ? ff 47 ? ff 87")), 1));
	return oFunc(this, pos);
}
