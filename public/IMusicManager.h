//========= Copyright © 1996-2002, Valve LLC, All rights reserved. ============
//
// Purpose: 
//
//=============================================================================

#ifndef IMUSICMANAGER_H
#define IMUSICMANAGER_H
#ifdef _WIN32
#pragma once
#endif

#include "interface.h"

enum TrackType
{
};

//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
class IMusicManager : public IBaseInterface
{
public:
	virtual void	StartTrack(TrackType type, bool looping) = 0;

	virtual void	StopTrack() = 0;

	virtual void	FadeOutTrack() = 0;

	virtual bool	IsPlayingTrack() = 0;

	virtual bool	IsPlayingTrack(TrackType type) = 0;
};

#define MUSICMANAGER_INTERFACE_VERSION "MusicManager001"

#endif // IMUSICMANAGER_H