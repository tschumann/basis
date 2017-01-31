/***
*
*	Copyright (c) 1999, Valve LLC. All rights reserved.
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
// cl_mod_util.h
//

extern void ConsolePrintf( const char *format, ... );
extern void ConsoleDPrintf( const char *format, ... );

extern void CL_LoadGameUI( void );
extern void CL_UnloadGameUI( void );

extern void CL_LoadVGUI2( void );
extern void CL_UnloadVGUI2( void );