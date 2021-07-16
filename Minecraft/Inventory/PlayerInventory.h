#pragma once
#include "../Block/BlockPos.h"
#include "../Block/BlockSource.h"
#include "ItemStack.h"
#include "../../Utils/Utils.h"

namespace Minecraft {
	class Container { /*copied from bedrock server, not perfect*/
	public:
		// EatVtable.js (in.txt -> out.txt)
		~Container();
		virtual void init(void); // 0x1
		virtual void nullsub_2(void); // 0x2
		virtual void addContentChangeListener(class ContainerContentChangeListener*); // 0x3
		virtual void removeContentChangeListener(ContainerContentChangeListener*); // 0x4
		virtual /*const */class ItemStack* _getItem(int); // 0x5
		ItemStack* getItem(int slot) {
			return callVirtual<ItemStack*, int>(0x5, this, slot);
		}
		virtual bool hasRoomForItem(ItemStack const&); // 0x6
		virtual void addItem(ItemStack&); // 0x7
		virtual char addItemToFirstEmptySlot(ItemStack&); // 0x8
		virtual __int64 setItem(int, ItemStack const&); // 0x9
		virtual void setItemWithForceBalance(int, ItemStack const&, bool); // 0xA
		virtual void removeItem(int, int); // 0xB
		virtual void removeAllItems(void); // 0xC
		virtual void dropContents(BlockSource&, Vec3 const&, bool); // 0xD
		virtual __int64 getContainerSize(void); // 0xE
		virtual long long getMaxStackSize(void); // 0xF
		virtual __int64 nullsub_7(void); // 0x10
		virtual __int64 nullsub_8(void); // 0x11
		virtual __int64 getSlotCopies(void); // 0x12
		virtual std::vector<const ItemStack*, std::allocator<const ItemStack*>> getSlots(void); // 0x13
		virtual __int64 getItemCount(ItemStack const&); // 0x14
		virtual __int64 findFirstSlotForItem(ItemStack const&); // 0x15
		// return true functions
		virtual bool nullsub_9(void); // 0x16
		virtual bool nullsub_10(void); // 0x17
		virtual void setContainerChanged(int); // 0x18
		virtual void setContainerMoved(void); // 0x19
		virtual void** setCustomName(std::string const&); // 0x1A
		virtual bool hasCustomName(void); // 0x1B
		virtual __int64 readAdditionalSaveData(CompoundTag const&); // 0x1C
		virtual __int64 addAdditionalSaveData(CompoundTag&); // 0x1D
		virtual __int64 createTransactionContext(std::function<void(Container&, int, ItemStack const&, ItemStack const&)>, std::function<void(void)>); // 0x1E
		virtual __int64 nullsub_11(void); // 0x1F
		virtual bool isEmpty(void); // 0x20
	};

	class Inventory : public Container {
	public:
	};

	class PlayerInventory {
	private:
		char pad_1[8];
	public:
		int selectedSlot;
		char pad[156];
		Inventory* inv;

	private:
		virtual void __cdecl checkLock(class CircuitSystem&, BlockPos const&);
	public:
		virtual void destructor(unsigned int);
		virtual void __cdecl createTransactionContext(class std_function, class std_function);
		virtual void __cdecl containerContentChanged(int);
	private:
		virtual void* vector_deleting_destructor(unsigned int);
	};
}