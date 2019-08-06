//========= Copyright © 1996-2002, Valve LLC, All rights reserved. ============
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================

#include <assert.h>
#include "hud.h"
#include "cl_util.h"
#include "const.h"
#include "com_model.h"
#include "studio.h"
#include "entity_state.h"
#include "cl_entity.h"
#include "dlight.h"
#include "triangleapi.h"

#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <math.h>

#include "studio_util.h"
#include "r_studioint.h"

#include "StudioModelRenderer.h"
#include "ModStudioModelRenderer.h"
#include "GameStudioModelRenderer.h"

extern cvar_t *r_cull;

//
// Override the StudioModelRender virtual member functions here to implement custom bone
// setup, blending, etc.
//

// Global engine <-> studio model rendering code interface
extern engine_studio_api_t IEngineStudio;

/*
====================
CModStudioModelRenderer

====================
*/
CModStudioModelRenderer::CModStudioModelRenderer( void )
{
}

/*
====================
StudioRenderModel

====================
*/
void CModStudioModelRenderer::StudioRenderModel( void )
{
	if ( !StudioShouldRenderModel( m_pRenderModel ) )
	{
		return;
	}

	CStudioModelRenderer::StudioRenderModel( );
}

/*
====================
StudioCulling

====================
*/
void CModStudioModelRenderer::StudioCulling( void )
{
	if (r_cull->value)
	{
		gEngfuncs.pTriAPI->CullFace( TRI_FRONT );
	}
	else
	{
		gEngfuncs.pTriAPI->CullFace( TRI_NONE );
	}
}

/*
====================
StudioScaleBones

====================
*/
void CModStudioModelRenderer::StudioScaleBones( void )
{
	if (m_pCurrentEntity->curstate.scale > 0.0)
	{
		// scale the bones by the entity's scale
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				(*m_protationmatrix)[i][j] *= m_pCurrentEntity->curstate.scale;
			}
		}
	}
}

/*
====================
StudioShouldRenderModel

====================
*/
bool CModStudioModelRenderer::StudioShouldRenderModel( model_t *pRenderModel )
{
	return true;
}