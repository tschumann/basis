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
/*

===== h_export.cpp ========================================================

  Entity classes exported by Halflife.

*/

#include "extdll.h"
#include "util.h"

#include "cbase.h"

// Holds engine functionality callbacks
enginefuncs_t g_engfuncs;
globalvars_t  *gpGlobals;

#undef DLLEXPORT
#ifdef _WIN32
#define DLLEXPORT __stdcall
#else
#define DLLEXPORT __attribute__ ((visibility("default")))
#endif

#ifdef _WIN32

// Required DLL entry point
BOOL WINAPI DllMain(
   HINSTANCE hinstDLL,
   DWORD fdwReason,
   LPVOID lpvReserved)
{
	if      (fdwReason == DLL_PROCESS_ATTACH)
    {
    }
	else if (fdwReason == DLL_PROCESS_DETACH)
    {
    }
	return TRUE;
}
#endif

extern "C" void DLLEXPORT GiveFnptrsToDll(	enginefuncs_t* pengfuncsFromEngine, globalvars_t *pGlobals )
{
	memcpy(&g_engfuncs, pengfuncsFromEngine, sizeof(enginefuncs_t));
	gpGlobals = pGlobals;
}


extern "C" void DLLEXPORT SV_SaveGameComment( char *pBuffer, int maxLength )
{
	if( !strncmp( STRING( gpGlobals->mapname ), "t0a0", strlen( "t0a0" ) ) ) // a, b, b1, b2, c, d
	{
		strncpy( pBuffer, "HAZARD COURSE", maxLength );
	}
	else if( !strncmp( STRING( gpGlobals->mapname ), "c0a0", strlen( "c0a0" ) ) ) // a, b, c, d, e
	{
		strncpy( pBuffer, "BLACK MESA INBOUND", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a0" ) )
	{
		strncpy( pBuffer, "ANOMOLOUS MATERIALS", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a0a" ) )
	{
		strncpy( pBuffer, "ANOMOLOUS MATERIALS", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a0b" ) )
	{
		strncpy( pBuffer, "ANOMOLOUS MATERIALS", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a0c" ) )
	{
		strncpy( pBuffer, "UNFORSEEN CONSEQUENCES", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a0d" ) )
	{
		strncpy( pBuffer, "UNFORSEEN CONSEQUENCES", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a0e" ) )
	{
		strncpy( pBuffer, "UNFORSEEN CONSEQUENCES", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a1" ) )
	{
		strncpy( pBuffer, "UNFORSEEN CONSEQUENCES", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a1a" ) )
	{
		strncpy( pBuffer, "UNFORSEEN CONSEQUENCES", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a1b" ) )
	{
		strncpy( pBuffer, "UNFORSEEN CONSEQUENCES", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a1c" ) )
	{
		strncpy( pBuffer, "UNFORSEEN CONSEQUENCES", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a1d" ) )
	{
		strncpy( pBuffer, "UNFORSEEN CONSEQUENCES", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a1f" ) )
	{
		strncpy( pBuffer, "UNFORSEEN CONSEQUENCES", maxLength );
	}
	else if( !strncmp( STRING( gpGlobals->mapname ), "c1a2", strlen( "c1a2" ) ) ) // a, b, c, d
	{
		strncpy( pBuffer, "OFFICE COMPLEX", maxLength );
	}
	else if( !strncmp( STRING( gpGlobals->mapname ), "c1a3", strlen( "c1a3" ) ) ) // a, b, c, d
	{
		strncpy( pBuffer, "\"WE'VE GOT HOSTILES\"", maxLength );
	}
	else if( !strncmp( STRING( gpGlobals->mapname ), "c1a4", strlen( "c1a4" ) ) ) // b, d, e, f, g, i, j, k
	{
		strncpy( pBuffer, "BLAST PIT", maxLength );
	}
	else if( !strncmp( STRING( gpGlobals->mapname ), "c2a1", strlen( "c2a1" ) ) ) // a, b
	{
		strncpy( pBuffer, "POWER UP", maxLength );
	}
	else if( !strncmp( STRING( gpGlobals->mapname ), "c2a2" , strlen( "c2a2" ) ) ) // a, b1, b2, c, d, e, f, g, h
	{
		strncpy( pBuffer, "ON A RAIL", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a3" ) )
	{
		strncpy( pBuffer, "APPREHENSION", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a3a" ) )
	{
		strncpy( pBuffer, "APPREHENSION", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a3b" ) )
	{
		strncpy( pBuffer, "APPREHENSION", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a3c" ) )
	{
		strncpy( pBuffer, "APPREHENSION", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a3d" ) )
	{
		strncpy( pBuffer, "APPREHENSION", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a3e" ) )
	{
		strncpy( pBuffer, "APPREHENSION", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a4" ) )
	{
		strncpy( pBuffer, "RESIDUE PROCESSING", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a4a" ) )
	{
		strncpy( pBuffer, "RESIDUE PROCESSING", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a4b" ) )
	{
		strncpy( pBuffer, "RESIDUE PROCESSING", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a4c" ) )
	{
		strncpy( pBuffer, "RESIDUE PROCESSING", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a4d" ) )
	{
		strncpy( pBuffer, "QUESTIONABLE ETHICS", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a4e" ) )
	{
		strncpy( pBuffer, "QUESTIONABLE ETHICS", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a4f" ) )
	{
		strncpy( pBuffer, "QUESTIONABLE ETHICS", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a4g" ) )
	{
		strncpy( pBuffer, "QUESTIONABLE ETHICS", maxLength );
	}
	else if( !strncmp( STRING( gpGlobals->mapname ), "c2a5", strlen( "c2a5" ) ) ) // a, b, c, d, e, f, g, w, x
	{
		strncpy( pBuffer, "SURFACE TENSION", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c3a1" ) )
	{
		strncpy( pBuffer, "\"FORGET ABOUT FREEMAN\"", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c3a1a" ) )
	{
		strncpy( pBuffer, "\"FORGET ABOUT FREEMAN\"", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c3a1b" ) )
	{
		strncpy( pBuffer, "\"FORGET ABOUT FREEMAN\"", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c3a2" ) )
	{
		strncpy( pBuffer, "\"FORGET ABOUT FREEMAN\"", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c3a2a" ) )
	{
		strncpy( pBuffer, "\"FORGET ABOUT FREEMAN\"", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c3a2b" ) )
	{
		strncpy( pBuffer, "\"FORGET ABOUT FREEMAN\"", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c3a2c" ) )
	{
		strncpy( pBuffer, "\"FORGET ABOUT FREEMAN\"", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c3a2d" ) )
	{
		strncpy( pBuffer, "\"FORGET ABOUT FREEMAN\"", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c3a2e" ) )
	{
		strncpy( pBuffer, "LAMBDA CORE", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c3a2f" ) )
	{
		strncpy( pBuffer, "LAMBDA CORE", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c4a1" ) )
	{
		strncpy( pBuffer, "XEN", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c4a1a" ) )
	{
		strncpy( pBuffer, "INTERLOPER", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c4a1b" ) )
	{
		strncpy( pBuffer, "INTERLOPER", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c4a1c" ) )
	{
		strncpy( pBuffer, "INTERLOPER", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c4a1d" ) )
	{
		strncpy( pBuffer, "INTERLOPER", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c4a1e" ) )
	{
		strncpy( pBuffer, "INTERLOPER", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c4a1f" ) )
	{
		strncpy( pBuffer, "INTERLOPER", maxLength );
	}
	else if( !strncmp( STRING( gpGlobals->mapname ), "c4a2", strlen( "c4a2" ) ) ) // a, b
	{
		strncpy( pBuffer, "GONARCH'S LAIR", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c4a3" ) )
	{
		strncpy( pBuffer, "NIHILANTH", maxLength );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c5a1" ) )
	{
		strncpy( pBuffer, "NIHILANTH", maxLength );
	}
	else
	{
		strncpy( pBuffer, STRING( gpGlobals->mapname ), maxLength );
	}
}
