/***
*
*	Copyright (c) 1996-2001, Valve LLC. All rights reserved.
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
//
// coop_gamerules.h
//

#define MAX_TEAMNAME_LENGTH	16
#define MAX_TEAMS			1

#define TEAMPLAY_TEAMLISTLENGTH		MAX_TEAMS*MAX_TEAMNAME_LENGTH
#define TEAMNAME					"Players"

class CHalfLifeCoop : public CHalfLifeMultiplay
{
public:
	CHalfLifeCoop();

	virtual BOOL ClientCommand( CBasePlayer *pPlayer, const char *pcmd );
	virtual void ClientUserInfoChanged( CBasePlayer *pPlayer, char *infobuffer );
	virtual BOOL IsTeamplay( void ) { return false; }
	virtual BOOL IsCoOp( void ) { return true; }
	virtual int IPointsForKill( CBasePlayer *pAttacker, CBasePlayer *pKilled );
	virtual void InitHUD( CBasePlayer *pl );
	virtual void DeathNotice( CBasePlayer *pVictim, entvars_t *pKiller, entvars_t *pevInflictor );
	virtual const char *GetGameDescription( void ) { return "HL Coop"; }  // this is the game name that gets seen in the server browser
	virtual void UpdateGameMode( CBasePlayer *pPlayer );  // the client needs to be informed of the current game mode
	virtual void PlayerKilled( CBasePlayer *pVictim, entvars_t *pKiller, entvars_t *pInflictor );
	virtual void Think ( void );
	const char *SetDefaultPlayerTeam( CBasePlayer *pPlayer );
	virtual void ChangePlayerTeam( CBasePlayer *pPlayer, const char *pTeamName, BOOL bKill, BOOL bGib );
	virtual int WeaponShouldRespawn( CBasePlayerItem *pWeapon );
	virtual float FlWeaponRespawnTime( CBasePlayerItem *pWeapon );
	virtual int ItemShouldRespawn( CItem *pItem );
	virtual float FlItemRespawnTime( CItem *pItem );
	virtual int AmmoShouldRespawn( CBasePlayerAmmo *pAmmo );
	virtual float FlAmmoRespawnTime( CBasePlayerAmmo *pAmmo );
	virtual float FlHealthChargerRechargeTime( void );
	virtual float FlHEVChargerRechargeTime( void );
	virtual BOOL FAllowMonsters( void );

private:

	BOOL m_DisableDeathMessages;
	BOOL m_DisableDeathPenalty;
	BOOL m_teamLimit;				// This means the server set only some teams as valid
	char m_szTeamList[TEAMPLAY_TEAMLISTLENGTH];
};
