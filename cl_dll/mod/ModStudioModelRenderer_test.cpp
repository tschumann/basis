//========= Copyright © 2008-2023, Team Sandpit, All rights reserved. ============
//
// Purpose: mod studio model renderer tests
//
// $NoKeywords: $
//================================================================================

// fix definitions in enginecallback.h colliding with definitions in cl_util.h
#define ENGINECALLBACK_H

#include "../foolsgoldsource/vscu_test.h"
#include "../foolsgoldsource/foolsgoldsource.h"

#include "com_model.h"
#include "studio.h"
#include "StudioModelRenderer.h"
#include "mod/ModStudioModelRenderer.h"

namespace modtests
{
	TEST_CLASS(modstudiomodelrenderer_test)
	{
	public:

		TEST_METHOD_INITIALIZE(SetUp)
		{
		}

		TEST_METHOD_CLEANUP(TearDown)
		{
		}

		TEST_METHOD(TestModStudioModelRendererInit)
		{
			CModStudioModelRenderer studioRenderer = CModStudioModelRenderer();
			studioRenderer.Init();

			Assert::IsNotNull( studioRenderer.m_pCvarHiModels );
			Assert::IsNotNull( studioRenderer.m_pCvarDeveloper );
			Assert::IsNotNull( studioRenderer.m_pCvarDrawEntities );
		}
	};
}
