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
//=========================================================
// Construction Worker
//=========================================================

#include	"extdll.h"
#include	"util.h"
#include	"cbase.h"
#include	"monsters.h"
#include	"mod/modmonster.h"
#include	"schedule.h"

//=========================================================
// DEAD CONSTRUCTION WORKER PROP
//=========================================================
class CDeadConstruction : public CModMonster
{
public:
	void Spawn( void );
	int	Classify ( void ) { return	CLASS_PLAYER_ALLY; }

	void KeyValue( KeyValueData *pkvd );

	int	m_iPose;// which sequence to display	-- temporary, don't need to save
	static char *m_szPoses[3];
};

char *CDeadConstruction::m_szPoses[] = { "lying_on_back", "lying_on_side", "lying_on_stomach" };

void CDeadConstruction::KeyValue( KeyValueData *pkvd )
{
	if (FStrEq(pkvd->szKeyName, "pose"))
	{
		m_iPose = atoi(pkvd->szValue);
		pkvd->fHandled = TRUE;
	}
	else 
		CBaseMonster::KeyValue( pkvd );
}

LINK_ENTITY_TO_CLASS( monster_construction_dead, CDeadConstruction );

//=========================================================
// ********** DeadConstruction SPAWN **********
//=========================================================
void CDeadConstruction :: Spawn( )
{
	PRECACHE_MODEL("models/construction.mdl");
	SET_MODEL(ENT(pev), "models/construction.mdl");

	pev->effects		= 0;
	pev->yaw_speed		= 8;
	pev->sequence		= 0;
	m_bloodColor		= BLOOD_COLOR_RED;

	pev->sequence = LookupSequence( m_szPoses[m_iPose] );
	if (pev->sequence == -1)
	{
		ALERT ( at_console, "Dead construction with bad pose\n" );
	}
	// Corpses have less health
	pev->health			= 8;

	MonsterInitDead();
}
