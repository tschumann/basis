/***
*
*	Copyright (c) 1996-2002, Valve LLC. All rights reserved.
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
// modhud.cpp
//
// implementation of CModHud class
//

#include "hud.h"
#include "modhud.h"
#include "cl_util.h"
#include <string.h>
#include <stdio.h>
#include "parsemsg.h"
#include "hud_servers.h"
#include "vgui_int.h"
#include "vgui_TeamFortressViewport.h"
#include "mod/vgui_ModViewport.h"

#include "demo.h"
#include "demo_api.h"
#include "vgui_ScorePanel.h"

cvar_t *r_cull = NULL;

// TFFree Command Menu
void __CmdFunc_OpenModMenu(void)
{
	if( gViewPort )
	{
		gViewPort->ShowVGUIMenu( MENU_MENU );
		gEngfuncs.PlayerInfo_SetValueForKey( "menu", "1" );
	}
}

void __CmdFunc_CloseModMenu(void)
{
	if( gViewPort )
	{
		gViewPort->ShowVGUIMenu( -MENU_MENU );
		gEngfuncs.PlayerInfo_SetValueForKey( "menu", "0" );
	}
}

// This is called every time the DLL is loaded
void CModHud :: Init( void )
{
	CHud::Init();

	HOOK_COMMAND( "+modmenu", OpenModMenu );
	HOOK_COMMAND( "-modmenu", CloseModMenu );

	CVAR_CREATE("cl_autowepswitch", "1", FCVAR_ARCHIVE | FCVAR_USERINFO);		// controls where the user automatically switches to the weapon they've just picked up

	r_cull = CVAR_CREATE("r_cull", "0", FCVAR_ARCHIVE);
}