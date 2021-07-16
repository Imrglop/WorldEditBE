#pragma once
#include "Actor.h"
#include "Mob.h"
#include "../Inventory/PlayerInventory.h"

namespace Minecraft {
	class Tick;

	class Player : public Mob {
	public:
		// CUSTOM FUNCTIONS
		inline PlayerInventory* getSupplies() {
			return *reinterpret_cast<PlayerInventory**>(reinterpret_cast<unsigned __int64>(this) + 0x0C88);
		}

		// EatVtable.js
		virtual __int64 prepareRegion(class ChunkSource&); // 0x170
		virtual __int64 destroyRegion(void); // 0x171
		virtual __int64 suspendRegion(void); // 0x172
		virtual __int64 resendAllChunks(void); // 0x173
		virtual __int64 _fireWillChangeDimension(void); // 0x174
		virtual __int64 _fireDimensionChanged(void); // 0x175
		virtual __int64 changeDimensionWithCredits(__int64); // 0x176
		virtual __int64 tickWorld(Tick const&); // 0x177
		virtual __int64 nullsub_0(void); // 0x178
		virtual __int64 getTickingOffsets(void); // 0x179
		virtual __int64 moveView(void); // 0x17A
		virtual __int64 setName(Text const&); // 0x17B
		virtual __int64 checkMovementStats(Vec3 const&); // 0x17C
		virtual __int64 getCurrentStructureFeature(void); // 0x17D
		virtual __int64 isAutoJumpEnabled(void); // 0x17E
		virtual __int64 respawn(void); // 0x17F
		virtual __int64 resetRot(void); // 0x180
		virtual __int64 resetPos(bool); // 0x181
		virtual __int64 isInTrialMode(void); // 0x182
		virtual __int64 hasResource(int); // 0x183
		virtual __int64 completeUsingItem(void); // 0x184
		virtual __int64 setPermissions(__int64); // 0x185
		virtual __int64 startDestroying(void); // 0x186
		virtual __int64 stopDestroying(void); // 0x187
		virtual __int64 openPortfolio(void); // 0x188
		virtual __int64 openBook(int, bool, int, class BlockActor*); // 0x189
		virtual __int64 openTrading(__int64 const&, bool); // 0x18A
		virtual __int64 canOpenContainerScreen(void); // 0x18B
		virtual __int64 openChalkboard(__int64&, bool); // 0x18C
		virtual __int64 openNpcInteractScreen(std::shared_ptr<__int64>); // 0x18D
		virtual __int64 openInventory(void); // 0x18E
		virtual __int64 displayChatMessage(Text const&, Text const&); // 0x18F

		virtual void displayClientMessage(Text const&); // 0x190

		void displayClientMessage(std::string s) {
			displayClientMessage(*reinterpret_cast<Text*>(&s));
		}

		virtual __int64 displayTextObjectMessage(__int64 const&, Text const&, Text const&); // 0x191
		virtual __int64 displayTextObjectWhisperMessage(__int64 const&, Text const&, Text const&); // 0x192
		virtual __int64 displayWhisperMessage(Text const&, Text const&, Text const&, Text const&); // 0x193
		virtual __int64 startSleepInBed(BlockPos const&); // 0x194
		virtual __int64 stopSleepInBed(bool, bool); // 0x195
		virtual __int64 canStartSleepInBed(void); // 0x196
		virtual __int64 getSleepTimer(void); // 0x197
		virtual __int64 getPreviousTickSleepTimer(void); // 0x198
		virtual __int64 openSign(BlockPos const&); // 0x199
		virtual __int64 playEmote(Text const&); // 0x19A
		virtual __int64 isHostingPlayer(void); // 0x19B
		virtual __int64 isLoading(void); // 0x19C
		virtual __int64 isPlayerInitialized(void); // 0x19D
		virtual __int64 stopLoading(void); // 0x19E
		virtual __int64 registerTrackedBoss(__int64); // 0x19F
		virtual __int64 unRegisterTrackedBoss(__int64); // 0x1A0
		virtual __int64 setPlayerGameType(int); // 0x1A1
		virtual __int64 initHUDContainerManager(void); // 0x1A2
		virtual __int64 _crit(Actor&); // 0x1A3
		virtual __int64 getEventing(void); // 0x1A4
		virtual __int64 getUserId(void); // 0x1A5
		virtual __int64 sendEventPacket(__int64&); // 0x1A6
		virtual __int64 addExperience(int); // 0x1A7
		virtual __int64 addLevels(int); // 0x1A8
		virtual __int64 nullsub_1(void); // 0x1A9
		virtual __int64 nullsub_2(void); // 0x1AA
		virtual __int64 inventoryChanged(Container&, int, ItemStack const&, ItemStack const&, bool); // 0x1AB
		virtual __int64 nullsub_3(void); // 0x1AC
		virtual __int64 deleteContainerManager(void); // 0x1AD
		virtual __int64 setFieldOfViewModifier(float); // 0x1AE
		virtual __int64 is2DPositionRelevant(__int64, BlockPos const&); // 0x1AF
		virtual __int64 isEntityRelevant(Actor const&); // 0x1B0
		virtual __int64 nullsub_4(void); // 0x1B1
		virtual __int64 onSuspension(void); // 0x1B2
		virtual __int64 onLinkedSlotsChanged(void); // 0x1B3
		virtual __int64 startCooldown(Item const*); // 0x1B4
		virtual __int64 getItemCooldownLeft(Text const&); // 0x1B5
		virtual __int64 isItemInCooldown(Text const&); // 0x1B6
		virtual __int64 nullsub_5(void); // 0x1B7
		virtual __int64 nullsub_6(void); // 0x1B8
		virtual __int64 sendNetworkPacket(__int64&); // 0x1B9
		virtual __int64 nullsub_7(void); // 0x1BA
		virtual __int64 nullsub_8(void); // 0x1BB
		virtual __int64 nullsub_9(void); // 0x1BC
		virtual __int64 nullsub_10(void); // 0x1BD
		virtual __int64 reportMovementTelemetry(__int64); // 0x1BE
		virtual __int64 onMovePlayerPacketNormal(Vec3 const&, Vec2 const&, float); // 0x1BF
	};
}