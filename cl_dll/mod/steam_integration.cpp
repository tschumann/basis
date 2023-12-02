/***
*
*	Copyright (c) 1996-2002, Valve LLC. All rights reserved.
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

#include "hud.h"
#include "mod/mod_cl_util.h"
// stub for function that the Steam API tries to use
int Q_snprintf( char *buffer, size_t buffersize, const char *format, ... ) { return 0; }
// NETADR_H is defined in common/netadr.h but the Steam API expects it to be defined in tier1 code
#undef NETADR_H
#include "steam_api.h"
#define NETADR_H

bool g_iSteamAPIInited;

void Steam_Init()
{
	g_iSteamAPIInited = SteamAPI_Init();
	ConsoleDPrintf( "SteamAPI_Init result %d\n", g_iSteamAPIInited );
}

bool Steam_UserHasLicenseForApp()
{
	ISteamUser* pUser = SteamUser();
	AppId_t appId = gEngfuncs.pfnGetAppID();

	if( pUser )
	{
		char cTicketData[2048];
		uint32 iTicketLength;

		HAuthTicket ticket = pUser->GetAuthSessionTicket( cTicketData, sizeof(cTicketData), &iTicketLength );
		ConsoleDPrintf( "GetAuthSessionTicket returned %d byte ticket\n", iTicketLength );
		EBeginAuthSessionResult authSessionResult = pUser->BeginAuthSession( cTicketData, iTicketLength, pUser->GetSteamID() );

		if( authSessionResult == k_EBeginAuthSessionResultOK )
		{
			EUserHasLicenseForAppResult licenseForAppResult = pUser->UserHasLicenseForApp( pUser->GetSteamID(), appId );
			ConsoleDPrintf( "UserHasLicenseForApp for appId %d: %d\n", appId, licenseForAppResult );

			return licenseForAppResult == k_EUserHasLicenseResultHasLicense;
		}
		else
		{
			ConsoleDPrintf( "BeginAuthSession returned %d\n", authSessionResult );
		}

		pUser->EndAuthSession( pUser->GetSteamID() );
	}
	else
	{
		ConsolePrintf( "Unable to get ISteamUser\n" );
	}

	return false;
}

bool Steam_UserOwnsApp( AppId_t appId )
{
	ISteamApps* pApps = SteamApps();

	if( pApps )
	{
		bool bOwner = pApps->BIsSubscribedApp( appId );
		ConsoleDPrintf( "BIsSubscribedApp for appId %d: %d\n", appId, bOwner );

		return bOwner;
	}
	else
	{
		ConsolePrintf( "Unabled to get ISteamApps\n" );

		return false;
	}
}