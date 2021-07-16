#include "ItemStack.h"
#include "../../WorldEdit/WorldEdit.h"

bool Minecraft::ItemStack::useOn(Actor* user, int x, int y, int z, byte side, float f1, float f2, float f3)
{
	using itemstack_useon_t = bool(__cdecl*)(ItemStack* _this, Actor* user, int x, int y, int z, byte side, float, float, float);
	static itemstack_useon_t oFunc = (itemstack_useon_t)FindSignature("40 53 55 56 57 48 83 ec ? 48 8b 41");
	return oFunc(this, user, x, y, z, side, f1, f2, f3);
}