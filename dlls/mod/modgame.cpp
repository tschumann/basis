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
#include "extdll.h"
#include "eiface.h"
#include "util.h"
#include "game.h"
#include "mod/modgame.h"
#include "interface.h"

HINTERFACEMODULE hFileSystemModule = NULL;
#include "FileSystem.h"
IFileSystem *g_pFileSystem = NULL;

void LoadFileSystem( void )
{
	hFileSystemModule = Sys_LoadModule( FILESYSTEM_DLLNAME );
	CreateInterfaceFn fileSystemFactory = Sys_GetFactory( hFileSystemModule );

	if( fileSystemFactory == NULL )
	{
		g_pFileSystem = NULL;
	}

	g_pFileSystem = (IFileSystem *)fileSystemFactory( FILESYSTEM_INTERFACE_VERSION, NULL );

	if( g_pFileSystem )
	{
		ALERT( at_aiconsole, "%s interface instantiated.\n", FILESYSTEM_INTERFACE_VERSION );
	}
}

cvar_t	coop		= {"mp_coop","0", FCVAR_SERVER };
cvar_t	physics		= {"sv_physics", "0"};

// Construction Worker
cvar_t	sk_construction_health1 = {"sk_construction_health1","0"};
cvar_t	sk_construction_health2 = {"sk_construction_health2","0"};
cvar_t	sk_construction_health3 = {"sk_construction_health3","0"};

void ModDLLInit( void )
{
	CVAR_REGISTER ( &coop );
	CVAR_REGISTER ( &physics );

	CVAR_REGISTER ( &sk_construction_health1 );
	CVAR_REGISTER ( &sk_construction_health2 );
	CVAR_REGISTER ( &sk_construction_health3 );

	LoadFileSystem();

	// make sure the mod_addons directory is loaded, but do it before doing
	// any other filesystem operations because it reinitialises the
	// filesystem - see https://github.com/ValveSoftware/halflife/issues/951
	// SERVER_COMMAND("_setaddons_folder 1");

	if( g_pFileSystem )
	{
		ALERT( at_console, "Adding search path\n" );
		g_pFileSystem->AddSearchPath("gearbox", "GAME");
	}
}

void Mod_Precache( void )
{
	PRECACHE_MODEL("models/null.mdl");
}