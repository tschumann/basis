//========= Copyright © 2008-2023, Team Sandpit, All rights reserved. ============
//
// Purpose: mod HUD tests
//
// $NoKeywords: $
//================================================================================

// fix definitions in enginecallback.h colliding with definitions in cl_util.h
#define ENGINECALLBACK_H

#include "../foolsgoldsource/vscu_test.h"
#include "../foolsgoldsource/foolsgoldsource.h"

#undef HSPRITE
#define HSPRITE HANDLE_SPRITE

#include "mod/modhud.h"
#include "cl_util.h"
#include "vgui_TeamFortressViewport.h"
#include "vgui_int.h"

extern "C" void VGui_Startup();

namespace modtests
{
	TEST_CLASS(modhud_test)
	{
	public:

		TEST_METHOD_INITIALIZE(SetUp)
		{
			if( gViewPort )
			{
				VGui_Shutdown();
			}
		}

		TEST_METHOD_CLEANUP(TearDown)
		{
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(TestModHudInit)
			TEST_IGNORE()
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(TestModHudInit)
		{
			VGui_Startup();
			// TODO: this crashed in VGUI code - need to fix no schemes being loaded as part of tests
			gHUD.Init();
		}
	};
}
