//========= Copyright © 2008-2023, Team Sandpit, All rights reserved. ============
//
// Purpose: construction entity tests
//
// $NoKeywords: $
//================================================================================

#include "foolsgoldsource/vscu_test.h"
#include "foolsgoldsource/foolsgoldsource.h"

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "mod/modcbase.h"

extern "C" void monster_construction_dead(entvars_t* pev);

namespace modtests
{
	TEST_CLASS(construction_test)
	{
	public:

		TEST_METHOD_INITIALIZE(SetUp)
		{
		}

		TEST_METHOD_CLEANUP(TearDown)
		{
		}

		TEST_METHOD(TestSpawn)
		{
			edict_t* pEdict = foolsgoldsource::gEngine.CreateEdict();
			monster_construction_dead( &pEdict->v );
			Assert::IsNotNull( pEdict->pvPrivateData );

			KeyValueData pose = { "monster_construction_dead", "pose", "0", 0 };
			DispatchKeyValue(pEdict, &pose);

			Assert::AreEqual( 0, ModDispatchSpawn( pEdict ) );
			Assert::AreEqual( 0, pEdict->v.sequence );
			Assert::AreEqual( "models/construction.mdl", STRING(pEdict->v.model) );
		}
	};
}
