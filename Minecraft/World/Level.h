#pragma once
#include <iostream>
#include <functional>

#include "../Entity/Player.h"
#include "../NBT/CompoundTag.h"
#include "../Block/Block.h"
#include "../CTypes.h"
#include "../String/Text.h"

namespace Minecraft {
	template <typename T, typename S>
	class AutomaticID {
	public:
		S val;
	};
	class Level {
		// EatVtable.js (in.txt -> out.txt)
	private:
		virtual ~Level(); // 0x0   |   0x0
		virtual __int64 initialize(std::string const&, class LevelSettings const&, class LevelData*, class Experiments const&, std::string const*); // 0x8   |   0x1
		virtual __int64 postProcessResources(void); // 0x10   |   0x2
		virtual __int64 startLeaveGame(void); // 0x18   |   0x3
		virtual __int64 isLeaveGameDone(void); // 0x20   |   0x4
		virtual __int64 createDimension(AutomaticID<class Dimension, int>); // 0x28   |   0x5
		virtual __int64 getDimension(AutomaticID<Dimension, int>); // 0x30   |   0x6
		virtual __int64 forEachDimension(std::function<bool(Dimension const&)>); // 0x38   |   0x7
		virtual __int64 forEachDimension2(std::function<bool(Dimension const&)>); // 0x40   |   0x8
		virtual __int64 getChunkTickRange(void); // 0x48   |   0x9
		virtual __int64 getPortalForcer(void); // 0x50   |   0xA
		virtual __int64 requestPlayerChangeDimension(Player&, std::unique_ptr<class ChangeDimensionRequest>); // 0x58   |   0xB
		virtual __int64 entityChangeDimension(Actor&, AutomaticID<Dimension, int>); // 0x60   |   0xC
		virtual __int64 getSpawner(void); // 0x68   |   0xD
		virtual __int64 getProjectileFactory(void); // 0x70   |   0xE
		virtual __int64 getEntityDefinitions(void); // 0x78   |   0xF
		virtual __int64 getActorAnimationGroup(void); // 0x80   |   0x10
		virtual __int64 getActorAnimationControllerGroup(void); // 0x88   |   0x11
		virtual __int64 getBlockDefinitions(void); // 0x90   |   0x12
		virtual __int64 getBlockComponentFactory(void); // 0x98   |   0x13
		virtual __int64 getBlockComponentFactory2(void); // 0xA0   |   0x14
		virtual __int64 getSpawnRules(void); // 0xA8   |   0x15
		virtual __int64 getSpawnGroupRegistry(void); // 0xB0   |   0x16
		virtual __int64 getSpawnRules2(void); // 0xB8   |   0x17
		virtual __int64 getSpawnSettings(void); // 0xC0   |   0x18
		virtual __int64 setSpawnSettings(class SpawnSettings const&); // 0xC8   |   0x19
		virtual __int64 getBehaviorTreeGroup(void); // 0xD0   |   0x1A
		virtual __int64 getBehaviorFactory(void); // 0xD8   |   0x1B
		virtual __int64 getDifficulty(void); // 0xE0   |   0x1C
		virtual __int64 getDimensionConversionData(void); // 0xE8   |   0x1D
		virtual __int64 getSpecialMultiplier(AutomaticID<Dimension, int>); // 0xF0   |   0x1E
		virtual __int64 hasCommandsEnabled(void); // 0xF8   |   0x1F
		virtual __int64 useMsaGamertagsOnly(void); // 0x100   |   0x20
		virtual __int64 setMsaGamertagsOnly(bool); // 0x108   |   0x21
		virtual __int64 addEntity(BlockSource&, std::unique_ptr<Actor>); // 0x110   |   0x22
		virtual __int64 addGlobalEntity(BlockSource&, std::unique_ptr<Actor>); // 0x118   |   0x23
		virtual __int64 addAutonomousEntity(BlockSource&, std::unique_ptr<Actor>); // 0x120   |   0x24
		virtual __int64 addPlayer(std::unique_ptr<Player>); // 0x128   |   0x25
		virtual __int64 suspendPlayer(Player&); // 0x130   |   0x26
		virtual __int64 resumePlayer(Player&); // 0x138   |   0x27
		virtual __int64 isPlayerSuspended(Player&); // 0x140   |   0x28
		virtual __int64 takeEntity(class ActorUniqueID); // 0x148   |   0x29
		virtual __int64 borrowEntity(ActorUniqueID, class LevelChunk*); // 0x150   |   0x2A
		virtual __int64 fetchEntity(ActorUniqueID, bool); // 0x158   |   0x2B
		virtual __int64 getRuntimeEntity(class ActorRuntimeID, bool); // 0x160   |   0x2C
		virtual __int64 getMob(ActorUniqueID); // 0x168   |   0x2D
		virtual __int64 getPlayer(ActorUniqueID); // 0x170   |   0x2E
		virtual __int64 getPlayer(__int64); // 0x178   |   0x2F
		virtual __int64 filler0();
	public:
		virtual Player* getPlayer(Text*); // 0x180   |   0x30
	private:
		virtual __int64 getPlayerByXuid(std::string const&); // 0x188   |   0x31
		virtual __int64 getPlayerFromUnknownIdentifier(std::string const&); // 0x190   |   0x32
		virtual __int64 getPlatformPlayer(std::string const&); // 0x198   |   0x33
		virtual __int64 getPlayerFromServerId(std::string const&); // 0x1A0   |   0x34
		virtual __int64 getRuntimePlayer(class ActorRuntimeID); // 0x1A8   |   0x35
		virtual __int64 getNextPlayer(ActorUniqueID const&, bool); // 0x1B0   |   0x36
		virtual __int64 getPrevPlayer(ActorUniqueID const&, bool); // 0x1B8   |   0x37
		virtual __int64 getNumRemotePlayers(void); // 0x1C0   |   0x38
		virtual __int64 getPrimaryLocalPlayer(void); // 0x1C8   |   0x39
		virtual __int64 getRandomPlayer(void); // 0x1D0   |   0x3A
		virtual __int64 getNewPlayerId(void); // 0x1D8   |   0x3B
		virtual __int64 getEventing(void); // 0x1E0   |   0x3C
		virtual __int64 getPlayerColor(Player const&); // 0x1E8   |   0x3D
		virtual __int64 getCurrentTick(void); // 0x1F0   |   0x3E
		virtual __int64 getCurrentServerTick(void); // 0x1F8   |   0x3F
		virtual __int64 removeAllNonPlayerEntities(ActorUniqueID); // 0x200   |   0x40
		virtual __int64 getBiomeRegistry(void); // 0x208   |   0x41
		virtual __int64 getBiomeRegistry2(void); // 0x210   |   0x42
		virtual __int64 getBlockPalette(void); // 0x218   |   0x43
		virtual __int64 getBlockPalette2(void); // 0x220   |   0x44
		virtual __int64 getFeatureRegistry(void); // 0x228   |   0x45
		virtual __int64 getFeatureRegistry2(void); // 0x230   |   0x46
		virtual __int64 getFeatureTypeFactory(void); // 0x238   |   0x47
		virtual __int64 getFeatureTypeFactory2(void); // 0x240   |   0x48
		virtual __int64 getJigsawStructureRegistry(void); // 0x248   |   0x49
		virtual __int64 getJigsawStructureRegistry2(void); // 0x250   |   0x4A
		virtual __int64 getStructureManager(void); // 0x258   |   0x4B
		virtual __int64 getStructureManager2(void); // 0x260   |   0x4C
		virtual __int64 getBiomeComponentFactory(void); // 0x268   |   0x4D
		virtual __int64 getBiomeComponentFactory2(void); // 0x270   |   0x4E
		virtual __int64 getSurfaceBuilderRegistry(void); // 0x278   |   0x4F
		virtual __int64 getSurfaceBuilderRegistry2(void); // 0x280   |   0x50
		virtual __int64 getDimensionFactory(void); // 0x288   |   0x51
		virtual __int64 getDimensionFactory2(void); // 0x290   |   0x52
		virtual __int64 getLightTextureImageBuilderFactory(void); // 0x298   |   0x53
		virtual __int64 getLightTextureImageBuilderFactory2(void); // 0x2A0   |   0x54
		virtual __int64 addListener(class LevelListener&); // 0x2A8   |   0x55
		virtual __int64 removeListener(LevelListener&); // 0x2B0   |   0x56
		virtual __int64 tickEntities(void); // 0x2B8   |   0x57
		virtual __int64 tickEntitySystems(void); // 0x2C0   |   0x58
		virtual __int64 onPlayerDeath(Player&, class ActorDamageSource const&); // 0x2C8   |   0x59
		virtual __int64 tick(void); // 0x2D0   |   0x5A
		virtual __int64 nullsub_0(void); // 0x2D8   |   0x5B
		virtual __int64 animateTick(Actor&); // 0x2E0   |   0x5C
		virtual __int64 explode(class Explosion&); // 0x2E8   |   0x5D
		virtual __int64 explode(BlockSource&, Actor*, Vec3 const&, float, bool, bool, float, bool); // 0x2F0   |   0x5E
		virtual __int64 spawnParticleEffect(std::string const&, Actor const&, Vec3 const&); // 0x2F8   |   0x5F
		virtual __int64 spawnParticleEffect(std::string const&, Vec3 const&, Dimension*); // 0x300   |   0x60
		virtual __int64 denyEffect(BlockSource&, Vec3 const&); // 0x308   |   0x61
		virtual __int64 potionSplash(Vec3 const&, __int64 const&, bool); // 0x310   |   0x62
		virtual __int64 checkAndHandleWater(Actor*); // 0x318   |   0x63
		virtual __int64 checkMaterial(AABB const&, enum MaterialType, BlockSource&); // 0x320   |   0x64
		virtual __int64 extinguishFire(BlockSource&, BlockPos const&, unsigned char); // 0x328   |   0x65
		virtual __int64 findPath(Actor&, Actor&, class NavigationComponent&); // 0x330   |   0x66
		virtual __int64 findPath(Actor&, int, int, int, class NavigationComponent&); // 0x338   |   0x67
		virtual __int64 updateSleepingPlayerList(void); // 0x340   |   0x68
		virtual __int64 getTime(void); // 0x348   |   0x69
		virtual __int64 setTime(int); // 0x350   |   0x6A
		virtual __int64 getSeed(void); // 0x358   |   0x6B
		virtual __int64 getDefaultSpawn(void); // 0x360   |   0x6C
		virtual __int64 setDefaultSpawn(BlockPos const&); // 0x368   |   0x6D
		virtual __int64 getDefaultSpawn2(void); // 0x370   |   0x6E
		virtual __int64 setDefaultGameType(class GameType); // 0x378   |   0x6F
		virtual __int64 getDefaultGameType(void); // 0x380   |   0x70
		virtual __int64 setDifficulty(enum Difficulty); // 0x388   |   0x71
		virtual __int64 setMultiplayerGameIntent(bool); // 0x390   |   0x72
		virtual __int64 getMultiplayerGameIntent(void); // 0x398   |   0x73
		virtual __int64 setMultiplayerGame(bool); // 0x3A0   |   0x74
		virtual __int64 isMultiplayerGame(void); // 0x3A8   |   0x75
		virtual __int64 setLANBroadcastIntent(bool); // 0x3B0   |   0x76
		virtual __int64 getLANBroadcastIntent(void); // 0x3B8   |   0x77
		virtual __int64 setLANBroadcast(bool); // 0x3C0   |   0x78
		virtual __int64 getLANBroadcast(void); // 0x3C8   |   0x79
		virtual __int64 setXBLBroadcastIntent(__int64); // 0x3D0   |   0x7A
		virtual __int64 getXBLBroadcastIntent(void); // 0x3D8   |   0x7B
		virtual __int64 hasXBLBroadcastIntent(void); // 0x3E0   |   0x7C
		virtual __int64 setXBLBroadcastMode(__int64); // 0x3E8   |   0x7D
		virtual __int64 getXBLBroadcastMode(void); // 0x3F0   |   0x7E
		virtual __int64 hasXBLBroadcast(void); // 0x3F8   |   0x7F
		virtual __int64 setPlatformBroadcastIntent(__int64); // 0x400   |   0x80
		virtual __int64 getPlatformBroadcastIntent(void); // 0x408   |   0x81
		virtual __int64 hasPlatformBroadcastIntent(void); // 0x410   |   0x82
		virtual __int64 setPlatformBroadcastMode(__int64); // 0x418   |   0x83
		virtual __int64 getPlatformBroadcastMode(void); // 0x420   |   0x84
		virtual __int64 hasPlatformBroadcast(void); // 0x428   |   0x85
		virtual __int64 setHasLockedBehaviorPack(bool); // 0x430   |   0x86
		virtual __int64 setHasLockedResourcePack(bool); // 0x438   |   0x87
		virtual __int64 setCommandsEnabled(bool); // 0x440   |   0x88
		virtual __int64 setWorldTemplateOptionsUnlocked(void); // 0x448   |   0x89
		virtual __int64 nullsub_1(void); // 0x450   |   0x8A
		virtual __int64 getLevelStorage(void); // 0x458   |   0x8B
		virtual __int64 getLevelStorage2(void); // 0x460   |   0x8C
		virtual __int64 getLevelData(void); // 0x468   |   0x8D
		virtual __int64 getLevelData2(void); // 0x470   |   0x8E
		virtual __int64 getPhotoStorage(void); // 0x478   |   0x8F
		virtual __int64 createPhotoStorage(void); // 0x480   |   0x90
		virtual __int64 setEducationLevelSettings(class EducationLevelSettings); // 0x488   |   0x91
		virtual __int64 getEducationLevelSettings(void); // 0x490   |   0x92
		virtual __int64 save(void); // 0x498   |   0x93
		virtual __int64 saveEducationLevelSettings(void); // 0x4A0   |   0x94
		virtual __int64 saveLevelData(void); // 0x4A8   |   0x95
		virtual __int64 saveGameData(void); // 0x4B0   |   0x96
		virtual __int64 saveVillages(void); // 0x4B8   |   0x97
		virtual __int64 savePlayers(void); // 0x4C0   |   0x98
		virtual __int64 savePlayer(Player&); // 0x4C8   |   0x99
		virtual __int64 saveBiomeData(void); // 0x4D0   |   0x9A
		virtual __int64 saveDirtyChunks(void); // 0x4D8   |   0x9B
		virtual __int64 saveAdditionalData(void); // 0x4E0   |   0x9C
		virtual __int64 requestTimedStorageDeferment(void); // 0x4E8   |   0x9D
		virtual __int64 _checkUserStorage(void); // 0x4F0   |   0x9E
		virtual __int64 getTickingAreasMgr(void); // 0x4F8   |   0x9F
		virtual __int64 getTickingArea(__int64 const&); // 0x500   |   0xA0
		virtual __int64 addParticle(class ParticleType, Vec3 const&, Vec3 const&, int, CompoundTag const*, bool); // 0x508   |   0xA1
		virtual __int64 sendServerLegacyParticle(ParticleType, Vec3 const&, Vec3 const&, int); // 0x510   |   0xA2
		virtual __int64 playSound(BlockSource&, struct LevelSoundEvent, Vec3 const&, int, class ActorDefinitionIdentifier const&, bool, bool); // 0x518   |   0xA3
		virtual __int64 handleSoundEvent(LevelSoundEvent, Vec3 const&, int, ActorDefinitionIdentifier const&, bool, bool); // 0x520   |   0xA4
		virtual __int64 playSynchronizedSound(BlockSource&, LevelSoundEvent, Vec3 const&, int, ActorDefinitionIdentifier const&, bool, bool); // 0x528   |   0xA5
		virtual __int64 playSynchronizedSound(BlockSource&, LevelSoundEvent, Vec3 const&, Block const&, ActorDefinitionIdentifier const&, bool, bool); // 0x530   |   0xA6
		virtual __int64 setRemotePlayerEventCoordinator(std::unique_ptr<class PlayerEventCoordinator>&&); // 0x538   |   0xA7
		virtual __int64 getRemotePlayerEventCoordinator(void); // 0x540   |   0xA8
		virtual __int64 setServerPlayerEventCoordinator(std::unique_ptr<class ServerPlayerEventCoordinator>&&); // 0x548   |   0xA9
		virtual __int64 getServerPlayerEventCoordinator(void); // 0x550   |   0xAA
		virtual __int64 setClientPlayerEventCoordinator(std::unique_ptr<class ClientPlayerEventCoordinator>&&); // 0x558   |   0xAB
		virtual __int64 getClientPlayerEventCoordinator(void); // 0x560   |   0xAC
		virtual __int64 setActorEventCoordinator(std::unique_ptr<class ActorEventCoordinator>&&); // 0x568   |   0xAD
		virtual __int64 getActorEventCoordinator(void); // 0x570   |   0xAE
		virtual __int64 setBlockEventCoordinator(std::unique_ptr<class BlockEventCoordinator>&&); // 0x578   |   0xAF
		virtual __int64 getBlockEventCoordinator(void); // 0x580   |   0xB0
		virtual __int64 setItemEventCoordinator(std::unique_ptr<class ItemEventCoordinator>&&); // 0x588   |   0xB1
		virtual __int64 getItemEventCoordinator(void); // 0x590   |   0xB2
		virtual __int64 getLevelEventCoordinator(void); // 0x598   |   0xB3
		virtual __int64 handleLevelEvent(class LevelEvent, CompoundTag const&); // 0x5A0   |   0xB4
		virtual __int64 handleLevelEvent(LevelEvent, Vec3 const&, int); // 0x5A8   |   0xB5
		virtual __int64 handleSoundEvent(std::string const&, Vec3 const&, float, float); // 0x5B0   |   0xB6
		virtual __int64 handleSoundEvent2(LevelSoundEvent, Vec3 const&, int, ActorDefinitionIdentifier const&, bool, bool); // 0x5B8   |   0xB7
		virtual __int64 handleStopSoundEvent(std::string const&); // 0x5C0   |   0xB8
		virtual __int64 handleStopAllSounds(void); // 0x5C8   |   0xB9
		virtual __int64 broadcastLevelEvent(LevelEvent, CompoundTag const&, Player*); // 0x5D0   |   0xBA
		virtual __int64 broadcastLevelEvent(LevelEvent, Vec3 const&, int, Player*); // 0x5D8   |   0xBB
		virtual __int64 broadcastLocalEvent(BlockSource&, LevelEvent, Vec3 const&, Block const&); // 0x5E0   |   0xBC
		virtual __int64 broadcastLocalEvent(BlockSource&, LevelEvent, Vec3 const&, int); // 0x5E8   |   0xBD
		virtual __int64 broadcastSoundEvent(BlockSource&, LevelSoundEvent, Vec3 const&, int, ActorDefinitionIdentifier const&, bool, bool); // 0x5F0   |   0xBE
		virtual __int64 broadcastSoundEvent(BlockSource&, LevelSoundEvent, Vec3 const&, Block const&, ActorDefinitionIdentifier const&, bool, bool); // 0x5F8   |   0xBF
		virtual __int64 broadcastActorEvent(Actor&, class ActorEvent, int); // 0x600   |   0xC0
		virtual __int64 addBossEventListener(class BossEventListener*); // 0x608   |   0xC1
		virtual __int64 removeBossEventListener(BossEventListener*); // 0x610   |   0xC2
		virtual __int64 broadcastBossEvent(class BossEventUpdateType); // 0x618   |   0xC3
		virtual __int64 broadcastBossEvent(BossEventUpdateType, ActorUniqueID const&, class BossEventPacket const&); // 0x620   |   0xC4
		virtual __int64 areBossEventListenersReady(void); // 0x628   |   0xC5
		virtual __int64 addChunkViewTracker(std::weak_ptr<class ChunkViewSource>); // 0x630   |   0xC6
		virtual __int64 pruneChunkViewTrackers(void); // 0x638   |   0xC7
		virtual __int64 onChunkReload(class Bounds const&); // 0x640   |   0xC8
		virtual __int64 getPlayerNames(void); // 0x648   |   0xC9
		virtual __int64 getActivePlayerCount(void); // 0x650   |   0xCA
		virtual __int64 forEachPlayer(std::function<bool(Player const&)>); // 0x658   |   0xCB
		virtual __int64 forEachPlayer2(std::function<bool(Player const&)>); // 0x660   |   0xCC
		virtual __int64 findPlayer(std::function<bool(Player const&)>); // 0x668   |   0xCD
		virtual __int64 getUserCount(void); // 0x670   |   0xCE
		virtual __int64 nullsub_2(void); // 0x678   |   0xCF
		virtual __int64 nullsub_3(void); // 0x680   |   0xD0
		virtual __int64 onChunkLoaded(class ChunkSource&, LevelChunk&); // 0x688   |   0xD1
		virtual __int64 onChunkDiscarded(LevelChunk&); // 0x690   |   0xD2
		virtual __int64 queueEntityRemoval(std::unique_ptr<Actor>&&, bool); // 0x698   |   0xD3
		virtual __int64 removeEntityReferences(Actor&, bool); // 0x6A0   |   0xD4
		virtual __int64 forceRemoveEntity(Actor&); // 0x6A8   |   0xD5
		virtual __int64 forceFlushRemovedPlayers(void); // 0x6B0   |   0xD6
		virtual __int64 loadFunctionManager(void); // 0x6B8   |   0xD7
		virtual __int64 levelCleanupQueueEntityRemoval(std::unique_ptr<Actor>&&, bool); // 0x6C0   |   0xD8
		virtual __int64 registerTemporaryPointer(class _TickPtr&); // 0x6C8   |   0xD9
		virtual __int64 unregisterTemporaryPointer(_TickPtr&); // 0x6D0   |   0xDA
		virtual __int64 destroyBlock(BlockSource&, BlockPos const&, bool); // 0x6D8   |   0xDB
		virtual __int64 upgradeStorageVersion(class StorageVersion); // 0x6E0   |   0xDC
		virtual __int64 suspendAndSave(void); // 0x6E8   |   0xDD
		virtual __int64 waitAsyncSuspendWork(void); // 0x6F0   |   0xDE
		virtual __int64 _destroyEffect(BlockPos const&, Block const&, int); // 0x6F8   |   0xDF
		virtual __int64 addParticleEffect(struct HashedString const&, Actor const&, HashedString const&, Vec3 const&, __int64 const&); // 0x700   |   0xE0
		virtual __int64 addParticleEffect(HashedString const&, Vec3 const&, __int64 const&); // 0x708   |   0xE1
		virtual __int64 addTerrainParticleEffect(BlockPos const&, Block const&, Vec3 const&, float, float, float); // 0x710   |   0xE2
		virtual __int64 addTerrainSlideEffect(BlockPos const&, Block const&, Vec3 const&, float, float, float); // 0x718   |   0xE3
		virtual __int64 addBreakingItemParticleEffect(Vec3 const&, ParticleType, class TextureUVCoordinateSet const&, bool); // 0x720   |   0xE4
		virtual __int64 getNewUniqueID(void); // 0x728   |   0xE5
		virtual __int64 getNextRuntimeID(void); // 0x730   |   0xE6
		virtual __int64 nullsub_4(void); // 0x738   |   0xE7
		virtual __int64 nullsub_5(void); // 0x740   |   0xE8
		virtual __int64 isExporting(void); // 0x748   |   0xE9
		virtual __int64 setIsExporting(bool); // 0x750   |   0xEA
		virtual __int64 getSavedData(void); // 0x758   |   0xEB
		virtual __int64 getMapSavedData(CompoundTag const*); // 0x760   |   0xEC
		virtual __int64 getMapSavedData2(CompoundTag const*); // 0x768   |   0xED
		virtual __int64 getMapSavedData(ActorUniqueID); // 0x770   |   0xEE
		virtual __int64 requestMapInfo(ActorUniqueID, bool); // 0x778   |   0xEF
		virtual __int64 expandMapByID(ActorUniqueID, bool); // 0x780   |   0xF0
		virtual __int64 copyAndLockMap(ActorUniqueID, ActorUniqueID); // 0x788   |   0xF1
		virtual __int64 createMapSavedData(std::vector<ActorUniqueID> const&, BlockPos const&, AutomaticID<Dimension, int>, int); // 0x790   |   0xF2
		virtual __int64 createMapSavedData(ActorUniqueID const&, BlockPos const&, AutomaticID<Dimension, int>, int); // 0x798   |   0xF3
		virtual __int64 getScreenshotsFolder(void); // 0x7A0   |   0xF4
		virtual __int64 getLevelId(void); // 0x7A8   |   0xF5
		virtual __int64 setLevelId(std::string); // 0x7B0   |   0xF6
		virtual __int64 getSyncTasksGroup(void); // 0x7B8   |   0xF7
		virtual __int64 getIOTasksGroup(void); // 0x7C0   |   0xF8
		virtual __int64 getClientResourcePackManager(void); // 0x7C8   |   0xF9
		virtual __int64 getServerResourcePackManager(void); // 0x7D0   |   0xFA
		virtual __int64 getTradeTables(void); // 0x7D8   |   0xFB
		virtual __int64 addEntryToTagCache(std::string const&); // 0x7E0   |   0xFC
		virtual __int64 addEntriesToTagCache(std::vector<std::string>); // 0x7E8   |   0xFD
		virtual __int64 dropEntryFromTagCache(std::string const&); // 0x7F0   |   0xFE
		virtual __int64 clearTagCache(void); // 0x7F8   |   0xFF
		virtual __int64 decrementTagCache(std::string const&, /*TagRegistry<IDType<LevelTagIDType>, IDType<LevelTagSetIDType>>&*/__int64, __int64); // 0x800   |   0x100
		virtual __int64 incrementTagCache(std::string const&, /*TagRegistry<IDType<LevelTagIDType>, IDType<LevelTagSetIDType>>&*/__int64, __int64); // 0x808   |   0x101
		virtual __int64 isEdu(void); // 0x810   |   0x102
		virtual __int64 getActorFactory(void); // 0x818   |   0x103
		virtual __int64 getActorFactory2(void); // 0x820   |   0x104
		virtual __int64 getActorInfoRegistry(void); // 0x828   |   0x105
		virtual __int64 getEntityRegistryOwner(void); // 0x830   |   0x106
		virtual __int64 getEntitySystems(void); // 0x838   |   0x107
		virtual __int64 _clientHandleAddOwnedEntity(class EntityNetId); // 0x840   |   0x108
		virtual __int64 _clientHandleAddWeakRefEntity(EntityNetId, /*WeakRefT<EntityRefTraits> const&*/__int64); // 0x848   |   0x109
		virtual __int64 _clientHandleRemoveOwnedEntity(EntityNetId); // 0x850   |   0x10A
		virtual __int64 _clientHandleRemoveOwnedEntity2(EntityNetId); // 0x858   |   0x10B
		virtual __int64 runCommand(class Command&, class CommandOrigin&, class CommandOriginSystem); // 0x860   |   0x10C
		virtual __int64 runCommand(HashedString const&, CommandOrigin&, CommandOriginSystem, class CurrentCmdVersion); // 0x868   |   0x10D
		virtual __int64 getTagRegistry(void); // 0x870   |   0x10E
		virtual __int64 getPlayerMovementSettings(void); // 0x878   |   0x10F
		virtual __int64 setPlayerMovementSettings(class PlayerMovementSettings const&); // 0x880   |   0x110
		virtual __int64 nullsub_6(void); // 0x888   |   0x111
		virtual __int64 getPositionTrackerDBClient(void); // 0x890   |   0x112
		virtual __int64 getPositionTrackerDBServer(void); // 0x898   |   0x113
		virtual __int64 flushRunTimeLighting(void); // 0x8A0   |   0x114
		virtual __int64 loadBlockDefinitionGroup(Experiments const&); // 0x8A8   |   0x115
		virtual __int64 initializeBlockDefinitionGroup(void); // 0x8B0   |   0x116
		virtual __int64 getUnknownBlockTypeRegistry(void); // 0x8B8   |   0x117
		virtual __int64 nullsub_7(void); // 0x8C0   |   0x118
		virtual __int64 isClientSide(void); // 0x8C8   |   0x119
		virtual __int64 getPlayerList(void); // 0x8D0   |   0x11A
		virtual __int64 getPlayerList2(void); // 0x8D8   |   0x11B
		virtual __int64 getPlayerXUID(__int64 const&); // 0x8E0   |   0x11C
		virtual __int64 getPlayerPlatformOnlineId(__int64 const&); // 0x8E8   |   0x11D
		virtual __int64 nullsub_8(void); // 0x8F0   |   0x11E
		virtual __int64 getGlobalEntities(void); // 0x8F8   |   0x11F
		virtual __int64 getAutonomousEntities(void); // 0x900   |   0x120
		virtual __int64 getRuntimeActorList(void); // 0x908   |   0x121
		virtual __int64 getAutonomousActiveEntity(ActorUniqueID); // 0x910   |   0x122
		virtual __int64 getAutonomousInactiveEntity(ActorUniqueID); // 0x918   |   0x123
		virtual __int64 getAutonomousEntity(ActorUniqueID); // 0x920   |   0x124
		virtual __int64 getAutonomousLoadedEntities(void); // 0x928   |   0x125
		virtual __int64 removeAutonomousEntity(Actor&, LevelChunk*); // 0x930   |   0x126
		virtual __int64 getPacketSender(void); // 0x938   |   0x127
		virtual __int64 setPacketSender(class PacketSender*); // 0x940   |   0x128
		virtual __int64 getNetEventCallback(void); // 0x948   |   0x129
		virtual __int64 setNetEventCallback(class NetEventCallback*); // 0x950   |   0x12A
		virtual __int64 getRandom(void); // 0x958   |   0x12B
		virtual __int64 getHitResult(void); // 0x960   |   0x12C
		virtual __int64 getLiquidHitResult(void); // 0x968   |   0x12D
		virtual __int64 getAdventureSettings(void); // 0x970   |   0x12E
		virtual __int64 getGameRules(void); // 0x978   |   0x12F
		virtual __int64 getGameRules2(void); // 0x980   |   0x130
		virtual __int64 hasStartWithMapEnabled(void); // 0x988   |   0x131
		virtual __int64 getDefaultAbilities(void); // 0x990   |   0x132
		virtual __int64 getTearingDown(void); // 0x998   |   0x133
		virtual __int64 takePicture(class /*cg:: TODO*/ImageBuffer&, Actor*, Actor*, class ScreenshotOptions&); // 0x9A0   |   0x134
		virtual __int64 getSoundPlayer(void); // 0x9A8   |   0x135
		virtual __int64 setSimPaused(bool); // 0x9B0   |   0x136
		virtual __int64 getSimPaused(void); // 0x9B8   |   0x137
		virtual __int64 setFinishedInitializing(void); // 0x9C0   |   0x138
		virtual __int64 getLootTables(void); // 0x9C8   |   0x139
		virtual __int64 updateWeather(float, int, float, int); // 0x9D0   |   0x13A
		virtual __int64 getNetherScale(void); // 0x9D8   |   0x13B
		virtual __int64 getScoreboard(void); // 0x9E0   |   0x13C
		virtual __int64 getPlayerAbilities(ActorUniqueID const&); // 0x9E8   |   0x13D
		virtual __int64 setPlayerAbilities(ActorUniqueID const&, class Abilities); // 0x9F0   |   0x13E
		virtual __int64 sendAllPlayerAbilities(Player const&); // 0x9F8   |   0x13F
		virtual __int64 incrementSpawnableTickedMob(void); // 0xA00   |   0x140
		virtual __int64 getSpawnableTickedMobCountPrevious(void); // 0xA08   |   0x141
		virtual __int64 getRecipes(void); // 0xA10   |   0x142
		virtual __int64 digestServerBlockProperties(class StartGamePacket const&, unsigned int); // 0xA18   |   0x143
		virtual __int64 digestServerItemComponents(class ItemComponentPacket const&); // 0xA20   |   0x144
		virtual __int64 getRegisteredBorderBlock(void); // 0xA28   |   0x145
		virtual __int64 nullsub_9(void); // 0xA30   |   0x146
		virtual __int64 nullsub_10(void); // 0xA38   |   0x147
	};
	
	class ServerLevel : public Level {
	public:
		virtual ~ServerLevel();
	};
}