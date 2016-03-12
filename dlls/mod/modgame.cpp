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

cvar_t	ragdolls = {"sv_ragdolls", 0};

// Construction Worker
cvar_t	sk_construction_health1 = {"sk_construction_health1","0"};
cvar_t	sk_construction_health2 = {"sk_construction_health2","0"};
cvar_t	sk_construction_health3 = {"sk_construction_health3","0"};

void ModDLLInit( void )
{
	CVAR_REGISTER (&ragdolls);

	CVAR_REGISTER (&sk_construction_health1);
	CVAR_REGISTER (&sk_construction_health2);
	CVAR_REGISTER (&sk_construction_health3);
}