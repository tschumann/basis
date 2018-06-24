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
#include "saverestore.h"
#include "skill.h"
#include "gamerules.h"

//-------------------------------------------------------------
// Wall mounted charger
//-------------------------------------------------------------
class CBaseCharger : public CBaseToggle
{
public:
	virtual void Spawn( );
	void EXPORT Off(void);
	virtual void EXPORT Recharge(void);
	void KeyValue( KeyValueData *pkvd );
	void Use( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value );
	virtual int	ObjectCaps( void ) { return (CBaseToggle :: ObjectCaps() | FCAP_CONTINUOUS_USE) & ~FCAP_ACROSS_TRANSITION; }
	virtual int		Save( CSave &save );
	virtual int		Restore( CRestore &restore );

	static	TYPEDESCRIPTION m_SaveData[];

	float m_flNextCharge; 
	int		m_iReactivate ; // DeathMatch Delay until reactvated
	int		m_iJuice;
	int		m_iOn;			// 0 = off, 1 = startup, 2 = going
	float   m_flSoundTime;

	string_t m_iszStopSound;
	float m_flRechargeTime;
};

void CBaseCharger::Spawn()
{
	Precache( );

	pev->solid		= SOLID_BSP;
	pev->movetype	= MOVETYPE_PUSH;

	UTIL_SetOrigin(pev, pev->origin);		// set size and link into world
	UTIL_SetSize(pev, pev->mins, pev->maxs);
	SET_MODEL(ENT(pev), STRING(pev->model) );	
}

void CBaseCharger::Off(void)
{
	// Stop looping sound.
	if (m_iOn > 1)
		STOP_SOUND( ENT(pev), CHAN_STATIC, STRING(m_iszStopSound) );

	m_iOn = 0;

	if ((!m_iJuice) &&  ( ( m_iReactivate = m_flRechargeTime ) > 0) )
	{
		pev->nextthink = pev->ltime + m_iReactivate;
		SetThink(&CBaseCharger::Recharge);
	}
	else
		SetThink( &CBaseCharger::SUB_DoNothing );
}

class CHealthCharger : public CBaseCharger
{
public:
	void Spawn( );
	void Precache( void );
	void EXPORT Recharge(void);
};

void CHealthCharger::Spawn()
{
	CBaseCharger::Spawn(  );
	m_iJuice = gSkillData.healthchargerCapacity;
	m_iszStopSound = MAKE_STRING("items/medcharge4.wav");
	m_flRechargeTime = g_pGameRules->FlHealthChargerRechargeTime();
}

void CHealthCharger::Precache()
{
	PRECACHE_SOUND("items/medshot4.wav");
	PRECACHE_SOUND("items/medshotno1.wav");
	PRECACHE_SOUND("items/medcharge4.wav");
}

void CHealthCharger::Recharge(void)
{
		EMIT_SOUND(ENT(pev), CHAN_ITEM, "items/medshot4.wav", 1.0, ATTN_NORM );
	m_iJuice = gSkillData.healthchargerCapacity;
	SetThink( &CHealthCharger::SUB_DoNothing );
}


class CArmorCharger : public CBaseCharger
{
public:
	void Spawn( );
	void Precache( void );
	void EXPORT Recharge(void);
};

void CArmorCharger::Spawn()
{
	CBaseCharger::Spawn(  );
	m_iJuice = gSkillData.suitchargerCapacity;		
	m_iszStopSound = MAKE_STRING("items/suitcharge1.wav");
	m_flRechargeTime = g_pGameRules->FlHEVChargerRechargeTime();
}

void CArmorCharger::Precache()
{
	PRECACHE_SOUND("items/suitcharge1.wav");
	PRECACHE_SOUND("items/suitchargeno1.wav");
	PRECACHE_SOUND("items/suitchargeok1.wav");
}

void CArmorCharger::Recharge(void)
{
	m_iJuice = gSkillData.suitchargerCapacity;
	SetThink( &CArmorCharger::SUB_DoNothing );
}