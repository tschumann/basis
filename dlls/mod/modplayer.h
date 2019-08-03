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
#ifndef MODPLAYER_H
#define MODPLAYER_H

#include "../player.h"

class CModPlayer : public CBasePlayer
{
public:
	virtual void UpdateClientData( void );

	virtual BOOL IsBot();
};

#endif // MODPLAYER_H
