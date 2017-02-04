/***
*
*	Copyright (c) 1996-2002, Valve LLC. All rights reserved.
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
//
// mod_util.cpp
//
// implementation of class-less helper functions
//

// #include "wrect.h"
// #include "cl_dll.h"
#include "hud.h"
#include "cl_util.h"

#include <stdarg.h>

#ifdef _WIN32
#define FILESYSTEM_DLLNAME "../FileSystem_Steam.dll"
#elif defined(OSX)
#define FILESYSTEM_DLLNAME "../FileSystem_Steam.dylib"
#elif defined(__linux__)
#define FILESYSTEM_DLLNAME "../FileSystem_Steam.so"
#else
#error
#endif

#include "GameUI.h"
CSysModule *g_hFilesystemModule = NULL;
CSysModule *g_hGameUIModule = NULL;
#include "Filesystem.h"
IFileSystem *g_pFilesystem = NULL;
#include "IGameConsole.h"
IGameConsole *g_pGameConsole = NULL;
#include "IMusicManager.h"
IMusicManager *g_pMusicManager = NULL;

#include "VGUI2.h"
CSysModule *g_hVGUI2Module = NULL;

void ConsolePrintf( const char *format, ... )
{
	char string[1024];

	va_list args;
	va_start(args, format);
	vsprintf(string, format, args);
	va_end(args);

	if( g_pGameConsole )
	{
		g_pGameConsole->Printf( string );
	}
	else
	{
		gEngfuncs.Con_Printf( string );
	}
}

void ConsoleDPrintf( const char *format, ... )
{
	char string[1024];

	va_list args;
	va_start(args, format);
	vsprintf(string, format, args);
	va_end(args);

	if( g_pGameConsole )
	{
		g_pGameConsole->DPrintf( string );
	}
	else
	{
		gEngfuncs.Con_DPrintf( string );
	}
}

void CL_UnloadFileSystem( void )
{
	Sys_UnloadModule( g_hFilesystemModule );

	g_hFilesystemModule = NULL;
}

void CL_LoadFileSystem( void )
{
	char szPDir[512];

	if ( gEngfuncs.COM_ExpandFilename( FILESYSTEM_DLLNAME, szPDir, sizeof( szPDir ) ) == FALSE )
	{
		ConsoleDPrintf( "Unable to load %s\n", FILESYSTEM_DLLNAME );
		g_hFilesystemModule = NULL;
		return;
	}

	g_hFilesystemModule = Sys_LoadModule( szPDir );
	CreateInterfaceFn filesystemFactory = Sys_GetFactory( g_hFilesystemModule );

	if ( g_hFilesystemModule == NULL )
	{
		ConsoleDPrintf( "Unable to get factory from %s\n", g_hFilesystemModule );
		g_hFilesystemModule = NULL;
		return;
	}

	g_pFilesystem = (IFileSystem *)filesystemFactory( FILESYSTEM_INTERFACE_VERSION, NULL);

	if ( g_pFilesystem )
	{
		ConsoleDPrintf( "%s interface instantiated\n", FILESYSTEM_INTERFACE_VERSION );
		g_pFilesystem->AddSearchPath("gearbox", "GAME");
	}
}

void CL_UnloadGameUI( void )
{
	Sys_UnloadModule( g_hGameUIModule );

	g_hGameUIModule = NULL;
}

void CL_LoadGameUI( void )
{
	char szPDir[512];

	if ( gEngfuncs.COM_ExpandFilename( GAMEUI_DLLNAME, szPDir, sizeof( szPDir ) ) == FALSE )
	{
		ConsoleDPrintf( "Unable to load %s\n", GAMEUI_DLLNAME );
		g_pGameConsole = NULL;
		g_hGameUIModule = NULL;
		return;
	}

	g_hGameUIModule = Sys_LoadModule( szPDir );
	CreateInterfaceFn gameUIFactory = Sys_GetFactory( g_hGameUIModule );

	if ( gameUIFactory == NULL )
	{
		ConsoleDPrintf( "Unable to get factory from %s\n", GAMEUI_DLLNAME );
		g_pGameConsole = NULL;
		g_hGameUIModule = NULL;
		return;
	}

	g_pGameConsole = (IGameConsole *)gameUIFactory( GAMECONSOLE_INTERFACE_VERSION, NULL);

	if ( g_pGameConsole )
	{
		ConsoleDPrintf( "%s interface instantiated\n", GAMECONSOLE_INTERFACE_VERSION );
	}

	g_pMusicManager = (IMusicManager *)gameUIFactory( MUSICMANAGER_INTERFACE_VERSION, NULL);

	if ( g_pMusicManager )
	{
		ConsoleDPrintf( "%s interface instantiated\n", MUSICMANAGER_INTERFACE_VERSION );
	}
}

void CL_UnloadVGUI2( void )
{
	Sys_UnloadModule( g_hVGUI2Module );

	g_hVGUI2Module = NULL;
}

void CL_LoadVGUI2( void )
{
	char szPDir[512];

	if ( gEngfuncs.COM_ExpandFilename( VGUI2_DLLNAME, szPDir, sizeof( szPDir ) ) == FALSE )
	{
		ConsoleDPrintf( "Unable to load %s\n", VGUI2_DLLNAME );
		g_hVGUI2Module = NULL;
		return;
	}

	g_hVGUI2Module = Sys_LoadModule( szPDir );
	CreateInterfaceFn vgui2Factory = Sys_GetFactory( g_hVGUI2Module );

	if ( vgui2Factory == NULL )
	{
		ConsoleDPrintf( "Unable to get factory from %s\n", VGUI2_DLLNAME );
		g_hVGUI2Module = NULL;
		return;
	}
}