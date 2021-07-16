#pragma once
#include "CNamespacedID.h"

#include "../Vector/AABB.h"
#include "../Vector/Vec2.h"
#include "../Vector/CRotation.h"
#include "../String/Text.h"

#include "../Block/BlockSource.h"

#include "CCollisionBox.h"
#include "../Block/Block.h"

#include <functional>

namespace Minecraft {
	class Actor {
	public:

		enum InitializationMethod : __int64 {};

		BlockSource* getRegionConst() {
			return *reinterpret_cast<BlockSource**>((__int64)this + 0x368);
		}

		// EatVtable.js (in.txt -> out.txt)
		virtual __int64 reloadHardcoded(Actor::InitializationMethod, struct VariantParameterList const&); // 0x0
		virtual __int64 reloadHardcodedClient(Actor::InitializationMethod, VariantParameterList const&); // 0x1
		virtual __int64 initializeComponents(Actor::InitializationMethod, VariantParameterList const&); // 0x2
		virtual __int64 reloadComponents(Actor::InitializationMethod, VariantParameterList const&); // 0x3
		virtual __int64 _serverInitItemStackIds(void); // 0x4
		virtual __int64 _doInitialMove(void); // 0x5
		virtual bool hasComponent(struct HashedString const&); // 0x6
		virtual ~Actor(); // 0x7
		virtual __int64 reset(void); // 0x9
		virtual __int64 getOnDeathExperience(void); // 0xA
		virtual __int64 getOwnerEntityType(void); // 0xB
		virtual __int64 remove(void); // 0xC
		virtual void setPos(Vec3 const&); // 0xD
		virtual bool isRuntimePredictedMovementEnabled(void); // 0xE
		virtual __int64 getPredictedMovementValues(void); // 0xF
		virtual Vec3& getPos(void); // 0x10
		virtual Vec3& getPosOld(void); // 0x11
		virtual Vec3& getPosExtrapolated(float); // 0x12
		virtual __int64 getAttachPos(__int64, float); // 0x13
		virtual __int64 getFiringPos(void); // 0x14
		virtual void setRot(Vec2 const&); // 0x15
		virtual __int64 move(Vec3 const&); // 0x16
		virtual __int64 move(__int64&, Vec3 const&); // 0x17
		virtual __int64 getInterpolatedRidingPosition(float); // 0x18
		virtual __int64 getInterpolatedBodyRot(float); // 0x19
		virtual __int64 getInterpolatedHeadRot(float); // 0x1A
		virtual __int64 getInterpolatedBodyYaw(float); // 0x1B
		virtual __int64 getYawSpeedInDegreesPerSecond(void); // 0x1C
		virtual __int64 getInterpolatedWalkAnimSpeed(float); // 0x1D
		virtual __int64 getInterpolatedRidingOffset(float); // 0x1E
		virtual __int64 checkBlockCollisions(AABB const&, __int64); // 0x1F  std::function<void()(BlockSource&, Block const&, BlockPos const&, Actor&)>
		virtual __int64 updateEntityInside(AABB const&); // 0x20
		virtual __int64 updateEntityInside(void); // 0x21
		virtual bool isFireImmune(void); // 0x22
		virtual __int64 breaksFallingBlocks(void); // 0x23
		virtual __int64 blockedByShield(__int64 const&, Actor&); // 0x24
		virtual __int64 teleportTo(Vec3 const&, bool, int, int); // 0x25
		virtual __int64 tryTeleportTo(Vec3 const&, bool, bool, int, int); // 0x26
		virtual __int64 chorusFruitTeleport(Vec3&); // 0x27
		virtual __int64 lerpTo(Vec3 const&, Vec2 const&, int); // 0x28
		virtual __int64 lerpMotion(Vec3 const&); // 0x29
		virtual __int64 tryCreateAddActorPacket(void); // 0x2A
		virtual __int64 normalTick(void); // 0x2B
		virtual __int64 baseTick(void); // 0x2C
		virtual __int64 rideTick(void); // 0x2D
		virtual __int64 positionRider(Actor&, float); // 0x2E
		virtual __int64 getRidingHeight(void); // 0x2F
		virtual __int64 startRiding(Actor&); // 0x30
		virtual __int64 addRider(Actor&); // 0x31
		virtual __int64 flagRiderToRemove(Actor&); // 0x32
		virtual __int64 getExitTip(Text const&, struct InputMode); // 0x33
		virtual __int64 intersects(Vec3 const&, Vec3 const&); // 0x34
		virtual bool isFree(Vec3 const&, float); // 0x35
		virtual bool isFree(Vec3 const&); // 0x36
		virtual bool isInWall(void); // 0x37
		virtual bool isInvisible(void); // 0x38
		virtual __int64 canShowNameTag(void); // 0x39
		virtual __int64 canExistInPeaceful(void); // 0x3A
		virtual void setNameTagVisible(bool); // 0x3B
		virtual Text* getNameTag(void); // 0x3C
		virtual __int64 getNameTagAsHash(void); // 0x3D
		virtual __int64 getFormattedNameTag(void); // 0x3E
		virtual __int64 filterFormattedNameTag(struct UIProfanityContext const&); // 0x3F
		virtual void setNameTag(Text const&); // 0x40
		virtual __int64 getAlwaysShowNameTag(void); // 0x41
		virtual void setScoreTag(Text const&); // 0x42
		virtual __int64 getScoreTag(void); // 0x43
		virtual bool isInWater(void); // 0x44
		virtual bool hasEnteredWater(void); // 0x45
		virtual bool isImmersedInWater(void); // 0x46
		virtual bool isInLava(void); // 0x47
		virtual bool isUnderLiquid(__int64); // 0x48
		virtual bool isOverWater(void); // 0x49
		virtual void setBlockMovementSlowdownMultiplier(Vec3 const&); // 0x4A
		virtual __int64 resetBlockMovementSlowdownMultiplier(void); // 0x4B
		virtual __int64 getCameraOffset(void); // 0x4C
		virtual __int64 getShadowHeightOffs(void); // 0x4D
		virtual __int64 getShadowRadius(void); // 0x4E
		virtual __int64 getHeadLookVector(float); // 0x4F
		virtual __int64 canSeeInvisible(void); // 0x50
		virtual __int64 canSee(Actor const&); // 0x51
		virtual __int64 canSee(Vec3 const&); // 0x52
		virtual bool isSkyLit(float); // 0x53
		virtual __int64 getBrightness(float); // 0x54
		virtual __int64 interactPreventDefault(void); // 0x55
		virtual __int64 playerTouch(class Player&); // 0x56
		virtual __int64 onAboveBubbleColumn(bool); // 0x57
		virtual __int64 onInsideBubbleColumn(bool); // 0x58
		virtual bool isImmobile(void); // 0x59
		virtual bool isSilent(void); // 0x5A
		virtual bool isPickable(void); // 0x5B
		virtual bool isFishable(void); // 0x5C
		virtual bool isSleeping(void); // 0x5D
		virtual bool isShootable(void); // 0x5E
		virtual void setSneaking(bool); // 0x5F
		virtual bool isBlocking(void); // 0x60
		virtual bool isDamageBlocked(__int64 const&); // 0x61
		virtual bool isAlive(void); // 0x62
		virtual bool isOnFire(void); // 0x63
		virtual bool isOnHotBlock(void); // 0x64
		virtual bool isCreativeModeAllowed(void); // 0x65
		virtual bool isSurfaceMob(void); // 0x66
		virtual bool isTargetable(void); // 0x67
		virtual bool isLocalPlayer(void); // 0x68
		virtual bool isPlayer(void); // 0x69
		virtual bool isAffectedByWaterBottle(void); // 0x6A
		virtual __int64 canAttack(Actor*, bool); // 0x6B
		virtual void setTarget(Actor*); // 0x6C
		virtual __int64 findAttackTarget(void); // 0x6D
		virtual bool isValidTarget(Actor*); // 0x6E
		virtual __int64 attack(Actor&, __int64 const&); // 0x6F
		virtual __int64 performRangedAttack(Actor&, float); // 0x70
		virtual __int64 adjustDamageAmount(int&); // 0x71
		virtual __int64 getEquipmentCount(void); // 0x72
		virtual void setOwner(__int64); // 0x73
		virtual void setSitting(bool); // 0x74
		virtual __int64 onTame(void); // 0x75
		virtual __int64 onFailedTame(void); // 0x76
		virtual __int64 getInventorySize(void); // 0x77
		virtual __int64 getEquipSlots(void); // 0x78
		virtual __int64 getChestSlots(void); // 0x79
		virtual void setStanding(bool); // 0x7A
		virtual __int64 canPowerJump(void); // 0x7B
		virtual void setCanPowerJump(bool); // 0x7C
		virtual bool isJumping(void); // 0x7D
		virtual bool isEnchanted(void); // 0x7E
		virtual __int64 rideJumped(void); // 0x7F
		virtual __int64 rideLanded(Vec3 const&, Vec3 const&); // 0x80
		virtual __int64 shouldRender(void); // 0x81
		virtual bool isInvulnerableTo(__int64 const&); // 0x82
		virtual __int64 getBlockDamageCause(Block const&); // 0x83
		virtual __int64 actuallyHurt(int, __int64 const&, bool); // 0x84
		virtual __int64 animateHurt(void); // 0x85
		virtual __int64 doFireHurt(int); // 0x86
		virtual __int64 onLightningHit(void); // 0x87
		virtual __int64 onBounceStarted(BlockPos const&, Block const&); // 0x88
		virtual __int64 feed(int); // 0x89
		virtual __int64 handleEntityEvent(__int64, int); // 0x8A
		virtual __int64 getPickRadius(void); // 0x8B
		virtual __int64 getActorRendererId(void); // 0x8C
		virtual __int64 spawnAtLocation(int, int); // 0x8D
		virtual __int64 spawnAtLocation(int, int, float); // 0x8E
		virtual __int64 spawnAtLocation(Block const&, int); // 0x8F
		virtual __int64 spawnAtLocation(Block const&, int, float); // 0x90
		virtual __int64 spawnAtLocation(class ItemStack const&, float); // 0x91
		virtual __int64 despawn(void); // 0x92
		virtual __int64 killed(Actor&); // 0x93
		virtual __int64 awardKillScore(Actor&, int); // 0x94
		virtual void setArmor(int, ItemStack const&); // 0x95
		virtual __int64 getArmor(int); // 0x96
		virtual __int64 getArmor__int64InSlot(int); // 0x97
		virtual __int64 getArmorMaterialTextureTypeInSlot(int); // 0x98
		virtual __int64 getArmorColorInSlot(int, int); // 0x99
		virtual __int64 getEquippedSlot(int); // 0x9A
		virtual void setEquippedSlot(int, ItemStack const&); // 0x9B
		virtual __int64 getCarriedItem(void); // 0x9C
		virtual void setCarriedItem(ItemStack const&); // 0x9D
		virtual void setOffhandSlot(ItemStack const&); // 0x9E
		virtual __int64 getEquippedTotem(void); // 0x9F
		virtual __int64 consumeTotem(void); // 0xA0
		virtual __int64 save(class CompoundTag&); // 0xA1
		virtual __int64 saveWithoutId(CompoundTag&); // 0xA2
		virtual __int64 load(CompoundTag const&, __int64&); // 0xA3
		virtual __int64 loadLinks(CompoundTag const&, std::vector<__int64>&, __int64&); // 0xA4
		virtual __int64 getEntityTypeId(void); // 0xA5
		virtual __int64 queryEntityRenderer(void); // 0xA6
		virtual __int64 getSourceUniqueID(void); // 0xA7
		virtual void setOnFire(int); // 0xA8
		virtual __int64 extinguishFire(void); // 0xA9
		virtual __int64 thawFreezeEffect(void); // 0xAA
		virtual __int64 canFreeze(void); // 0xAB
		virtual bool isWearingLeatherArmor(void); // 0xAC
		virtual __int64 getHandleWaterAABB(void); // 0xAD
		virtual __int64 handleInsidePortal(BlockPos const&); // 0xAE
		virtual __int64 getPortalCooldown(void); // 0xAF
		virtual __int64 getPortalWaitTime(void); // 0xB0
		virtual __int64 getDimensionId(void); // 0xB1
		virtual __int64 canChangeDimensions(void); // 0xB2
		virtual __int64 changeDimension(/*AutomaticID<struct Dimension, int>*/int, bool); // 0xB3
		virtual __int64 changeDimension(struct ChangeDimensionPacket const&); // 0xB4
		virtual __int64 getControllingPlayer(void); // 0xB5
		virtual __int64 checkFallDamage(float, bool); // 0xB6
		virtual __int64 causeFallDamage(float, float, __int64); // 0xB7
		virtual __int64 handleFallDistanceOnServer(float, float, bool); // 0xB8
		virtual __int64 playSynchronizedSound(struct LevelSoundEvent, Vec3 const&, Block const&, bool); // 0xB9
		virtual __int64 playSynchronizedSound(LevelSoundEvent, Vec3 const&, int, bool); // 0xBA
		virtual __int64 onSynchedDataUpdate(int); // 0xBB
		virtual __int64 canAddRider(Actor&); // 0xBC
		virtual __int64 canPickupItem(class ItemStack const&); // 0xBD
		virtual __int64 canBePulledIntoVehicle(void); // 0xBE
		virtual __int64 inCaravan(void); // 0xBF
		virtual bool isLeashableType(void); // 0xC0
		virtual __int64 tickLeash(void); // 0xC1
		virtual __int64 sendMotionPacketIfNeeded(void); // 0xC2
		virtual __int64 canSynchronizeNewEntity(void); // 0xC3
		virtual __int64 stopRiding(bool, bool, bool); // 0xC4
		virtual __int64 startSwimming(void); // 0xC5
		virtual __int64 stopSwimming(void); // 0xC6
		virtual __int64 buildDebugInfo(Text&); // 0xC7
		virtual __int64 getCommandPermissionLevel(void); // 0xC8
		virtual bool isClientSide(void); // 0xC9
		virtual __int64 getMutableAttribute(enum Attribute : int); // 0xCA
		virtual __int64 getAttribute(enum Attribute : int att); // 0xCB
		virtual __int64 getDeathTime(void); // 0xCC
		virtual __int64 heal(int); // 0xCD
		virtual bool isInvertedHealAndHarm(void); // 0xCE
		virtual __int64 canBeAffected(int); // 0xCF
		virtual __int64 canBeAffected(struct MobEffectInstance const&); // 0xD0
		virtual __int64 canBeAffectedByArrow(MobEffectInstance const&); // 0xD1
		virtual __int64 onEffectAdded(MobEffectInstance&); // 0xD2
		virtual __int64 onEffectUpdated(MobEffectInstance const&); // 0xD3
		virtual __int64 onEffectRemoved(MobEffectInstance&); // 0xD4
		virtual __int64 getAnimationComponent(void); // 0xD5
		virtual __int64 openContainerComponent(Player&); // 0xD6
		virtual __int64 swing(void); // 0xD7
		virtual __int64 useItem(class ItemStackBase&, enum ItemUseMethod : int, bool); // 0xD8
		virtual bool hasOutputSignal(unsigned char); // 0xD9
		virtual __int64 getOutputSignal(void); // 0xDA
		virtual __int64 getDebugText(std::vector<Text>&); // 0xDB
		virtual __int64 getMapDecorationRotation(void); // 0xDC
		virtual __int64 getRiderYRotation(Actor const&); // 0xDD
		virtual __int64 getYHeadRot(void); // 0xDE
		virtual bool isWorldBuilder(void); // 0xDF
		virtual bool isCreative(void); // 0xE0
		virtual bool isAdventure(void); // 0xE1
		virtual __int64 add(ItemStack&); // 0xE2
		virtual __int64 drop(ItemStack const&, bool); // 0xE3
		virtual __int64 getInteraction(Player&, struct ActorInteraction&, Vec3 const&); // 0xE4
		virtual __int64 canDestroyBlock(Block const&); // 0xE5
		virtual void setAuxValue(int); // 0xE6
		virtual void setSize(float, float); // 0xE7
		virtual __int64 getLifeSpan(void); // 0xE8
		virtual __int64 onOrphan(void); // 0xE9
		virtual __int64 wobble(void); // 0xEA
		virtual __int64 wasHurt(void); // 0xEB
		virtual __int64 startSpinAttack(void); // 0xEC
		virtual __int64 stopSpinAttack(void); // 0xED
		virtual void setDamageNearbyMobs(bool); // 0xEE
		virtual __int64 renderDebugServerState(class Options const&); // 0xEF
		virtual __int64 reloadLootTable(void); // 0xF0
		virtual __int64 reloadLootTable(struct EquipmentTableDefinition const&); // 0xF1
		virtual __int64 getLootTable(void); // 0xF2
		virtual __int64 getDefaultLootTable(void); // 0xF3
		virtual __int64 getDeletionDelayTimeSeconds(void); // 0xF4
		virtual __int64 kill(void); // 0xF5
		virtual __int64 die(__int64 const&); // 0xF6
		virtual __int64 shouldTick(void); // 0xF7
		virtual __int64 createMovementProxy(void); // 0xF8
		virtual __int64 getMovementProxy(void); // 0xF9
		virtual __int64 getNextStep(float); // 0xFA
		virtual __int64 updateEntitySpecificMolangVariables(struct RenderParams&); // 0xFB
		virtual __int64 shouldTryMakeStepSound(void); // 0xFC
		virtual __int64 canMakeStepSound(void); // 0xFD
		virtual __int64 outOfWorld(void); // 0xFE
		virtual __int64 _hurt(__int64 const&, int, bool, bool); // 0xFF
		virtual __int64 markHurt(void); // 0x100
		virtual __int64 _getAnimationComponent(std::shared_ptr<class AnimationComponent>&, class AnimationComponentGroup); // 0x101
		virtual __int64 readAdditionalSaveData(CompoundTag const&, __int64&); // 0x102
		virtual __int64 addAdditionalSaveData(CompoundTag&); // 0x103
		virtual __int64 _playStepSound(BlockPos const&, Block const&); // 0x104
		virtual __int64 _playFlySound(BlockPos const&, Block const&); // 0x105
		virtual __int64 _makeFlySound(void); // 0x106
		virtual __int64 checkInsideBlocks(float); // 0x107
		virtual __int64 pushOutOfBlocks(Vec3 const&); // 0x108
		virtual __int64 updateWaterState(void); // 0x109
		virtual __int64 doWaterSplashEffect(void); // 0x10A
		virtual __int64 spawnTrailBubbles(void); // 0x10B
		virtual __int64 updateInsideBlock(void); // 0x10C
		virtual __int64 _removeRider(__int64 const&, bool, bool, bool); // 0x10D
		virtual __int64 _onSizeUpdated(void); // 0x10E
		virtual __int64 _doAutoAttackOnTouch(Actor&); // 0x10F
	};
}