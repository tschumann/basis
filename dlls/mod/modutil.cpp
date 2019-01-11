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

===== modutil.cpp ========================================================

Utility code.

*/

#include "extdll.h"
#include "util.h"
#include "mod/modutil.h"
#include "mod/modgame.h"

int UTIL_PrecacheModelSafe( char *szModel )
{
	if( g_pFileSystem && !g_pFileSystem->FileExists( szModel ) )
	{
		ALERT( at_error, "%s doesn't exist - precaching models/null.mdl instead\n", szModel );
		return (*g_engfuncs.pfnPrecacheModel)("models/null.mdl");
	}
	return (*g_engfuncs.pfnPrecacheModel)( szModel );
}

void UTIL_SetModelSafe( edict_t *pEdict, const char *szModel )
{
	// check it's not a brushmodel (name starts with *)
	if( g_pFileSystem && !g_pFileSystem->FileExists( szModel ) && strncmp( szModel, "*", 1 ) )
	{
		ALERT( at_error, "%s doesn't exist - setting models/null.mdl instead\n", szModel );
		(*g_engfuncs.pfnSetModel)(pEdict, "models/null.mdl");

		return;
	}
	(*g_engfuncs.pfnSetModel)( pEdict, szModel );
}

void UTIL_ClampAngles( vec3_t &angles )
{
	if( angles.x >= 180.0f )
	{
		angles.x -= 360 * ((int)(angles.x / 360.0f) + 1);
	}
	if( angles.x < -180.0f )
	{
		angles.x += 360 * ((int)(angles.x / 360.0f) + 1);
	}
	if( angles.y >= 180.0f )
	{
		angles.y -= 360 * ((int)(angles.y / 360.0f) + 1);
	}
	if( angles.y < -180.0f )
	{
		angles.y += 360 * ((int)(angles.y / 360.0f) + 1);
	}
	if( angles.z >= 180.0f )
	{
		angles.z -= 360 * ((int)(angles.z / 360.0f) + 1);
	}
	if( angles.z < -180.0f )
	{
		angles.z += 360 * ((int)(angles.z / 360.0f) + 1);
	}
}

BOOL UTIL_IsModel( edict_t *pent )
{
	const char *szExtension = strrchr( STRING(pent->v.model), '.' );

	return szExtension && strcmp(szExtension, ".mdl") == 0;
}

BOOL UTIL_IsSprite( edict_t *pent )
{
	const char *szExtension = strrchr( STRING(pent->v.model), '.' );

	return szExtension && strcmp(szExtension, ".spr") == 0;
}

void UTIL_ClientPrintf( edict_t* pEdict, PRINT_TYPE ptype, const char *szFormat, ... )
{
	char string[1024];

	va_list args;
	va_start(args, szFormat);
	vsprintf(string, szFormat, args);
	va_end(args);

	if( strlen( string ) > 40 && ptype == print_center )
	{
		ALERT( at_error, "The engine will truncate your message \"%s\" as it is more than 40 characters long\n", string );
	}

	CLIENT_PRINTF( pEdict, ptype, string );
}