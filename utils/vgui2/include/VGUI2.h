//========= Copyright © 1996-2002, Valve LLC, All rights reserved. ============
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================

#ifndef VGUI2_H
#define VGUI2_H

#ifdef _WIN32
#define VGUI2_DLLNAME "../vgui2.dll"
#elif defined(OSX)
#define VGUI2_DLLNAME "../vgui2.dylib"
#elif defined(LINUX)
#define VGUI2_DLLNAME "../vgui2.so"
#else
#error
#endif

// handle to an internal vgui panel
// this is the only handle to a panel that is valid across dll boundaries
typedef unsigned int VPANEL;

// handles to vgui objects
// NULL values signify an invalid value
typedef unsigned long HScheme;
typedef unsigned long HTexture;
typedef unsigned long HCursor;
typedef unsigned long HPanel;
const HPanel INVALID_PANEL = 0xffffffff;
typedef unsigned long HFont;
const HFont INVALID_FONT = 0; // the value of an invalid font handle

#endif

