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


extern "C" void __declspec( dllexport ) SV_SaveGameComment( char *buffer, int max_length )
{
	if( !strcmp( STRING( gpGlobals->mapname ), "t0a0" ) )
	{
		strcpy( buffer, "HAZARD COURSE" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "t0a0a" ) )
	{
		strcpy( buffer, "HAZARD COURSE" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "t0a0b" ) )
	{
		strcpy( buffer, "HAZARD COURSE" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "t0a0b1" ) )
	{
		strcpy( buffer, "HAZARD COURSE" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "t0a0b2" ) )
	{
		strcpy( buffer, "HAZARD COURSE" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "t0a0c" ) )
	{
		strcpy( buffer, "HAZARD COURSE" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "t0a0d" ) )
	{
		strcpy( buffer, "HAZARD COURSE" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c0a0" ) )
	{
		strcpy( buffer, "BLACK MESA INBOUND" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c0a0a" ) )
	{
		strcpy( buffer, "BLACK MESA INBOUND" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c0a0b" ) )
	{
		strcpy( buffer, "BLACK MESA INBOUND" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c0a0c" ) )
	{
		strcpy( buffer, "BLACK MESA INBOUND" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c0a0d" ) )
	{
		strcpy( buffer, "BLACK MESA INBOUND" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c0a0e" ) )
	{
		strcpy( buffer, "BLACK MESA INBOUND" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a0" ) )
	{
		strcpy( buffer, "ANOMOLOUS MATERIALS" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a0a" ) )
	{
		strcpy( buffer, "ANOMOLOUS MATERIALS" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a0b" ) )
	{
		strcpy( buffer, "ANOMOLOUS MATERIALS" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a0c" ) )
	{
		strcpy( buffer, "UNFORSEEN CONSEQUENCES" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a0d" ) )
	{
		strcpy( buffer, "UNFORSEEN CONSEQUENCES" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a0e" ) )
	{
		strcpy( buffer, "UNFORSEEN CONSEQUENCES" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a1" ) )
	{
		strcpy( buffer, "UNFORSEEN CONSEQUENCES" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a1a" ) )
	{
		strcpy( buffer, "UNFORSEEN CONSEQUENCES" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a1b" ) )
	{
		strcpy( buffer, "UNFORSEEN CONSEQUENCES" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a1c" ) )
	{
		strcpy( buffer, "UNFORSEEN CONSEQUENCES" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a1d" ) )
	{
		strcpy( buffer, "UNFORSEEN CONSEQUENCES" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a1f" ) )
	{
		strcpy( buffer, "UNFORSEEN CONSEQUENCES" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a2" ) )
	{
		strcpy( buffer, "OFFICE COMPLEX" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a2a" ) )
	{
		strcpy( buffer, "OFFICE COMPLEX" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a2b" ) )
	{
		strcpy( buffer, "OFFICE COMPLEX" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a2c" ) )
	{
		strcpy( buffer, "OFFICE COMPLEX" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a2d" ) )
	{
		strcpy( buffer, "OFFICE COMPLEX" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a3" ) )
	{
		strcpy( buffer, "\"WE'VE GOT HOSTILES\"" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a3a" ) )
	{
		strcpy( buffer, "\"WE'VE GOT HOSTILES\"" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a3b" ) )
	{
		strcpy( buffer, "\"WE'VE GOT HOSTILES\"" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a3c" ) )
	{
		strcpy( buffer, "\"WE'VE GOT HOSTILES\"" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a3d" ) )
	{
		strcpy( buffer, "\"WE'VE GOT HOSTILES\"" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a4" ) )
	{
		strcpy( buffer, "BLAST PIT" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a4b" ) )
	{
		strcpy( buffer, "BLAST PIT" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a4d" ) )
	{
		strcpy( buffer, "BLAST PIT" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a4e" ) )
	{
		strcpy( buffer, "BLAST PIT" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a4f" ) )
	{
		strcpy( buffer, "BLAST PIT" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a4g" ) )
	{
		strcpy( buffer, "BLAST PIT" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a4i" ) )
	{
		strcpy( buffer, "BLAST PIT" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a4j" ) )
	{
		strcpy( buffer, "BLAST PIT" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c1a4k" ) )
	{
		strcpy( buffer, "BLAST PIT" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a1" ) )
	{
		strcpy( buffer, "POWER UP" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a1a" ) )
	{
		strcpy( buffer, "POWER UP" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a1b" ) )
	{
		strcpy( buffer, "POWER UP" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a2" ) )
	{
		strcpy( buffer, "ON A RAIL" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a2a" ) )
	{
		strcpy( buffer, "ON A RAIL" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a2b1" ) )
	{
		strcpy( buffer, "ON A RAIL" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a2b2" ) )
	{
		strcpy( buffer, "ON A RAIL" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a2c" ) )
	{
		strcpy( buffer, "ON A RAIL" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a2d" ) )
	{
		strcpy( buffer, "ON A RAIL" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a2e" ) )
	{
		strcpy( buffer, "ON A RAIL" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a2f" ) )
	{
		strcpy( buffer, "ON A RAIL" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a2g" ) )
	{
		strcpy( buffer, "ON A RAIL" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a2h" ) )
	{
		strcpy( buffer, "ON A RAIL" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a3" ) )
	{
		strcpy( buffer, "APPREHENSION" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a3a" ) )
	{
		strcpy( buffer, "APPREHENSION" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a3b" ) )
	{
		strcpy( buffer, "APPREHENSION" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a3c" ) )
	{
		strcpy( buffer, "APPREHENSION" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a3d" ) )
	{
		strcpy( buffer, "APPREHENSION" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a3e" ) )
	{
		strcpy( buffer, "APPREHENSION" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a4" ) )
	{
		strcpy( buffer, "RESIDUE PROCESSING" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a4a" ) )
	{
		strcpy( buffer, "RESIDUE PROCESSING" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a4b" ) )
	{
		strcpy( buffer, "RESIDUE PROCESSING" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a4c" ) )
	{
		strcpy( buffer, "RESIDUE PROCESSING" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a4d" ) )
	{
		strcpy( buffer, "QUESTIONABLE ETHICS" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a4e" ) )
	{
		strcpy( buffer, "QUESTIONABLE ETHICS" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a4f" ) )
	{
		strcpy( buffer, "QUESTIONABLE ETHICS" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a4g" ) )
	{
		strcpy( buffer, "QUESTIONABLE ETHICS" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a5" ) )
	{
		strcpy( buffer, "SURFACE TENSION" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a5a" ) )
	{
		strcpy( buffer, "SURFACE TENSION" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a5b" ) )
	{
		strcpy( buffer, "SURFACE TENSION" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a5c" ) )
	{
		strcpy( buffer, "SURFACE TENSION" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a5d" ) )
	{
		strcpy( buffer, "SURFACE TENSION" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a5e" ) )
	{
		strcpy( buffer, "SURFACE TENSION" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a5f" ) )
	{
		strcpy( buffer, "SURFACE TENSION" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a5g" ) )
	{
		strcpy( buffer, "SURFACE TENSION" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a5w" ) )
	{
		strcpy( buffer, "SURFACE TENSION" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c2a5x" ) )
	{
		strcpy( buffer, "SURFACE TENSION" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c3a1" ) )
	{
		strcpy( buffer, "\"FORGET ABOUT FREEMAN\"" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c3a1a" ) )
	{
		strcpy( buffer, "\"FORGET ABOUT FREEMAN\"" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c3a1b" ) )
	{
		strcpy( buffer, "\"FORGET ABOUT FREEMAN\"" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c3a2" ) )
	{
		strcpy( buffer, "\"FORGET ABOUT FREEMAN\"" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c3a2a" ) )
	{
		strcpy( buffer, "\"FORGET ABOUT FREEMAN\"" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c3a2b" ) )
	{
		strcpy( buffer, "\"FORGET ABOUT FREEMAN\"" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c3a2c" ) )
	{
		strcpy( buffer, "\"FORGET ABOUT FREEMAN\"" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c3a2d" ) )
	{
		strcpy( buffer, "\"FORGET ABOUT FREEMAN\"" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c3a2e" ) )
	{
		strcpy( buffer, "LAMBDA CORE" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c3a2f" ) )
	{
		strcpy( buffer, "LAMBDA CORE" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c4a1" ) )
	{
		strcpy( buffer, "XEN" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c4a1a" ) )
	{
		strcpy( buffer, "INTERLOPER" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c4a1b" ) )
	{
		strcpy( buffer, "INTERLOPER" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c4a1c" ) )
	{
		strcpy( buffer, "INTERLOPER" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c4a1d" ) )
	{
		strcpy( buffer, "INTERLOPER" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c4a1e" ) )
	{
		strcpy( buffer, "INTERLOPER" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c4a1f" ) )
	{
		strcpy( buffer, "INTERLOPER" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c4a2" ) )
	{
		strcpy( buffer, "GONARCH'S LAIR" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c4a2a" ) )
	{
		strcpy( buffer, "GONARCH'S LAIR" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c4a2b" ) )
	{
		strcpy( buffer, "GONARCH'S LAIR" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c4a3" ) )
	{
		strcpy( buffer, "NIHILANTH" );
	}
	else if( !strcmp( STRING( gpGlobals->mapname ), "c5a1" ) )
	{
		strcpy( buffer, "NIHILANTH" );
	}
	else
	{
		strcpy( buffer, STRING( gpGlobals->mapname ) );
	}
}