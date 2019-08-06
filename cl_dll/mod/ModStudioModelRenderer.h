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

	// Send bones and verts to renderer
	virtual void StudioRenderModel ( void );
protected:
	virtual void StudioCulling( void );
	virtual void StudioScaleBones( void );

	virtual bool StudioShouldRenderModel( model_t *pRenderModel );
};

#endif // MODSTUDIOMODELRENDERER_H