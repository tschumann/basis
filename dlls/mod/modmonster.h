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

#ifndef MODMONSTER_H
#define MODMONSTER_H

//
// generic Monster
//
class CModMonster : public CBaseMonster
{
public:
	virtual void Look ( int iDistance );// basic sight function for monsters

	virtual void BecomeDead( void );

	virtual CBaseEntity* BestVisibleEnemy ( void );// finds best visible enemy for attack

	virtual int DeadTakeDamage( entvars_t *pevInflictor, entvars_t *pevAttacker, float flDamage, int bitsDamageType );
};

#endif // MODMONSTER_H