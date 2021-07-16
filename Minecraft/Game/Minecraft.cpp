#include "Minecraft.h"

Minecraft::Level* Minecraft::Minecraft::getLevel()
{
	/*
	mov     rax, [rcx+0B8h]
	test    rax, rax
	jz      short locret_140BA0111
	mov     rax, [rax+8]
	retn
	*/

	Level* result; // rax

	result = (Level*)*((unsigned __int64*)this + 23);
	if (result)
		result = (Level*)(result + 0x8);
	return result;
}