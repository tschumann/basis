/***
*
*	Copyright (c) 1996-2002, Valve LLC. All rights reserved.
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
// hassault
//=========================================================

#include	"extdll.h"
#include	"util.h"
#include	"cbase.h"
#include	"monsters.h"
#include	"schedule.h"
#include	"animation.h"
#include	"squadmonster.h"
#include	"talkmonster.h"
#include	"soundent.h"

class CHAssault : public CSquadMonster
{
public:
	void Spawn( void );
	void Precache( void );
	int  Classify ( void );
	int ISoundMask ( void );

	int IRelationship ( CBaseEntity *pTarget );
};

LINK_ENTITY_TO_CLASS( monster_human_assault, CHAssault );

//=========================================================
// IRelationship - overridden because Alien Grunts are 
// Human Assault's nemesis.
//=========================================================
int CHAssault::IRelationship ( CBaseEntity *pTarget )
{
	if ( FClassnameIs( pTarget->pev, "monster_alien_grunt" ) || ( FClassnameIs( pTarget->pev,  "monster_gargantua" ) ) )
	{
		return R_NM;
	}

	return CSquadMonster::IRelationship( pTarget );
}

//=========================================================
// ISoundMask - Overidden for human assults because they 
// hear the DANGER sound that is made by hand grenades and
// other dangerous items.
//=========================================================
int CHAssault :: ISoundMask ( void )
{
	return	bits_SOUND_WORLD	|
			bits_SOUND_COMBAT	|
			bits_SOUND_PLAYER	|
			bits_SOUND_DANGER;
}

//=========================================================
// Classify - indicates this monster's place in the 
// relationship table.
//=========================================================
int	CHAssault :: Classify ( void )
{
	return	CLASS_HUMAN_MILITARY;
}

//=========================================================
// Spawn
//=========================================================
void CHAssault :: Spawn()
{
	Precache( );

	SET_MODEL(ENT(pev), "models/hassault.mdl");
	UTIL_SetSize(pev, VEC_HUMAN_HULL_MIN, VEC_HUMAN_HULL_MAX);

	pev->solid			= SOLID_SLIDEBOX;
	pev->movetype		= MOVETYPE_STEP;
	m_bloodColor		= BLOOD_COLOR_RED;
	pev->effects		= 0;
	pev->health			= gSkillData.hgruntHealth;
	m_flFieldOfView		= 0.2;// indicates the width of this monster's forward view cone ( as a dotproduct result )
	m_MonsterState		= MONSTERSTATE_NONE;

	m_afCapability		= bits_CAP_SQUAD | bits_CAP_TURN_HEAD | bits_CAP_DOORS_GROUP;

	CTalkMonster::g_talkWaitTime = 0;

	MonsterInit();
}

//=========================================================
// Precache - precaches all resources this monster needs
//=========================================================
void CHAssault :: Precache()
{
	PRECACHE_MODEL("models/hassault.mdl");

	PRECACHE_SOUND("sounds/hassault/hw_gun4.wav");
	PRECACHE_SOUND("sounds/hassault/hw_shoot1.wav");
	PRECACHE_SOUND("sounds/hassault/hw_shoot2.wav");
	PRECACHE_SOUND("sounds/hassault/hw_shoot3.wav");
	PRECACHE_SOUND("sounds/hassault/hw_spin.wav");
	PRECACHE_SOUND("sounds/hassault/hw_spindown.wav");
	PRECACHE_SOUND("sounds/hassault/hw_spinup.wav");
}	