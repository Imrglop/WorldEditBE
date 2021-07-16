#pragma once
#include "shared.h"
#include <memory>

// Functions

typedef bool(__cdecl* set_block_t)(Minecraft::BlockSource* _this, BlockPos const* pos, Minecraft::Block const* block, int, std::shared_ptr<class BlockActor>, class ActorBlockSyncMessage const*);
typedef bool(__cdecl* block_use_t)(Minecraft::Block* _this, Minecraft::Player* player, BlockPos* pos, unsigned char side);
typedef bool(__cdecl* itemstack_useon_t)(Minecraft::ItemStack* _this, Minecraft::Actor* user, int x, int y, int z, byte side, float, float, float);
typedef Minecraft::ItemDescriptor*(__thiscall* itemstackbase_get_descriptor_t)(Minecraft::ItemStackBase* _this, Minecraft::ItemDescriptor* out);
typedef void(__fastcall* serverlevel_tick_t)(Minecraft::ServerLevel* _this);

typedef Minecraft::PlayerInventory* (__cdecl* get_inventory_t)(Minecraft::Player* _this);
typedef item_list_t const(__cdecl* get_container_items_t)();

// Vtables 

typedef bool(__cdecl* gamemode_attack_t)(Minecraft::GameMode* _this, Minecraft::Actor*);
typedef bool(__cdecl* gamemode_destroy_t)(Minecraft::GameMode* _this, BlockPos* pos, unsigned __int8 side);

// (not sure what this is exactly)
typedef void(__cdecl* send_chat_message_t)(void*, Minecraft::Text* chatMessage, size_t, size_t, int*, void*, void*);