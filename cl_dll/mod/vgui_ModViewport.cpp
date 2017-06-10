//=========== (C) Copyright 1999 Valve, L.L.C. All rights reserved. ===========
//
// The copyright to the contents herein is the property of Valve, L.L.C.
// The contents may be used and/or copied only with the written permission of
// Valve, L.L.C., or in accordance with the terms and conditions stipulated in
// the agreement/contract under which the contents have been supplied.
//
// Purpose: Client DLL VGUI Viewport
//
// $Workfile:     $
// $Date:         $
//
//-----------------------------------------------------------------------------
// $Log: $
//
// $NoKeywords: $
//=============================================================================
#include<VGUI_Cursor.h>
#include<VGUI_Frame.h>
#include<VGUI_Label.h>
#include<VGUI_Surface.h>
#include<VGUI_BorderLayout.h>
#include<VGUI_Panel.h>
#include<VGUI_ImagePanel.h>
#include<VGUI_Button.h>
#include<VGUI_ActionSignal.h>
#include<VGUI_InputSignal.h>
#include<VGUI_MenuSeparator.h>
#include<VGUI_TextPanel.h>
#include<VGUI_LoweredBorder.h>
#include<VGUI_LineBorder.h>
#include<VGUI_Scheme.h>
#include<VGUI_Font.h>
#include<VGUI_App.h>
#include<VGUI_BuildGroup.h>

#include "hud.h"
#include "cl_util.h"
#include "camera.h"
#include "kbutton.h"
#include "cvardef.h"
#include "usercmd.h"
#include "const.h"
#include "camera.h"
#include "in_defs.h"
#include "parsemsg.h"
#include "pm_shared.h"
#include "keydefs.h"
#include "demo.h"
#include "demo_api.h"

#include "vgui_int.h"
#include "vgui_TeamFortressViewport.h"
#include "vgui_ModViewport.h"
#include "vgui_ServerBrowser.h"
#include "vgui_ScorePanel.h"
#include "vgui_SpectatorPanel.h"

#include "shake.h"
#include "screenfade.h"

//================================================================
ModViewport::ModViewport(int x, int y, int wide, int tall) : TeamFortressViewport(x, y, wide, tall)
{
	m_pModPanel = NULL;

	CreateModMenu();
}

//-----------------------------------------------------------------------------
// Purpose: Called everytime a new level is started. Viewport clears out it's data.
//-----------------------------------------------------------------------------
void ModViewport::Initialize(void)
{
	TeamFortressViewport::Initialize();

	// Force each menu to Initialize
	if (m_pModPanel)
	{
		m_pModPanel->setVisible( false );
	}
}

void ModViewport::SetCurrentMenu( CMenuPanel *pMenu )
{
	m_pCurrentMenu = pMenu;
	if ( m_pCurrentMenu )
	{
		// in the parent this doesn't get called if it happens during demo playback
		m_pCurrentMenu->Open();
	}
	else
	{
		gEngfuncs.pfnClientCmd( "closemenus;" );
	}
}

//======================================================================================
// MOD MENU
//======================================================================================
// Show the mod Menu
CMenuPanel* ModViewport::ShowModMenu()
{
	m_pModPanel->Reset();
	return m_pModPanel;
}

void ModViewport::CreateModMenu()
{
	// Create the panel
	m_pModPanel = new CModPanel(100, false, 0, 0, ScreenWidth, ScreenHeight);
	m_pModPanel->setParent( this );
	m_pModPanel->setVisible( false );
}