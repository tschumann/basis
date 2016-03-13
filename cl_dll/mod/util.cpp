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
// util.cpp
//
// implementation of class-less helper functions
//

#include "mod/cl_util.h"
#include "IGameConsole.h"

extern IGameConsole *g_pGameConsole;

void ConsolePrintf( const char *format, ... )
{
	if( g_pGameConsole )
	{
		g_pGameConsole->Printf( format, ... );
	}
	else
	{
		gEngfuncs.Con_Printf( format, ... );
	}
}

void ConsoleDPrintf( const char *format, ... )
{
	if( g_pGameConsole )
	{
		g_pGameConsole->DPrintf( format, .. );
	}
	else
	{
		gEngfuncs.Con_DPrintf( format, ... );
	}
}