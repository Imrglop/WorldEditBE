#pragma once
#include "../Minecraft/Block/Block.h"
#include "../Minecraft/Block/BlockPos.h"
#include "../Minecraft/Vector/Vec3.h"

class BlockWrapper
{
public:
	Minecraft::Block* block = nullptr;
	BlockPos pos = {};
	short aux = 0;

	BlockWrapper() {}
	~BlockWrapper() {}
};

