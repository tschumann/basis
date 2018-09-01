//========= Copyright © 1996-2002, Valve LLC, All rights reserved. ============
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================

#if !defined( MODSTUDIOMODELRENDERER_H )
#define MODSTUDIOMODELRENDERER_H
#if defined( _WIN32 )
#pragma once
#endif

/*
====================
CModStudioModelRenderer

====================
*/
class CModStudioModelRenderer : public CStudioModelRenderer
{
public:
	CModStudioModelRenderer( void );

	// Set up model bone positions
	virtual void StudioSetupBones ( void );	

	// Send bones and verts to renderer
	virtual void StudioRenderModel ( void );
protected:
	bool StudioShouldRenderModel( model_t *pRenderModel );
};

#endif // MODSTUDIOMODELRENDERER_H