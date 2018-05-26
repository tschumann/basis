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
// mod_cl_util.h
//

#include "com_model.h"

#ifdef _WIN32
#define FILESYSTEM_DLLNAME "FileSystem_Steam.dll"
#elif defined(OSX)
#define FILESYSTEM_DLLNAME "FileSystem_Steam.dylib"
#elif defined(__linux__)
#define FILESYSTEM_DLLNAME "FileSystem_Steam.so"
#else
#error
#endif

extern void ConsolePrintf( const char *format, ... );
extern void ConsoleDPrintf( const char *format, ... );

extern void CL_LoadFileSystem( void );
extern void CL_UnloadFileSystem( void );

extern void CL_LoadGameUI( void );
extern void CL_UnloadGameUI( void );

extern void CL_LoadVGUI2( void );
extern void CL_UnloadVGUI2( void );

extern const char *GetModelType( model_t *pModel );

extern void COM_FileBase ( const char *in, char *out);