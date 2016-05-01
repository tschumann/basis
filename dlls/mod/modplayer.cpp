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

===== modplayer.cpp ========================================================

  functions dealing with the player

*/

#include "extdll.h"
#include "util.h"

#include "cbase.h"
#include "modplayer.h"


//=========================================================
// 
//=========================================================
BOOL CModPlayer :: SwitchWeapon( CBasePlayerItem *pWeapon ) 
{
	if ( atof(g_engfuncs.pfnInfoKeyValue( g_engfuncs.pfnGetInfoKeyBuffer( this->edict() ), "cl_autowepswitch" )) )
	{
		return TRUE;
	}
	else
	{
		return CBasePlayer::SwitchWeapon( pWeapon );
	}
}

/*
=========================================================
	UpdateClientData

resends any changed player HUD info to the client.
Called every frame by PlayerPreThink
Also called at start of demo recording and playback by
ForceClientDllUpdate to ensure the demo gets messages
reflecting all of the HUD state info.
=========================================================
*/
void CModPlayer :: UpdateClientData( void )
{
	CBasePlayer::UpdateClientData();

	if (m_fInitHUD)
	{
		if ( !m_fGameHUDInitialized )
		{
			CBaseEntity *pEntity = NULL;

			MESSAGE_BEGIN( MSG_ONE, gmsgFog, NULL, pev );
				// send any info about client-side entities from here
				pEntity = UTIL_FindEntityByClassname( NULL, "env_fog" );

				if( pEntity )
				{
					CClientFog *pFog = (CClientFog *)pEntity;

					WRITE_FLOAT( pFog->pev->rendercolor.x );
					WRITE_FLOAT( pFog->pev->rendercolor.y );
					WRITE_FLOAT( pFog->pev->rendercolor.z );
					WRITE_FLOAT( pFog->m_iStartDist );
					WRITE_FLOAT( pFog->m_iEndDist );
					WRITE_FLOAT( pFog->m_iDensity );
					WRITE_BYTE( pFog->pev->spawnflags );
				}
				else
				{
					WRITE_FLOAT( 0.0 );
					WRITE_FLOAT( 0.0 );
					WRITE_FLOAT( 0.0 );
					WRITE_FLOAT( 0.0 );
					WRITE_FLOAT( 0.0 );
					WRITE_FLOAT( 0.0 );
					WRITE_CHAR( 0 );
				}
			MESSAGE_END();
		}
	}
}

LINK_ENTITY_TO_CLASS( player, CModPlayer );