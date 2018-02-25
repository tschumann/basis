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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/nowin.h"
#include "steam/steamtypes.h"

typedef uint32 ULONG;
typedef int BOOL;
#define TRUE	 1	
#define FALSE	0

// hack into header files that we can ship
typedef int qboolean;
typedef unsigned char byte;
#include "../utils/common/mathlib.h"
#include "const.h"
#include "progdefs.h"
#include "edict.h"
#include "eiface.h"
#include "com_model.h"
#include "r_studioint.h"

// mathlib.h has vec3_t as an array whereas util.h has it as class Vector, and util.h is needed for SVC_TEMPENTITY
#define VECTOR_H
class Vector
{
public:
	operator const float *() const					{ return &x; }

	vec_t x, y, z;
};
#include "cdll_dll.h"
#include "util.h"
#undef VECTOR_H

#include "studio.h"

#ifndef MODANIMATION_H
#include "mod/modanimation.h"
#endif



// The simple blending interface we'll pass back to the engine
sv_blending_interface_t svBlending = 
{
        SV_BLENDING_INTERFACE_VERSION,
        SV_StudioSetupBones
};

// Global engine <-> studio model code interface
server_studio_api_t IEngineStudio;

studiohdr_t *g_pstudiohdr;

float (*g_pRotationMatrix)[3][4];

float (*g_pBoneTransform)[MAXSTUDIOBONES][3][4];



void DrawBox( vec3_t p[], byte r, byte g, byte b )
{
	for( int i = 0; i < 8; i += 2 )
	{
		MESSAGE_BEGIN( MSG_PVS, SVC_TEMPENTITY );
			WRITE_BYTE( TE_LINE );
			WRITE_COORD( p[i][0] );
			WRITE_COORD( p[i][1] );
			WRITE_COORD( p[i][2] );

			WRITE_COORD( p[i + 1][0] );
			WRITE_COORD( p[i + 1][1] );
			WRITE_COORD( p[i + 1][2] );

			WRITE_SHORT( 1 );

			WRITE_BYTE( r );
			WRITE_BYTE( g );
			WRITE_BYTE( b );
		MESSAGE_END();
	}
}


/*
====================
Server_GetBlendingInterface

Export this function for the engine to use the blending code to blend models
====================
*/
#ifdef _WIN32

extern "C" int __declspec( dllexport ) Server_GetBlendingInterface( int version, struct sv_blending_interface_s **ppinterface, struct server_studio_api_s *pstudio, float (*rotationmatrix)[3][4], float (*bonetransform)[MAXSTUDIOBONES][3][4] )

#else

extern "C" int Server_GetBlendingInterface( int version, struct sv_blending_interface_s **ppinterface, struct server_studio_api_s *pstudio, float (*rotationmatrix)[3][4], float (*bonetransform)[MAXSTUDIOBONES][3][4] )

#endif
{
	if ( version != SV_BLENDING_INTERFACE_VERSION )
		return 0;

	// Point the engine to our callback
	*ppinterface = &svBlending;

	// Copy in engine helper functions
	memcpy( &IEngineStudio, pstudio, sizeof( IEngineStudio ) );

	g_pRotationMatrix = rotationmatrix;

	g_pBoneTransform = bonetransform;

	// Success
	return 1;
}


// blending function used by the server to blend the models (for hitbox purposes)
void SV_StudioSetupBones( struct model_s *pModel, float frame, int sequence, const vec3_t angles, const vec3_t origin, const byte *pcontroller, const byte *pblending, int iBone, const edict_t *pEdict )
{
	// your blending code here...


	g_pstudiohdr = (studiohdr_t *)IEngineStudio.Mod_Extradata (pModel);

	if( drawhitboxes.value )
	{
		mstudiobbox_t	*pbbox;
		vec3_t	tmp;
		vec3_t	p[8];
		int i,j;

		pbbox	= (mstudiobbox_t *)((byte *)g_pstudiohdr + g_pstudiohdr->hitboxindex);

		for (i = 0; i < g_pstudiohdr->numhitboxes; i++)
		{
			//get the vector positions of the 8 corners of the bounding box
			for (j = 0; j < 8; j++)
			{
				tmp[0] = (j & 1) ? pbbox[i].bbmin[0] : pbbox[i].bbmax[0];
				tmp[1] = (j & 2) ? pbbox[i].bbmin[1] : pbbox[i].bbmax[1];
				tmp[2] = (j & 4) ? pbbox[i].bbmin[2] : pbbox[i].bbmax[2];

				VectorTransform( tmp, (*g_pBoneTransform)[pbbox[i].bone], p[j] );
			}

			DrawBox( p, 255, 0, 0 );
		}
	}
}
