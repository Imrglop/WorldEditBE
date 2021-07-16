#pragma once
#include "ItemStackBase.h"
#include "../Entity/Actor.h"

namespace Minecraft {
	class ItemStack : public ItemStackBase {
	public:
		inline void destroy() {
			memset(this, 0, sizeof(ItemStack));
		}

		bool useOn(Actor* user, int x, int y, int z, byte side, float f1, float f2, float f3);

		virtual ~ItemStack();
		virtual void __cdecl reinit(void*, int, int);
		virtual void __cdecl reinit(BlockLegacy* block, int count);
		virtual void __cdecl reinit(Item const*, int, int);
		virtual void __cdecl setNull();
		virtual std::string __cdecl toString();
		virtual std::string __cdecl toDebugString();
	};
}