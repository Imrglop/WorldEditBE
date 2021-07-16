#pragma once
#include "../Entity/LocalPlayer.h"

namespace Minecraft {
	class ClientInstance {
	private:
		char pad_000[312];
	public:
		LocalPlayer* localPlayer;
	};
}