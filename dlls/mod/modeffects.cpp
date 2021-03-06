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
#include "util.h"
#include "cbase.h"
#include "customentity.h"
#include "effects.h"

//=========================================================
// Fog
//=========================================================
#define SF_IN_SKYBOX	0x0001

LINK_ENTITY_TO_CLASS( env_fog, CClientFog );

void CClientFog::KeyValue( KeyValueData *pkvd )
{
	if( FStrEq( pkvd->szKeyName, "startdist" ) )
	{
		m_iStartDist = atoi( pkvd->szValue );
		pkvd->fHandled = TRUE;
	}
	else if( FStrEq( pkvd->szKeyName, "enddist" ) )
	{
		m_iEndDist = atoi( pkvd->szValue );
		pkvd->fHandled = TRUE;
	}
	else if( FStrEq( pkvd->szKeyName, "density" ) )
	{
		m_iDensity = atof( pkvd->szValue );
		pkvd->fHandled = TRUE;
	}
	else
	{
		CBaseEntity::KeyValue( pkvd );
	}
}

void CClientFog::Spawn( void )
{
	pev->movetype = MOVETYPE_NOCLIP;
	pev->solid = SOLID_NOT;							// Remove model & collisions
	pev->renderamt = 0;								// The engine won't draw this model if this is set to 0 and blending is on
	pev->rendermode = kRenderTransTexture;
}

//=========================================================
// Projectile
//=========================================================
class CEnvProjectile : public CBaseEntity
{
public:
	void Spawn(void);
	void Precache(void);
	void EXPORT ProjectileThink( void );
};

LINK_ENTITY_TO_CLASS( env_projectile, CEnvProjectile );

void CEnvProjectile::Spawn(void)
{
	pev->movetype = MOVETYPE_NOCLIP;
	pev->solid = SOLID_NOT;							// Remove model & collisions
	pev->speed = 5.0;

	Precache();
	SET_MODEL( ENT(pev), STRING(pev->model) );

	SetThink( &CEnvProjectile::ProjectileThink );
	pev->nextthink = gpGlobals->time;
}

void CEnvProjectile::Precache(void)
{
	PRECACHE_MODEL( (char *)STRING(pev->model) );
}

void CEnvProjectile::ProjectileThink( void )
{
	// set a random velocity
	pev->velocity.x = RANDOM_LONG(-1, 1) * 5;
	pev->velocity.y = RANDOM_LONG(-1, 1) * 5;
	pev->velocity.z = RANDOM_LONG(-1, 1) * 5;
	// think again in one second
	pev->nextthink = gpGlobals->time + 1.0;
}