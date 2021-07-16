#pragma once
#include "../shared.h"
#include "../Block/BlockLegacy.h"
#include "../NBT/CompoundTag.h"
namespace Minecraft {
	class Item;
	class ItemStack;
	class ItemDescriptor;

	class Item {
	public:
		Text texture_name;
	private:
		void* pad_000[5];
		Text __type; // "sword"
		void* pad_001[7];
	public:
		Text _id;
	private:
		void* pad_002;
	public:
		Text _namespace;
	private:
		void* pad_003[16];
	public:
		Text version;
		inline std::string getTypeID() {
			return this->_namespace.str() + ":" + this->_id.getText();
		}

	public:

		class BlockLegacy* getLegacyBlock() {
			return reinterpret_cast<BlockLegacy*>(reinterpret_cast<__int64>(this) + 0x198);
		}

		virtual ~Item();
	private:
		virtual void __cdecl initServer(class Json_Value&);
	public:
		virtual __int64 __cdecl getMaxUseDuration(void*);
		virtual __int64 __cdecl getMaxUseDuration(ItemStack const*);
	};
}