#pragma once
#include "Minecraft.h"

namespace Minecraft {
	class ServerInstance {
	public:
		void* vtable;
		class DedicatedServer* server;
		Minecraft* minecraft;
	};
}