#pragma once
#include "../World/Level.h"

namespace Minecraft {
	class Minecraft {
	public:
		// EatVtable.js
		virtual ~Minecraft(); // 0x0
		virtual __int64 nullsub_0(void); // 0x1
		virtual void setSimTimePause(bool); // 0x2
		virtual void setSimTimeScale(float); // 0x3
		virtual bool getSimPaused(void); // 0x4
		virtual bool isOnlineClient(void); // 0x5

		// Non-virtuals

		Level* getLevel();
	};
}