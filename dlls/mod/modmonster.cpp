/***
*
*	Copyright (c) 1996-2001, Valve LLC. All rights reserved.
*	
*	This product contains software technology licensed from Id 
*	Software, Inc. ("Id Technology").  Id Technology (c) 1996 Id Software, Inc. 
*	All Rights Reserved.
*
*   This source code contains proprietary and confidential information of
*   Valve LLC and its suppliers.  Access to this code is restricted to
*   persons who have executed a written SDK license with Valve.  Any access,
*   use or distribution of this code by or to any unlicensed person is illegal.
*
****/
/*

===== modmonster.cpp ========================================================

  Monster-related utility code

*/

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "monsters.h"
#include "mod/modgame.h"
#include "mod/modmonster.h"

void CModMonster :: Look ( int iDistance )
{
	if ( ai.value )
	{
		CBaseMonster ::Look( iDistance );
	}
}

void CModMonster::BecomeDead( void )
{
	CBaseMonster::BecomeDead();

	if ( physics.value )
	{
		pev->flags &= ~FL_ONGROUND;
		pev->origin.z += 2;
		pev->velocity = g_vecAttackDir * -1;
		pev->velocity = pev->velocity * RANDOM_FLOAT( 300, 400 );
	}
}

CBaseEntity *CModMonster :: BestVisibleEnemy ( void )
{
	if ( ai.value )
	{
		return CBaseMonster :: BestVisibleEnemy();
	}
	else
	{
		return NULL;
	}
}

//=========================================================
// DeadTakeDamage - takedamage function called when a monster's
// corpse is damaged.
//=========================================================
int CModMonster :: DeadTakeDamage( entvars_t *pevInflictor, entvars_t *pevAttacker, float flDamage, int bitsDamageType )
{
	Vector			vecDir;

	// grab the vector of the incoming attack. ( pretend that the inflictor is a little lower than it really is, so the body will tend to fly upward a bit).
	vecDir = Vector( 0, 0, 0 );
	if (!FNullEnt( pevInflictor ))
	{
		CBaseEntity *pInflictor = CBaseEntity :: Instance( pevInflictor );
		if (pInflictor)
		{
			vecDir = ( pInflictor->Center() - Vector ( 0, 0, 10 ) - Center() ).Normalize();
			vecDir = g_vecAttackDir = vecDir.Normalize();
		}
	}

	// turn this back on when the bounding box issues are resolved.
	if ( physics.value )
	{
		pev->flags &= ~FL_ONGROUND;
		pev->origin.z += 1;
		
		// let the damage scoot the corpse around a bit.
		if ( !FNullEnt(pevInflictor) && (pevAttacker->solid != SOLID_TRIGGER) )
		{
			pev->velocity = pev->velocity + vecDir * -DamageForce( flDamage );
		}
	}

	return CBaseMonster::DeadTakeDamage(pevInflictor, pevAttacker, flDamage, bitsDamageType);
}