#include "Utils.h"

void swapValues(int& v1, int& v2) {
	int temp1 = v1;
	int temp2 = v2;

	v1 = temp2;
	v2 = temp1;
}

uintptr_t Utils::InstructionToAddress(void* addy, size_t lenOperation, size_t size)
{
	if (addy == nullptr) return NULL;
	uintptr_t out = (uintptr_t)addy;
	int offset = *reinterpret_cast<int*>(out + lenOperation);
	out += offset + (static_cast<unsigned long long>(lenOperation) + size);
	return out;
}

void Utils::CalcMinMax(int& minX, int& minY, int& minZ, int& maxX, int& maxY, int& maxZ)
{
	if (minX > maxX) swapValues(minX, maxX);
	if (minY > maxY) swapValues(minY, maxY);
	if (minZ > maxZ) swapValues(minZ, maxZ);
}
