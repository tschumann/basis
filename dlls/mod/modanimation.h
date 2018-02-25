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
#ifndef MODANIMATION_H
#define MODANIMATION_H

extern cvar_t drawhitboxes;

void SV_StudioSetupBones( struct model_s *pModel, float frame, int sequence, const vec3_t angles, const vec3_t origin, const byte *pcontroller, const byte *pblending, int iBone, const edict_t *pEdict );

#endif	//MODANIMATION_H