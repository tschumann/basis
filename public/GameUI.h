#ifndef GAMEUI_H
#define GAMEUI_H

#include "interface.h"

#ifdef _WIN32
#define GAMEUI_DLLNAME "cl_dlls/GameUI.dll"
#elif defined(OSX)
#define GAMEUI_DLLNAME "cl_dlls/gameui.dylib"
#elif defined(LINUX)
#define GAMEUI_DLLNAME "cl_dlls/gameui.so"
#else
#error
#endif

#endif //GAMEUI_H
