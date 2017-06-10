//=========== (C) Copyright 1996-2002 Valve, L.L.C. All rights reserved. ===========
//
// The copyright to the contents herein is the property of Valve, L.L.C.
// The contents may be used and/or copied only with the written permission of
// Valve, L.L.C., or in accordance with the terms and conditions stipulated in
// the agreement/contract under which the contents have been supplied.
//
// Purpose: 
//
// $Workfile:     $
// $Date:         $
//
//-----------------------------------------------------------------------------
// $Log: $
//
// $NoKeywords: $
//=============================================================================

#include "hud.h"
#include "cl_util.h"
#include "vgui_ModViewport.h"

CModPanel::CModPanel(int iTrans, int iRemoveMe, int x, int y, int wide, int tall) : CMenuPanel(iTrans, iRemoveMe, x, y, wide, tall)
{
	CSchemeManager *pSchemes = gViewPort->GetSchemeManager();
	SchemeHandle_t hTitleScheme = pSchemes->getSchemeHandle( "Title Font" );

	int r, g, b, a;

	m_pPanel = new CTransparentPanel( 200, XRES(20), YRES(20), XRES(600), YRES(440) );
	m_pPanel->setParent( this );
	m_pPanel->setBorder( new LineBorder( Color(255 * 0.7, 170 * 0.7, 0, 0) ) );

	m_pTitle = new Label( "", XRES(1), YRES(1), XRES(478), YRES(58) );
	m_pTitle->setParent( m_pPanel );
	m_pTitle->setFont( pSchemes->getFont(hTitleScheme) );
	pSchemes->getFgColor( hTitleScheme, r, g, b, a );
	m_pTitle->setFgColor( r, g, b, a );
	pSchemes->getBgColor( hTitleScheme, r, g, b, a );
	m_pTitle->setBgColor( r, g, b, a );
	m_pTitle->setContentAlignment( vgui::Label::a_center );
	m_pTitle->setText( "Menu" );

	m_pCancelButton = new CommandButton( gHUD.m_TextMessage.BufferedLocaliseTextString( "#CANCEL" ), XRES(510), YRES(400), XRES(70), YRES(30) );
	m_pCancelButton->setContentAlignment( vgui::Label::a_west );
	m_pCancelButton->setParent( m_pPanel );
	m_pCancelButton->addActionSignal( new CMenuHandler_TextWindow(HIDE_TEXTWINDOW) );
}