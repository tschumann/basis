/***
*
*	Copyright (c) 1999, Valve LLC. All rights reserved.
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
//
//  hud_msg.cpp
//

#include "hud.h"
#include "mod/modhud.h"
#include "cl_util.h"
#include "parsemsg.h"

float g_iFogColor[3];
float g_iFogDensity;
float g_iStartDist;
float g_iEndDist;
int g_iFogSkybox;

/// USER-DEFINED SERVER MESSAGE HANDLERS

void CModHud :: MsgFunc_Fog( const char *pszName, int iSize, void *pbuf )
{
	// Clear the fog
	g_iFogColor[0] = 0.0;
	g_iFogColor[1] = 0.0;
	g_iFogColor[2] = 0.0;
	g_iStartDist = 0.0;
	g_iEndDist = 0.0;
	g_iFogDensity = 0.0;
	g_iFogSkybox = 0.0;

	BEGIN_READ( pbuf, iSize );

	g_iFogColor[0] = READ_FLOAT();
	g_iFogColor[1] = READ_FLOAT();
	g_iFogColor[2] = READ_FLOAT();
	g_iStartDist = READ_FLOAT();
	g_iEndDist = READ_FLOAT();
	g_iFogDensity = READ_FLOAT();
	g_iFogSkybox = READ_BYTE();
}