//========= Copyright © 2008-2023, Team Sandpit, All rights reserved. ============
//
// Purpose: mod triangle tests
//
// $NoKeywords: $
//================================================================================

#define ENGINECALLBACK_H

#include "../foolsgoldsource/vscu_test.h"
#include "../foolsgoldsource/foolsgoldsource.h"

#include "mod/modtri.h"

extern float g_iFogColor[3];
extern float g_iFogDensity;
extern float g_iStartDist;
extern float g_iEndDist;
extern int g_iFogSkybox;

extern int g_iWaterLevel;

namespace modtests
{
	TEST_CLASS(modtri_test)
	{
	public:

		TEST_METHOD_INITIALIZE(SetUp)
		{
			::foolsgoldsource::gEngine.SetIsFogOn( false );
		}

		TEST_METHOD_CLEANUP(TearDown)
		{
		}

		TEST_METHOD(TestRenderFogLowWaterLevel)
		{
			g_iFogColor[0] = 255.0f;
			g_iFogColor[1] = 255.0f;
			g_iFogColor[2] = 255.0f;
			g_iFogDensity = 1.0f;
			g_iStartDist = 0.0f;
			g_iEndDist = 10.0f;
			g_iFogSkybox = 1;
			g_iWaterLevel = 1;

			RenderFog();
			Assert::IsTrue( ::foolsgoldsource::gEngine.GetIsFogOn() );
		}

		TEST_METHOD(TestRenderFogHighWaterLevel)
		{
			g_iFogColor[0] = 255.0f;
			g_iFogColor[1] = 255.0f;
			g_iFogColor[2] = 255.0f;
			g_iFogDensity = 1.0f;
			g_iStartDist = 0.0f;
			g_iEndDist = 10.0f;
			g_iFogSkybox = 1;
			g_iWaterLevel = 2;

			RenderFog();
			Assert::IsFalse( ::foolsgoldsource::gEngine.GetIsFogOn() );
		}
	};
}
