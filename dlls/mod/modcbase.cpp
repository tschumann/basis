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
#include	"extdll.h"
#include	"util.h"
#include	"cbase.h"
#include	"mod/modcbase.h"
#include	"mod/modgame.h"

int ModDispatchSpawn( edict_t *pent )
{
	CBaseEntity *pEntity = (CBaseEntity *)GET_PRIVATE(pent);

	if (pEntity)
	{
		const char *szModelName = STRING(pEntity->pev->model);

		// swap the model name at spawn time (but not for brush models) - overriding the model name that gets passed
		// to engine functions works but the wrong model name in entvars_t ends up causing problems in the engine
		if ( strlen( szModelName ) && szModelName[0] != '*' && g_pFileSystem && !g_pFileSystem->FileExists( szModelName ) )
		{
			ALERT( at_warning, "%s doesn't exist - changing %s to use models/null.mdl instead\n", szModelName, STRING(pEntity->pev->classname) );
			pEntity->pev->model = MAKE_STRING( "models/null.mdl" );
		}
	}

	return DispatchSpawn( pent );
}