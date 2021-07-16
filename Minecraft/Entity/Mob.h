#pragma once
#include "Actor.h"
#include "../Inventory/Item.h"

namespace Minecraft {
	class Mob : public Actor {
	public:
		virtual __int64 knockback(Actor*, int, float, float, float, float, float); // 0x110
		virtual __int64 resolveDeathLoot(int, __int64 const&); // 0x111
		virtual __int64 spawnAnim(void); // 0x112
		virtual __int64 setSleeping(bool); // 0x113
		virtual __int64 setSprinting(bool); // 0x114
		virtual __int64 playAmbientSound(void); // 0x115
		virtual __int64 getAmbientSound(void); // 0x116
		virtual __int64 getHurtSound(void); // 0x117
		virtual __int64 getDeathSound(void); // 0x118
		virtual __int64 getAmbientSoundPostponeTicks(void); // 0x119
		virtual __int64 getAmbientSoundPostponeTicksRange(void); // 0x11A
		virtual __int64 getItemInHandIcon(ItemStack const&, int); // 0x11B
		virtual __int64 getSpeed(void); // 0x11C
		virtual __int64 setSpeed(float); // 0x11D
		virtual __int64 getJumpPower(void); // 0x11E
		virtual __int64 hurtEffects(__int64 const&, int, bool, bool); // 0x11F
		virtual __int64 getMeleeWeaponDamageBonus(Mob*); // 0x120
		virtual __int64 getMeleeKnockbackBonus(void); // 0x121
		virtual __int64 travel(float, float, float); // 0x122
		virtual __int64 travel(__int64&, float, float, float); // 0x123
		virtual __int64 applyFinalFriction(float, bool); // 0x124
		virtual __int64 updateWalkAnim(void); // 0x125
		virtual __int64 aiStep(void); // 0x126
		virtual __int64 aiStep(__int64&); // 0x127
		virtual __int64 pushActors(void); // 0x128
		virtual __int64 lookAt(Actor*, float, float); // 0x129
		virtual __int64 isLookingAtAnEntity(void); // 0x12A
		virtual __int64 checkSpawnRules(bool); // 0x12B
		virtual __int64 checkSpawnObstruction(void); // 0x12C
		virtual __int64 getAttackAnim(float); // 0x12D
		virtual __int64 getItemUseDuration(void); // 0x12E
		virtual __int64 getItemUseStartupProgress(void); // 0x12F
		virtual __int64 getItemUseIntervalProgress(void); // 0x130
		virtual __int64 getItemuseIntervalAxis(void); // 0x131
		virtual __int64 getTimeAlongSwing(void); // 0x132
		virtual __int64 ate(void); // 0x133
		virtual __int64 getMaxHeadXRot(void); // 0x134
		virtual __int64 getLastHurtByMob(void); // 0x135
		virtual __int64 setLastHurtByMob(Mob*); // 0x136
		virtual __int64 getLastHurtByPlayer(void); // 0x137
		virtual __int64 setLastHurtByPlayer(Player*); // 0x138
		virtual __int64 getLastHurtMob(void); // 0x139
		virtual __int64 setLastHurtMob(Actor*); // 0x13A
		virtual __int64 isAlliedTo(Mob*); // 0x13B
		virtual __int64 doHurtTarget(Actor*, __int64 const&); // 0x13C
		virtual __int64 canBeControlledByRider(void); // 0x13D
		virtual __int64 leaveCaravan(void); // 0x13E
		virtual __int64 joinCaravan(Mob*); // 0x13F
		virtual __int64 hasCaravanTail(void); // 0x140
		virtual __int64 getCaravanHead(void); // 0x141
		virtual __int64 getArmorValue(void); // 0x142
		virtual __int64 getArmorCoverPercentage(void); // 0x143
		virtual __int64 hurtArmor(__int64 const&, int); // 0x144
		virtual __int64 hurtArmor(__int64 const&, int, __int64); // 0x145
		virtual __int64 hurtArmorSlot(__int64 const&, int, enum ArmorSlot : int); // 0x146
		virtual __int64 setDamagedArmor(enum ArmorSlot : int, ItemStack const&); // 0x147
		virtual __int64 sendArmorDamage(__int64); // 0x148
		virtual __int64 sendArmor(__int64); // 0x149
		virtual __int64 containerChanged(int); // 0x14A
		virtual __int64 updateEquipment(void); // 0x14B
		virtual __int64 clearEquipment(void); // 0x14C
		virtual __int64 getAllArmor(void); // 0x14D
		virtual __int64 getAllArmorID(void); // 0x14E
		virtual __int64 getAllHand(void); // 0x14F
		virtual __int64 getAllEquipment(void); // 0x150
		virtual __int64 getArmorTypeHash(void); // 0x151
		virtual __int64 dropEquipmentOnDeath(__int64 const&, int); // 0x152
		virtual __int64 dropEquipmentOnDeath(void); // 0x153
		virtual __int64 clearVanishEnchantedItemsOnDeath(void); // 0x154
		virtual __int64 sendInventory(bool); // 0x155
		virtual __int64 getDamageAfterMagicAbsorb(__int64 const&, int); // 0x156
		virtual __int64 createAIGoals(void); // 0x157
		virtual __int64 onBorn(Actor&, Actor&); // 0x158
		virtual __int64 setItemSlot(enum EquipmentSlot : int, ItemStack const&); // 0x159
		virtual __int64 setTransitioningSitting(bool); // 0x15A
		virtual __int64 attackAnimation(Actor*, float); // 0x15B
		virtual __int64 getAttackTime(void); // 0x15C
		virtual __int64 _getWalkTargetValue(BlockPos const&); // 0x15D
		virtual __int64 canExistWhenDisallowMob(void); // 0x15E
		virtual __int64 useNewAi(void); // 0x15F
		virtual __int64 ascendLadder(void); // 0x160
		virtual __int64 ascendBlockByJumping(void); // 0x161
		virtual __int64 descendBlockByCrouching(void); // 0x162
		virtual __int64 dropContainer(void); // 0x163
		virtual __int64 initBodyControl(void); // 0x164
		virtual __int64 jumpFromGround(void); // 0x165
		virtual __int64 jumpFromGround(__int64&); // 0x166
		virtual __int64 updateAi(void); // 0x167
		virtual __int64 newServerAiStep(void); // 0x168
		virtual __int64 _serverAiMobStep(void); // 0x169
		virtual __int64 getDamageAfterEnchantReduction(__int64 const&, int); // 0x16A
		virtual __int64 getDamageAfterArmorAbsorb(__int64 const&, int); // 0x16B
		virtual __int64 dropBags(void); // 0x16C
		virtual __int64 tickDeath(void); // 0x16D
		virtual __int64 updateGliding(void); // 0x16E
		virtual __int64 _allowAscendingScaffolding(void); // 0x16F
	};
}