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

#ifndef MODWEAPONS_H
#define MODWEAPONS_H

#include "../weapons.h"

class CModPlayerItem : public CBasePlayerItem
{
public:
	virtual int PlayerIndex();
	void KeyValue( KeyValueData *pkvd );
private:
	int m_iPlayerIndex;
};

#endif // MODWEAPONS_H
