//========= Copyright © 1996-2002, Valve LLC, All rights reserved. ============
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================

#ifndef MODFILESYSTEM_H
#define MODFILESYSTEM_H

#include <cstdlib>
#include "interface.h"
#include "FileSystem.h"

#ifdef _WIN32
#define FILESYSTEM_DLLNAME "FileSystem_Steam.dll"
#elif defined(OSX)
#define FILESYSTEM_DLLNAME "FileSystem_Steam.dylib"
#elif defined(__linux__)
#define FILESYSTEM_DLLNAME "FileSystem_Steam.so"
#else
#error
#endif

extern HINTERFACEMODULE hFileSystemModule;
extern IFileSystem *g_pFileSystem;

void LoadFileSystem( void );

#endif