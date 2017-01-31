//========= Copyright © 1996-2002, Valve LLC, All rights reserved. ============
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================

#include "modfilesystem.h"
#ifndef CLIENT_DLL
#include "extdll.h"
#include "eiface.h"
#include "enginecallback.h"
#endif

HINTERFACEMODULE hFileSystemModule = NULL;
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
#ifndef CLIENT_DLL
		ALERT( at_aiconsole, "%s interface instantiated.\n", FILESYSTEM_INTERFACE_VERSION );
#endif
	}
}