//========= Copyright © 1996-2002, Valve LLC, All rights reserved. ============
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================

// Triangle rendering, if any

#include "hud.h"
#include "mod/modhud.h"
#include "cl_util.h"

// Triangle rendering apis are in gEngfuncs.pTriAPI

#include "const.h"
#include "entity_state.h"
#include "cl_entity.h"
#include "triangleapi.h"
#include "Exports.h"

#include "particleman.h"
#include "tri.h"
extern IParticleMan *g_pParticleMan;

extern float g_iFogColor[3];
extern float g_iFogDensity;
extern float g_iStartDist;
extern float g_iEndDist;
extern int g_iFogSkybox;

extern int g_iWaterLevel;

void RenderFog( void )
{
	//Not in water and we want fog.
	bool bFog = g_iWaterLevel < 2 && g_iStartDist >= 0 && g_iEndDist >= 0;
	gEngfuncs.pTriAPI->FogParams( g_iFogDensity, g_iFogSkybox );
	gEngfuncs.pTriAPI->Fog( g_iFogColor, g_iStartDist, g_iEndDist, bFog );
}

/*
=================
HUD_DrawNormalTriangles

Non-transparent triangles-- add them here
=================
*/
void CL_DLLEXPORT HUD_DrawNormalTriangles( void )
{
//	RecClDrawNormalTriangles();

	gHUD.m_Spectator.DrawOverview();
}

#if defined( _TFC )
void RunEventList( void );
#endif

/*
=================
HUD_DrawTransparentTriangles

Render any triangles with transparent rendermode needs here
=================
*/
void CL_DLLEXPORT HUD_DrawTransparentTriangles( void )
{
//	RecClDrawTransparentTriangles();

#if defined( _TFC )
	RunEventList();
#endif

	if ( g_pParticleMan )
		 g_pParticleMan->Update();

	RenderFog();
}
