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

//
// Override the StudioModelRender virtual member functions here to implement custom bone
// setup, blending, etc.
//

/*
====================
CGameStudioModelRenderer

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