//========= Copyright © 1996-2002, Valve LLC, All rights reserved. ============
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================

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
#include "mod/modtri.h"

extern cvar_t *r_boundingboxes;

void RenderBoundingBoxes( void )
{
	int i = 0;

	if( r_boundingboxes->value )
	{
		while( true )
		{
			cl_entity_t *pEntity = gEngfuncs.GetEntityByIndex( i );

			// if there are no more entities, stop looping
			if( !pEntity )
			{
				break;
			}
			else
			{
				i++;

				vec3_t mins = pEntity->curstate.mins;
				vec3_t maxs = pEntity->curstate.maxs;

				gEngfuncs.pTriAPI->RenderMode( kRenderNormal );
				gEngfuncs.pTriAPI->CullFace( TRI_NONE );
				gEngfuncs.pTriAPI->Begin( TRI_LINES );

				gEngfuncs.pTriAPI->Color4f( 0.0, 1.0, 0.0, 1.0 );
				gEngfuncs.pTriAPI->Brightness( 1.0 );

				// straight lines
				gEngfuncs.pTriAPI->Vertex3f( mins.x, mins.y, mins.z );
				gEngfuncs.pTriAPI->Vertex3f( maxs.x, mins.y, mins.z );

				gEngfuncs.pTriAPI->Vertex3f( mins.x, mins.y, mins.z );
				gEngfuncs.pTriAPI->Vertex3f( mins.x, maxs.y, mins.z );

				gEngfuncs.pTriAPI->Vertex3f( mins.x, mins.y, mins.z );
				gEngfuncs.pTriAPI->Vertex3f( mins.x, mins.y, maxs.z );

				// angled lines
				gEngfuncs.pTriAPI->Vertex3f( mins.x, mins.y, mins.z );
				gEngfuncs.pTriAPI->Vertex3f( maxs.x, mins.y, maxs.z );

				gEngfuncs.pTriAPI->Vertex3f( mins.x, mins.y, mins.z );
				gEngfuncs.pTriAPI->Vertex3f( mins.x, maxs.y, maxs.z );

				gEngfuncs.pTriAPI->Vertex3f( mins.x, mins.y, mins.z );
				gEngfuncs.pTriAPI->Vertex3f( maxs.x, maxs.y, maxs.z );

				gEngfuncs.pTriAPI->End();
			}
		}
	}
}