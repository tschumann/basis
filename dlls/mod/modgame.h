/***
*
*	Copyright (c) 1996-2001, Valve LLC. All rights reserved.
*	
*	This product contains software technology licensed from Id 
*	Software, Inc. ("Id Technology").  Id Technology (c) 1996 Id Software, Inc. 
*	All Rights Reserved.
*
*   Use, distribution, and modification of this source code and/or resulting
*   object code is restricted to non-commercial enhancements to products from
*   Valve LLC.  All other use, distribution, or modification is prohibited
*   without written permission from Valve LLC.
*
****/

#ifndef MODGAME_H
#define MODGAME_H

#ifdef _WIN32
#define FILESYSTEM_DLLNAME "FileSystem_Stdio.dll"
#elif defined(OSX)
#define FILESYSTEM_DLLNAME "FileSystem_Stdio.dylib"
#elif defined(__linux__)
#define FILESYSTEM_DLLNAME "filesystem_stdio.so"
#else
#error
#endif

#include "interface.h"
#include "FileSystem.h"

extern HINTERFACEMODULE hFileSystemModule;
extern IFileSystem *g_pFileSystem;

extern void ModDLLInit( void );

extern void Mod_Precache( void );

extern cvar_t	physics;
extern cvar_t	coop;
extern cvar_t	drawhitboxes;

extern DLL_GLOBAL	short	g_sModelIndexNull;// holds the index for the null model

#endif		// MODGAME_H
