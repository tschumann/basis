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

extern int			UTIL_PrecacheModelSafe( char *szModel );
extern void			UTIL_SetModelSafe( edict_t *pEdict, const char *szModel );
extern void			UTIL_ClampAngles( vec3_t &angles );

extern BOOL			UTIL_IsModel( edict_t *pent );
extern BOOL			UTIL_IsSprite( edict_t *pent );