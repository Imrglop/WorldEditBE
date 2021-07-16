#pragma once
#include "../Core/shared.h"
#include "../File/FileStorage.h"
#include "../Depends/SigScanner/SignatureScanner.h"
#include "../Minecraft/Block/BlockPos.h"
#include <MinHook.h>
#include "../Minecraft/World/Level.h"
#include "../Minecraft/Game/ClientInstance.h"
#include "../Minecraft/Game/ServerInstance.h"
#include "WorldTask.h"

struct GlobalData {
	Minecraft::ServerLevel* level;
	Minecraft::ClientInstance* clientInstance;
	Minecraft::ServerInstance* serverInstance;
	Minecraft::Player* localServerPlayer;
};

extern GlobalData global;

class WorldEdit
{
private:
	void initHooks();
	FileStorage* fileStorage;
public:
	//std::vector<std::shared_ptr<WorldTask>> worldTasks;

	bool enable();
	void disable();
	void loop();
	uintptr_t moduleBase;

	~WorldEdit();
};

bool setPos2(BlockPos& pos);
bool setPos1(BlockPos& pos);

BlockPos getPos1();
BlockPos getPos2();

extern std::unique_ptr<SignatureScanner> c_Scanner;
#define FindSignature(x) c_Scanner->scan(x)