#pragma once
#include <cstdint>
#include <chrono>

namespace Utils {
	uintptr_t InstructionToAddress(void* addy, size_t lenOperation = 3, size_t size = sizeof(int));
	void CalcMinMax(int& minX, int& minY, int& minZ, int& maxX, int& maxY, int& maxZ);
}

template<typename RET, typename... ARGS>
RET callVirtual(int off, void* _this, ARGS... args) {
    using FUNC = RET(__fastcall*)(void*, ARGS...);
    FUNC* vtable = *reinterpret_cast<FUNC**>(_this);
    return vtable[off](_this, args...);
}

// kinda bad random method but oks
inline size_t _rand() {
    static size_t seed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
    seed = (1103515245 * seed + 12345) % (int)std::pow(2, 31);
    return seed;
}