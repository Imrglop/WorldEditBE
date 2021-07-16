/*
WorldEditBE
Made by Imrglop
https://github.com/Imrglop/WorldEditBE
*/

#include "WorldEdit.h"
#include "../Core/main.h"
#include "../Core/Logger.h"
#include <math.h>
#include <Psapi.h>
#include "../Depends/VTHook/vtable_hook.h"
#include "../Utils/Utils.h"
#include "../Utils/Game.h"

#include "../Minecraft/World/Level.h"

#include "all_minecraft_headers.h"

#include "../Minecraft/Inventory/PlayerInventory.h"

GlobalData global;

typedef uintptr_t** vftable_t;

std::unique_ptr<SignatureScanner> c_Scanner;

send_chat_message_t sendChatMessage;
block_use_t useBlock;
itemstack_useon_t useItemStackOn;
gamemode_destroy_t destroyBlockOn;
set_block_t setBlock;
serverlevel_tick_t oServerLevelTick;

typedef __int64 undefined8;
typedef unsigned char code;
typedef __int64 longlong;

typedef void(__fastcall* server_instance_initialize_server_t)(Minecraft::ServerInstance* _this, longlong* minecraftApp, undefined8 param_3, undefined8 param_4, undefined8 param_5, undefined8 param_6, undefined8* param_7, undefined8 param_8, undefined8 param_9, undefined8 param_10, undefined8 param_11_00, undefined8 param_12_00, undefined8 param_13, undefined8 param_14_00, undefined8 param_15, undefined8 param_16, undefined8 param_17, undefined8 param_18, longlong* param_19, undefined8 param_20, undefined8 param_21, longlong* param_22, undefined8 param_23, undefined8 param_24, longlong param_25, undefined8 param_26, undefined8 param_27, code** param_28, undefined8 param_29, longlong* param_30, longlong* param_31, undefined8 param_32_00, longlong param_33, bool param_34, std::shared_ptr<class Core_FileStorageArea> param_35, unsigned short param_36, bool param_37, bool param_38, __int64 playerMovementSettings, void* pExperiments);
server_instance_initialize_server_t initializeServer;
void ServerInstance_initializeServerF(Minecraft::ServerInstance* _this, longlong* minecraftApp, undefined8 param_3, undefined8 param_4, undefined8 param_5, undefined8 param_6, undefined8* param_7, undefined8 param_8, undefined8 param_9, undefined8 param_10, undefined8 param_11_00, undefined8 param_12_00, undefined8 param_13, undefined8 param_14_00, undefined8 param_15, undefined8 param_16, undefined8 param_17, undefined8 param_18, longlong* param_19, undefined8 param_20, undefined8 param_21, longlong* param_22, undefined8 param_23, undefined8 param_24, longlong param_25, undefined8 param_26, undefined8 param_27, code** param_28, undefined8 param_29, longlong* param_30, longlong* param_31, undefined8 param_32_00, longlong param_33, bool param_34, std::shared_ptr<class Core_FileStorageArea> param_35, unsigned short param_36, bool param_37, bool param_38, __int64 playerMovementSettings, void* pExperiments) {
    initializeServer(_this, minecraftApp, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11_00, param_12_00, param_13, param_14_00, param_15, param_16, param_17, param_18, param_19, param_20, param_21, param_22, param_23, param_24, param_25, param_26, param_27, param_28, param_29, param_30, param_31, param_32_00, param_33, param_34, param_35, param_36, param_37, param_38, playerMovementSettings, pExperiments);
    global.serverInstance = _this;
}

bool setBlockHook(Minecraft::BlockSource* _this, const BlockPos* pos, const Minecraft::Block* block, int i1, std::shared_ptr<BlockActor> blockActor, const ActorBlockSyncMessage* absm) {
    if (i1 == 3 /*&& _this == global.localServerPlayer->getRegionConst()*/) {
        Vec3 playerPos = global.localServerPlayer->getPos();
        playerPos.y -= 1.6F;
        BlockPos pos2 = *pos;
        pos2.y += 1; // place same block on top of it
        logL("Setblock " << pos->x << ", " << pos->y << ", " << pos->z << " : " << i1 << " " << " " << absm);
        global.localServerPlayer->getRegionConst()->setBlock(&pos2, block, i1, nullptr, nullptr);
    }
    return setBlock(_this, pos, block, i1, blockActor, absm);
}

BlockPos pos1 = BlockPos();
BlockPos pos2 = BlockPos();

bool setPos2(BlockPos& pos) {
    if (pos2.equals(pos)) {
        return false;
    }
    pos2.set(pos);
    clientMessage("Set position 2 to " << pos2.toString());
    return true;
}

bool setPos1(BlockPos& pos) {
    if (pos1.equals(pos)) {
        return false;
    }
    pos1.set(pos);
    clientMessage("Set position 1 to " << pos1.toString());
    return true;
}

BlockPos getPos1()
{
    return pos1;
}

BlockPos getPos2()
{
    return pos2;
}

void __cdecl sendChatMessageHook(void* rbp, Minecraft::Text* chatText, size_t b1, size_t b2, int* pInt1, void* a1, void* a2) {
    string txt = chatText->str();
    Minecraft::Player* player = global.localServerPlayer;
    Minecraft::Player* localPlayer = global.clientInstance->localPlayer;
    logL("Chatted! '" << txt << "'");
    if (txt[0] == '-') {
        if (txt.size() == 1) {
            clientMessage("Please enter a command.");
            return;
        }
        if (txt.substr(0, 5) == "-say ") {
            auto supplies = localPlayer->getSupplies();

            chatText->str() = txt.substr(5);
            return sendChatMessage(rbp, chatText, b1, b2, pInt1, a1, a2);
        }
        if (c_CommandMgr->runCommand(txt.substr(1))) {
            logLC(0xA, "Command Success! " << txt);
        }

        return;
    }
    sendChatMessage(rbp, chatText, b1, b2, pInt1, a1, a2);
}

bool __cdecl destroyBlockHook(Minecraft::GameMode* _this, BlockPos* pos, unsigned __int8 param_1) {
    if (_this->plr == global.clientInstance->localPlayer) {
        Minecraft::PlayerInventory* supplies = _this->plr->getSupplies();
        int slot = supplies->selectedSlot;
        Minecraft::Inventory* inv = supplies->inv;

        Minecraft::ItemStack* itemStack = inv->getItem(slot);

        if (itemStack != nullptr) {
            if (itemStack->item != nullptr) {
                Minecraft::Item* item = *itemStack->item;
                if (item->getTypeID() == "minecraft:wooden_axe") {
                    setPos1(*pos);
                    return false;
                }
            }
        }
    }
    return destroyBlockOn(_this, pos, param_1);
}

uintptr_t g_moduleBase;

bool __cdecl hook_ItemStack_useOn(Minecraft::ItemStack* _this, Minecraft::Actor* actor, int x, int y, int z, byte side, float param_6, float param_7, float param_8) {
    if (reinterpret_cast<Minecraft::Actor*>(global.localServerPlayer) == actor) {
        if (_this->item != nullptr) {
            Minecraft::Item* item = *_this->item;
            if (item->getTypeID() == "minecraft:wooden_axe") {
                BlockPos pos = { x, y, z };
                setPos2(pos);
                return true;
            }
            if (item->getTypeID() == "minecraft:blaze_rod") {
                Vec3 pos = Vec3();
                pos.x = (float)x + 0.50F;
                pos.y = (float)y + 2.62F;
                pos.z = (float)z + 0.50F;
                global.clientInstance->localPlayer->setPos(pos);
                global.localServerPlayer->setPos(pos);
                logL("Teleport to " << pos.toString());
                return true;
            }
        }
    }
    return useItemStackOn(_this, actor, x, y, z, side, param_6, param_7, param_8);
}

void ServerLevel_tickF(Minecraft::ServerLevel* _this) {
    global.level = _this;
    if (global.clientInstance->localPlayer) {
        global.localServerPlayer = callVirtual<Minecraft::Player*, Minecraft::Text*>(0x31, _this, global.clientInstance->localPlayer->getNameTag());
    }
    oServerLevelTick(_this);
}

void WorldEdit::initHooks()
{
    MODULEINFO info;
    GetModuleInformation(GetCurrentProcess(), (HMODULE)moduleBase, &info, sizeof(MODULEINFO));
    c_Scanner = std::make_unique<SignatureScanner>(moduleBase, moduleBase + info.SizeOfImage);

    static uintptr_t sendChatFunc = FindSignature("48 89 5c 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8d ac 24 ? ? ? ? 48 81 ec ? ? ? ? 48 8b 05 ? ? ? ? 48 33 c4 48 89 85 ? ? ? ? 4c 8b ea 4c 8b f9 48 8b 49");
    static uintptr_t gameModeSig = FindSignature("48 8D 05 ? ? ? ? 48 8B D9 48 89 01 8B FA 48 8B 89 ? ? ? ? 48 85 C9 74 ? 48 8B 01 BA ? ? ? ? FF 10 48 8B 8B");
    static uintptr_t itemStackUseFunc = FindSignature("40 53 55 56 57 48 83 ec ? 48 8b 41");
    static uintptr_t player_getInvFunc = FindSignature("45 84 c0 75 ? 48 8b 89 ? ? ? ? 48 8b 01");
    static uintptr_t clientInstanceSig = FindSignature("48 8B 15 ? ? ? ? 4C 8B 02 4C 89 06 40 84 FF 74 ? 48 8B CD E8 ? ? ? ? 48 8B C6 48 8B 4C 24 ? 48 33 CC E8 ? ? ? ? 48 8B 5C 24 ? 48 8B 6C 24 ? 48 8B 74 24 ? 48 83 C4 ? 5F C3 B9 ? ? ? ? E8 ? ? ? ? CC E8 ? ? ? ? CC CC CC CC CC CC CC CC CC CC CC 48 89 5C 24 ? 48 89 6C 24 ? 56");
    static uintptr_t itemStackBase_getDescriptorFunc = FindSignature("48 89 5c 24 ? 48 89 74 24 ? 57 48 81 ec ? ? ? ? 48 8b 05 ? ? ? ? 48 33 c4 48 89 84 24 ? ? ? ? 48 8b da 48 8b f9 48 89 54 24 ? 48 8b 51");
    static uintptr_t setBlockFunc = FindSignature("4c 8b dc 49 89 5b ? 55 56 57 41 54 41 55 41 56 41 57 48 83 ec ? 45 8b e9");
    static uintptr_t fpServerInstance_initializeServer = FindSignature("48 89 5c 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8d ac 24 ? ? ? ? b8 ? ? ? ? e8 ? ? ? ? 48 2b e0 0f 29 b4 24 ? ? ? ? 48 8b 05 ? ? ? ? 48 33 c4 48 89 85 ? ? ? ? 48 89 95");
    static uintptr_t fpServerLevel_tick = FindSignature("48 89 5C 24 ?? 57 48 83 EC ?? 48 8B 05 ?? ?? ?? ?? 48 33 C4 48 89 44 24 ?? 48 8B F9 E8 ?? ?? ?? ?? 48 8B 8F");

    logL("Done scanning");
    MH_CreateHook(reinterpret_cast<LPVOID>(sendChatFunc), sendChatMessageHook, reinterpret_cast<LPVOID*>(&sendChatMessage));
    //MH_CreateHook(reinterpret_cast<LPVOID>(setBlockFunc), setBlockHook, reinterpret_cast<LPVOID*>(&setBlock));
    MH_CreateHook(reinterpret_cast<LPVOID>(itemStackUseFunc), hook_ItemStack_useOn, reinterpret_cast<LPVOID*>(&useItemStackOn));
    MH_CreateHook(reinterpret_cast<LPVOID>(fpServerInstance_initializeServer), ServerInstance_initializeServerF, reinterpret_cast<LPVOID*>(&initializeServer));
    MH_CreateHook(reinterpret_cast<LPVOID>(fpServerLevel_tick), ServerLevel_tickF, reinterpret_cast<LPVOID*>(&oServerLevelTick));

    // GameMode::`vftable'
    vftable_t gameModeVtable = reinterpret_cast<vftable_t>(Utils::InstructionToAddress(reinterpret_cast<void*>(gameModeSig)));
    MH_CreateHook(reinterpret_cast<LPVOID>(gameModeVtable[0x2]), destroyBlockHook, reinterpret_cast<LPVOID*>(&destroyBlockOn));

    // ClientInstance
    uintptr_t ciBase = Utils::InstructionToAddress(reinterpret_cast<void*>(clientInstanceSig));

    uintptr_t evalPtr = *reinterpret_cast<uintptr_t*>(ciBase);
    evalPtr = *reinterpret_cast<uintptr_t*>(evalPtr);
    global.clientInstance = *reinterpret_cast<Minecraft::ClientInstance**>(evalPtr + 0x50);

    logL("Client Instance: " << global.clientInstance);

    rawClientMessage("WorldEditBE is loaded!");
}

bool WorldEdit::enable()
{
    HMODULE minecraftModule = GetModuleHandle(NULL);
    moduleBase = (uintptr_t)minecraftModule;
    g_moduleBase = moduleBase;
    MODULEINFO info;
    GetModuleInformation(GetCurrentProcess(), (HMODULE)moduleBase, &info, sizeof(MODULEINFO));
    initHooks();
    return true;
}

void WorldEdit::disable()
{
}

void WorldEdit::loop()
{   
}

WorldEdit::~WorldEdit()
{
}
