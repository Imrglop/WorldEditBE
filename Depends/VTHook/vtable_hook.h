// github.com/Imrglop/SignatureScanner

#pragma once
#include <cstdint>
#include <Windows.h>
#include <string>

namespace vh {
	int hook(LPVOID* pfpTarget, LPVOID pDetour, LPVOID* pOriginal = NULL);
	int unhook(LPVOID* pfpTarget);
	std::string statusToString(int status);
}