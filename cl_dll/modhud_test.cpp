//========= Copyright © 2008-2023, Team Sandpit, All rights reserved. ============
//
// Purpose: construction entity tests
//
// $NoKeywords: $
//================================================================================

#include "../foolsgoldsource/vscu_test.h"
#include "../foolsgoldsource/foolsgoldsource.h"

#include "mod/modhud.h"

extern "C" void VGui_Startup();

namespace modtests
{
	TEST_CLASS(modhud_test)
	{
	public:

		TEST_METHOD_INITIALIZE(SetUp)
		{
		}

		TEST_METHOD_CLEANUP(TearDown)
		{
		}

		TEST_METHOD(TestModHudInit)
		{
			VGui_Startup();
			gHUD.Init();
		}
	};
}
