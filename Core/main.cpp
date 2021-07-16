#include "main.h"
#include <windows.h>
#include <iostream>
#include "../WorldEdit/WorldEdit.h"
#include "../Utils/Game.h"
#include "../File/FileStorage.h"
#include "Logger.h"

CommandManager* c_CommandMgr;

FileStorage* fileStorage;

bool isEjecting = false;

void main::eject()
{
    isEjecting = true;
}

FileStorage* main::getFileStorage() {
    return fileStorage; 
}

WorldEdit* worldEdit = nullptr;
HMODULE _hModule = 0;

FILE* consoleOut;

void initConsole() {
#ifdef CONSOLE
    AllocConsole();
    freopen_s(&consoleOut, "CONOUT$", "w", stdout);
#endif
}

void exitWorldEdit(bool freeLib = true) {
    worldEdit->disable();
    delete worldEdit;
    MH_Uninitialize();
    clientMessage("Uninjected!");
    if (consoleOut != NULL) {
        fclose(consoleOut);
    }
#ifdef CONSOLE
    FreeConsole();
#endif
    if (freeLib) FreeLibrary(_hModule);
}

DWORD __stdcall init(void* lpParam) {
    HMODULE* pModule = reinterpret_cast<HMODULE*>(lpParam);
#if defined(CONSOLE)
    initConsole();
    logL("Test");
    SetConsoleTitle(TEXT("World Edit - Debug Console"));
#endif
    Logger::init();
    logF("Initializing!");
    // -------------- INIT CLASS --------------
    MH_Initialize();
    // -------------- INIT FILE STORAGE --------------
#pragma warning(suppress : 4996)
    const char* szAppDataPath = getenv("LOCALAPPDATA");
    std::string strAppDataPath(szAppDataPath);
    fileStorage = new FileStorage(strAppDataPath);
    fileStorage->init();
    // -------------- INIT WORLD EDIT --------------
    worldEdit = new WorldEdit();
    c_CommandMgr = new CommandManager();
    c_CommandMgr->init();
    if (worldEdit->enable()) {
        logFC(0xA, "Enabled WorldEditBE.");
        MH_EnableHook(MH_ALL_HOOKS);
    }
    else {
        logFC(0xC, "Could not enable WorldEditBE!");
    }
    // -------------- INIT LOOP --------------
    logF("Started loop.");
    while (!isEjecting) {
        Sleep(100);
    }
    Sleep(200);
    exitWorldEdit(false);
    FreeLibraryAndExitThread(_hModule, 0);
    return EXIT_SUCCESS;
}

int __stdcall DllMain(HMODULE hModule, DWORD ulCallReason)
{
    if (ulCallReason == DLL_PROCESS_ATTACH) {
        CreateThread(nullptr, NULL, init, reinterpret_cast<void*>(&hModule), NULL, nullptr);
        _hModule = hModule;
    }
    else if (ulCallReason == DLL_PROCESS_DETACH) {
//#if defined(_DEBUG)
//        exitWorldEdit();
//#endif

    }
    return 1;
}

FileStorage* getFS() {
    return fileStorage;
}
