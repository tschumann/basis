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


extern "C" void DLLEXPORT SV_SaveGameComment( char *buffer, int max_length )
{
	if( !strncmp( STRING( gpGlobals->mapname ), "t0a0", strlen( "t0a0" ) ) ) // a, b, b1, b2, c, d
	{
		strncpy( buffer, "HAZARD COURSE", max_length );
	}
	else if( !strncmp( STRING( gpGlobals->mapname ), "c0a0", strlen( "c0a0" ) ) ) // a, b, c, d, e
	{
		strncpy( buffer, "BLACK MESA INBOUND", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a0" ) )
	{
		strncpy( buffer, "ANOMOLOUS MATERIALS", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a0a" ) )
	{
		strncpy( buffer, "ANOMOLOUS MATERIALS", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a0b" ) )
	{
		strncpy( buffer, "ANOMOLOUS MATERIALS", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a0c" ) )
	{
		strncpy( buffer, "UNFORSEEN CONSEQUENCES", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a0d" ) )
	{
		strncpy( buffer, "UNFORSEEN CONSEQUENCES", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a0e" ) )
	{
		strncpy( buffer, "UNFORSEEN CONSEQUENCES", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a1" ) )
	{
		strncpy( buffer, "UNFORSEEN CONSEQUENCES", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a1a" ) )
	{
		strncpy( buffer, "UNFORSEEN CONSEQUENCES", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a1b" ) )
	{
		strncpy( buffer, "UNFORSEEN CONSEQUENCES", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a1c" ) )
	{
		strncpy( buffer, "UNFORSEEN CONSEQUENCES", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a1d" ) )
	{
		strncpy( buffer, "UNFORSEEN CONSEQUENCES", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a1f" ) )
	{
		strncpy( buffer, "UNFORSEEN CONSEQUENCES", max_length );
	}
	else if( !strncmp( STRING( gpGlobals->mapname ), "c1a2", strlen( "c1a2" ) ) ) // a, b, c, d
	{
		strncpy( buffer, "OFFICE COMPLEX", max_length );
	}
	else if( !strncmp( STRING( gpGlobals->mapname ), "c1a3", strlen( "c1a3" ) ) ) // a, b, c, d
	{
		strncpy( buffer, "\"WE'VE GOT HOSTILES\"", max_length );
	}
	else if( !strncmp( STRING( gpGlobals->mapname ), "c1a4", strlen( "c1a4" ) ) ) // b, d, e, f, g, i, j, k
	{
		strncpy( buffer, "BLAST PIT", max_length );
	}
	else if( !strncmp( STRING( gpGlobals->mapname ), "c2a1", strlen( "c2a1" ) ) ) // a, b
	{
		strncpy( buffer, "POWER UP", max_length );
	}
	else if( !strncmp( STRING( gpGlobals->mapname ), "c2a2" , strlen( "c2a2" ) ) ) // a, b1, b2, c, d, e, f, g, h
	{
		strncpy( buffer, "ON A RAIL", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a3" ) )
	{
		strncpy( buffer, "APPREHENSION", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a3a" ) )
	{
		strncpy( buffer, "APPREHENSION", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a3b" ) )
	{
		strncpy( buffer, "APPREHENSION", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a3c" ) )
	{
		strncpy( buffer, "APPREHENSION", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a3d" ) )
	{
		strncpy( buffer, "APPREHENSION", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a3e" ) )
	{
		strncpy( buffer, "APPREHENSION", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a4" ) )
	{
		strncpy( buffer, "RESIDUE PROCESSING", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a4a" ) )
	{
		strncpy( buffer, "RESIDUE PROCESSING", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a4b" ) )
	{
		strncpy( buffer, "RESIDUE PROCESSING", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a4c" ) )
	{
		strncpy( buffer, "RESIDUE PROCESSING", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a4d" ) )
	{
		strncpy( buffer, "QUESTIONABLE ETHICS", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a4e" ) )
	{
		strncpy( buffer, "QUESTIONABLE ETHICS", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a4f" ) )
	{
		strncpy( buffer, "QUESTIONABLE ETHICS", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a4g" ) )
	{
		strncpy( buffer, "QUESTIONABLE ETHICS", max_length );
	}
	else if( !strncmp( STRING( gpGlobals->mapname ), "c2a5", strlen( "c2a5" ) ) ) // a, b, c, d, e, f, g, w, x
	{
		strncpy( buffer, "SURFACE TENSION", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c3a1" ) )
	{
		strncpy( buffer, "\"FORGET ABOUT FREEMAN\"", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c3a1a" ) )
	{
		strncpy( buffer, "\"FORGET ABOUT FREEMAN\"", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c3a1b" ) )
	{
		strncpy( buffer, "\"FORGET ABOUT FREEMAN\"", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c3a2" ) )
	{
		strncpy( buffer, "\"FORGET ABOUT FREEMAN\"", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c3a2a" ) )
	{
		strncpy( buffer, "\"FORGET ABOUT FREEMAN\"", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c3a2b" ) )
	{
		strncpy( buffer, "\"FORGET ABOUT FREEMAN\"", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c3a2c" ) )
	{
		strncpy( buffer, "\"FORGET ABOUT FREEMAN\"", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c3a2d" ) )
	{
		strncpy( buffer, "\"FORGET ABOUT FREEMAN\"", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c3a2e" ) )
	{
		strncpy( buffer, "LAMBDA CORE", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c3a2f" ) )
	{
		strncpy( buffer, "LAMBDA CORE", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c4a1" ) )
	{
		strncpy( buffer, "XEN", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c4a1a" ) )
	{
		strncpy( buffer, "INTERLOPER", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c4a1b" ) )
	{
		strncpy( buffer, "INTERLOPER", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c4a1c" ) )
	{
		strncpy( buffer, "INTERLOPER", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c4a1d" ) )
	{
		strncpy( buffer, "INTERLOPER", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c4a1e" ) )
	{
		strncpy( buffer, "INTERLOPER", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c4a1f" ) )
	{
		strncpy( buffer, "INTERLOPER", max_length );
	}
	else if( !strncmp( STRING( gpGlobals->mapname ), "c4a2", strlen( "c4a2" ) ) ) // a, b
	{
		strncpy( buffer, "GONARCH'S LAIR", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c4a3" ) )
	{
		strncpy( buffer, "NIHILANTH", max_length );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c5a1" ) )
	{
		strncpy( buffer, "NIHILANTH", max_length );
	}
	else
	{
		strncpy( buffer, STRING( gpGlobals->mapname ), max_length );
	}
}
