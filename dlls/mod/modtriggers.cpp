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

===== modtriggers.cpp ========================================================

  spawn and use functions for editor-placed triggers              

*/

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "mod/modmonster.h"
#include "player.h"
#include "saverestore.h"
#include "mod/triggers.h"

//
// Trigger that sets a bit in a trigger_bit_counter
//
class CTriggerBit : public CBaseTrigger
{
public:
	void Spawn( void );
	void Use( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value );
};

LINK_ENTITY_TO_CLASS( trigger_bit, CTriggerBit );

void CTriggerBit::Spawn( void )
{
	InitTrigger();
}

void CTriggerBit::Use( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value )
{
	FireTargets( STRING(pev->target), pActivator, this, USE_TOGGLE, pev->skin );
}


//
// Trigger that fires when its bit combination is set
//
class CTriggerBitCounter : public CBaseTrigger
{
public:
	void Spawn( void );
	void KeyValue( KeyValueData *pkvd );
	void Use( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value );
	void EXPORT Think( void );
private:
	int m_iMask;
	int m_iValue;
};

LINK_ENTITY_TO_CLASS( trigger_bit_counter, CTriggerBitCounter );

void CTriggerBitCounter::Spawn( void )
{
	InitTrigger();

	m_iValue = pev->skin;

	SetThink( &CTriggerBitCounter::Think );

	pev->nextthink = gpGlobals->time;
}

void CTriggerBitCounter::KeyValue( KeyValueData *pkvd )
{
	if( FStrEq( pkvd->szKeyName, "triggermask" ) )
	{
		m_iMask = atoi(pkvd->szValue);
		pkvd->fHandled = TRUE;
	}
	else
	{
		CBaseTrigger::KeyValue( pkvd );
	}
}

void CTriggerBitCounter::Use( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value )
{
	// toggle the bit
	m_iValue ^= (int)value;

	// start thinking after being used
	pev->nextthink = gpGlobals->time;
}

void CTriggerBitCounter::Think( void )
{
	if( m_iValue == m_iMask )
	{
		FireTargets( STRING(pev->target), this, this, USE_TOGGLE, 0.0 );
		// stop thinking (and firing) for now - next use will start thinking again
		pev->nextthink = 0;
	}
	else
	{
		pev->nextthink = gpGlobals->time + 0.1;
	}
}