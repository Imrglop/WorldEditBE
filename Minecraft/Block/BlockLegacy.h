#pragma once
#include "../String/Text.h"
#include <cstdint>

namespace Minecraft {
	class BlockLegacy {
	public:
		uintptr_t** vtable;
		Text blockName;
	private:
		void* holder1[2];
	public:

	};
}