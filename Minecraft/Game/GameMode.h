#pragma once
#include "../Entity/Player.h"

namespace Minecraft {
	class GameMode {
	public:
		Player* plr;

		virtual ~GameMode();
		virtual bool __cdecl startDestroyBlock(BlockPos*, unsigned __int8, bool*);
		virtual bool __cdecl destroyBlock(BlockPos*, unsigned __int8);
	};
}