#include <string>
#include <thread>
#include <chrono>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <ostream>
#include "string"
#include "nbqmemory.h"
#include "stdafx.h"
#include <Lmcons.h>
#include <stdlib.h>
#include "memory.h"

//Offsets secundarios

#define m_nModelIndex 0x258
#define m_iViewModelIndex 0x3250 //netvar correto 
#define m_hViewModel 0x3308 //netvar 20h

#pragma region Offsets



#define cs_gamerules_data  0x0
#define m_ArmorValue  0x117CC
#define m_Collision  0x320
#define m_CollisionGroup  0x474
#define m_Local  0x2FCC
#define m_MoveType  0x25C
#define m_OriginalOwnerXuidHigh  0x31D4
#define m_OriginalOwnerXuidLow  0x31D0
#define m_SurvivalGameRuleDecisionTypes  0x1328
#define m_SurvivalRules  0xD00
#define m_aimPunchAngle  0x303C
#define m_aimPunchAngleVel  0x3048
#define m_angEyeAnglesX  0x117D0
#define m_angEyeAnglesY  0x117D4
#define m_bBombDefused  0x29C0
#define m_bBombPlanted  0x9A5
#define m_bBombTicking  0x2990
#define m_bFreezePeriod  0x20
#define m_bGunGameImmunity  0x9990
#define m_bHasDefuser  0x117DC
#define m_bHasHelmet  0x117C0
#define m_bInReload  0x32B5
#define m_bIsDefusing  0x997C
#define m_bIsQueuedMatchmaking  0x74
#define m_bIsScoped  0x9974
#define m_bIsValveDS  0x7C
#define m_bSpotted  0x93D
#define m_bSpottedByMask  0x980
#define m_bStartedArming  0x3400
#define m_bUseCustomAutoExposureMax  0x9D9
#define m_bUseCustomAutoExposureMin  0x9D8
#define m_bUseCustomBloomScale  0x9DA
#define m_clrRender  0x70
#define m_dwBoneMatrix  0x26A8
#define m_fAccuracyPenalty  0x3340
#define m_fFlags  0x104
#define m_flC4Blow  0x29A0
#define m_flCustomAutoExposureMax  0x9E0
#define m_flCustomAutoExposureMin  0x9DC
#define m_flCustomBloomScale  0x9E4
#define m_flDefuseCountDown  0x29BC
#define m_flDefuseLength  0x29B8
#define m_flFallbackWear  0x31E0
#define m_flFlashDuration  0x10470
#define m_flFlashMaxAlpha  0x1046C
#define m_flLastBoneSetupTime  0x2928
#define m_flLowerBodyYawTarget  0x9ADC
#define m_flNextAttack  0x2D80
#define m_flNextPrimaryAttack  0x3248
#define m_flSimulationTime  0x268
#define m_flTimerLength  0x29A4
#define m_hActiveWeapon  0x2F08
#define m_hBombDefuser  0x29C4
#define m_hMyWeapons  0x2E08
#define m_hObserverTarget  0x339C
#define m_hOwner  0x29DC
#define m_hOwnerEntity  0x14C
#define m_hViewModel  0x3308
#define m_iAccountID  0x2FD8
#define m_iClip1  0x3274
#define m_iCompetitiveRanking  0x1A84
#define m_iCompetitiveWins  0x1B88
#define m_iCrosshairId  0x11838
#define m_iDefaultFOV  0x333C
#define m_iEntityQuality  0x2FBC
#define m_iFOV  0x31F4
#define m_iFOVStart  0x31F8
#define m_iGlowIndex  0x10488
#define m_iHealth  0x100
#define m_iItemDefinitionIndex  0x2FBA
#define m_iItemIDHigh  0x2FD0
#define m_iMostRecentModelBoneCounter  0x2690
#define m_iObserverMode  0x3388
#define m_iShotsFired  0x103E0
#define m_iState  0x3268
#define m_iTeamNum  0xF4
#define m_lifeState  0x25F
#define m_nBombSite  0x2994
#define m_nFallbackPaintKit  0x31D8
#define m_nFallbackSeed  0x31DC
#define m_nFallbackStatTrak  0x31E4
#define m_nForceBone  0x268C
#define m_nTickBase  0x3440
#define m_nViewModelIndex  0x29D0
#define m_rgflCoordinateFrame  0x444
#define m_szCustomName  0x304C
#define m_szLastPlaceName  0x35C4
#define m_thirdPersonViewAngles  0x31E8
#define m_vecOrigin  0x138
#define m_vecVelocity  0x114
#define m_vecViewOffset  0x108
#define m_viewPunchAngle  0x3030
#define m_zoomLevel  0x33E0
#define anim_overlays  0x2990
#define clientstate_choked_commands  0x4D30
#define clientstate_delta_ticks  0x174
#define clientstate_last_outgoing_command  0x4D2C
#define clientstate_net_channel  0x9C
#define convar_name_hash_table  0x2F0F8
#define dwClientState  0x58BFC4
#define dwClientState_GetLocalPlayer  0x180
#define dwClientState_IsHLTV  0x4D48
#define dwClientState_Map  0x28C
#define dwClientState_MapDirectory  0x188
#define dwClientState_MaxPlayer  0x388
#define dwClientState_PlayerInfo  0x52C0
#define dwClientState_State  0x108
#define dwClientState_ViewAngles  0x4D90
#define dwEntityList  0x4DCEB7C
#define dwForceAttack  0x31FF054
#define dwForceAttack2  0x31FF078
#define dwForceBackward  0x31FF0A8
#define dwForceForward  0x31FF09C
#define dwForceJump  0x52789F8
#define dwForceLeft  0x31FF0B4
#define dwForceRight  0x31FF0C0
#define dwGameDir  0x62A880
#define dwGameRulesProxy  0x52EBA5C
#define dwGetAllClasses  0xDDCF2C
#define dwGlobalVars  0x58BCC8
#define dwGlowObjectManager  0x5316E98
#define dwInput  0x5220150
#define dwInterfaceLinkList  0x966044
#define dwLocalPlayer  0xDB35EC
#define dwMouseEnable  0xDB92F8
#define dwMouseEnablePtr  0xDB92C8
#define dwPlayerResource  0x31FD3E0
#define dwRadarBase  0x52038F4
#define dwSensitivity  0xDB9194
#define dwSensitivityPtr  0xDB9168
#define dwSetClanTag  0x8A290
#define dwViewMatrix  0x4DC0494
#define dwWeaponTable  0x5220C18
#define dwWeaponTableIndex  0x326C
#define dwYawPtr  0xDB8F58
#define dwZoomSensitivityRatioPtr  0xDBEF60
#define dwbSendPackets  0xD93D2
#define dwppDirect3DDevice9  0xA5050
#define find_hud_element  0x2E0648A0
#define force_update_spectator_glow  0x3BA6CA
#define interface_engine_cvar  0x3E9EC
#define is_c4_owner  0x3C76A0
#define m_bDormant  0xED
#define m_flSpawnTime  0x103C0
#define m_pStudioHdr  0x2950
#define m_pitchClassPtr  0x5203B90
#define m_yawClassPtr  0xDB8F58
#define model_ambient_min  0x58F03C
#define set_abs_angles  0x1E51E0
#define set_abs_origin  0x1E5020

#pragma endregion

namespace offset
{
	//client.dll

	constexpr ::std::ptrdiff_t EntityList = 0x4DCEB7C;
	constexpr ::std::ptrdiff_t localPlayer = 0xDB35EC;

	//entity

	constexpr ::std::ptrdiff_t Spotted = 0x93D;
	constexpr ::std::ptrdiff_t TeamNum = 0xF4;
}

//Faca do CT/TR
#define precache_bayonet_ct 90  // = v_knife_bayonet.mdl - v_knife_default_ct.mdl 639 - 549
#define precache_bayonet_t 65 // = v_knife_bayonet.mdl - v_knife_default_t.mdl 639 - 574

NBQMemory nbqmem;

typedef unsigned char uint8_t;
bool ssd = false;
template <typename T, size_t N>

size_t countof(T(&array)[N])
{
	return N;
}

int kmodelid = 508;
int kskinid = 416;

//Config
int Deagle;
int Glock;
int Ak47;
int Awp;
int M4A1S;
int Usp;
int M4a4;
int Scar20;
int Scout;
int Aug;
int Revolver;
int Cz75;
int P250;
int Sg553;
int Nova;
int Mp9;
int Mp7;
int P2000;
int Tec9;
int Sawedoff;
int Negev;
int Mag7;
int Bizon;
int Xm1014;
int Ump45;
int Mp5sd;
int P90;
int Mac10;
int M249;
int Galil;
int G3sg1;
int Famas;
int Fiveseven;
int Dualberettas;

int GetKnifeID(const short itemDef)
{
	switch (itemDef)
	{
	default:
	case WEAPON_KNIFE_BAYONET:
		return 0;
	case WEAPON_KNIFE_FLIP:
		return 1;
	case WEAPON_KNIFE_GUT:
		return 2;
	case WEAPON_KNIFE_KARAMBIT:
		return 3;
	case WEAPON_KNIFE_M9_BAYONET:
		return 4;
	case WEAPON_KNIFE_TACTICAL:
		return 5;
	case WEAPON_KNIFE_FALCHION:
		return 6;
	case WEAPON_KNIFE_SURVIVAL_BOWIE:
		return 7;
	case WEAPON_KNIFE_BUTTERFLY:
		return 8;
	case WEAPON_KNIFE_PUSH:
		return 9;
	case WEAPON_KNIFE_URSUS:
		return 10;
	case WEAPON_KNIFE_GYPSY_JACKKNIFE:
		return 11;
	case WEAPON_KNIFE_STILETTO:
		return 12;
	case WEAPON_KNIFE_WIDOWMAKER:
		return 13;
	}
}

void felpsds(HANDLE csgo, DWORD client, short itemDef, DWORD paintKit)
{
	const int itemIDHigh = -1;
	const int entityQuality = 3;
	const float fallbackWear = 0.0001f;

	int knifeID = GetKnifeID(itemDef);
	int knifeIDOffset = knifeID < 10 ? 0 : 1;

	DWORD cachedPlayer = 0;
	DWORD modelIndex = 0;

	while (!GetAsyncKeyState(VK_F9))
	{
		DWORD localPlayer = nbqmem.ReadMemory<DWORD>(csgo, client + dwLocalPlayer);
		DWORD crosshairId = nbqmem.ReadMemory<DWORD>(csgo, localPlayer + m_iCrosshairId);
		DWORD localTeam = nbqmem.ReadMemory<DWORD>(csgo, client + m_iTeamNum);

		
		if (localPlayer == 0)
		{
			modelIndex = 0;
			continue;
		}
		else if (localPlayer != cachedPlayer)
		{
			modelIndex = 0;
			cachedPlayer = localPlayer;
		}

		if (paintKit > 0 && modelIndex > 0)
		{
			for (int i = 0; i < 8; i++)
			{
				DWORD myWeapons = nbqmem.ReadMemory<DWORD>(csgo, localPlayer + m_hMyWeapons + i * 0x4) & 0xfff;
				DWORD weaponEntity = nbqmem.ReadMemory<DWORD>(csgo, client + dwEntityList + (myWeapons - 1) * 0x10);
				if (weaponEntity == 0) { continue; }


				short weaponID = nbqmem.ReadMemory<short>(csgo, weaponEntity + m_iItemDefinitionIndex);

				DWORD fallbackPaint = paintKit;
				if (weaponID == WEAPON_DEAGLE) { fallbackPaint = Deagle;}
				else if (weaponID == WEAPON_GLOCK) { fallbackPaint = Glock; } 
				else if (weaponID == WEAPON_AK47) { fallbackPaint = Ak47; } 
				else if (weaponID == WEAPON_AWP) { fallbackPaint = Awp; } 
				else if (weaponID == WEAPON_M4A1_SILENCER) { fallbackPaint = M4A1S; } 
				else if (weaponID == WEAPON_USP) { fallbackPaint = Usp; } 
				else if (weaponID == WEAPON_M4A4) { fallbackPaint = M4a4; } 
				else if (weaponID == WEAPON_SCAR20) { fallbackPaint = Scar20; } 
				else if (weaponID == WEAPON_SSG08) { fallbackPaint = Scout; } 
				else if (weaponID == WEAPON_AUG) { fallbackPaint = Aug; } 
				else if (weaponID == WEAPON_REVOLVER) { fallbackPaint = Revolver; } 
				else if (weaponID == WEAPON_CZ75A) { fallbackPaint = Cz75; } 
				else if (weaponID == WEAPON_P250) { fallbackPaint = P250; }
				else if (weaponID == WEAPON_SG556) { fallbackPaint = Sg553; } 
				else if (weaponID == WEAPON_NOVA) { fallbackPaint = Nova; } 
				else if (weaponID == WEAPON_MP9) { fallbackPaint = Mp9; } 
				else if (weaponID == WEAPON_MP7) { fallbackPaint = Mp7; }
				else if (weaponID == WEAPON_P2000) { fallbackPaint = P2000; } 
				else if (weaponID == WEAPON_TEC9) { fallbackPaint = Tec9; } 
				else if (weaponID == WEAPON_SAWEDOFF) { fallbackPaint = Sawedoff; } 
				else if (weaponID == WEAPON_NEGEV) { fallbackPaint = Negev; } 
				else if (weaponID == WEAPON_MAG7) { fallbackPaint = Mag7;  } 
				else if (weaponID == WEAPON_BIZON) { fallbackPaint = Bizon; } 
				else if (weaponID == WEAPON_XM1014) { fallbackPaint = Xm1014; } 
				else if (weaponID == WEAPON_UMP45) { fallbackPaint = Ump45; } 
				else if (weaponID == WEAPON_MP5SD) { fallbackPaint = Mp5sd; }
				else if (weaponID == WEAPON_P90) { fallbackPaint = P90; } 
				else if (weaponID == WEAPON_MAC10) { fallbackPaint = Mac10; } 
				else if (weaponID == WEAPON_M249) { fallbackPaint = M249; } 
				else if (weaponID == WEAPON_GALIL) { fallbackPaint = Galil; } 
				else if (weaponID == WEAPON_G3SG1) { fallbackPaint = G3sg1; } 
				else if (weaponID == WEAPON_FAMAS) { fallbackPaint = Famas; } 
				else if (weaponID == WEAPON_FIVESEVEN) { fallbackPaint = Fiveseven; } 
				else if (weaponID == WEAPON_ELITE) { fallbackPaint = Dualberettas; } 
				else if (weaponID != WEAPON_KNIFE && weaponID != WEAPON_KNIFE_T && weaponID != itemDef) { continue; }
				else
				{
					nbqmem.WriteMemory<short>(csgo, weaponEntity + m_iItemDefinitionIndex, itemDef);
					nbqmem.WriteMemory<DWORD>(csgo, weaponEntity + m_iViewModelIndex, modelIndex); //sem som e todos items atualizando
					nbqmem.WriteMemory<DWORD>(csgo, weaponEntity + m_nModelIndex, modelIndex); //sem som 
					nbqmem.WriteMemory<int>(csgo, weaponEntity + m_iEntityQuality, entityQuality); //  nada
					
				}
				nbqmem.WriteMemory<int>(csgo, weaponEntity + m_iItemIDHigh, itemIDHigh);
				nbqmem.WriteMemory<DWORD>(csgo, weaponEntity + m_nFallbackPaintKit, fallbackPaint);
				nbqmem.WriteMemory<float>(csgo, weaponEntity + m_flFallbackWear, fallbackWear);
				//
				
				
				
			}
		}


		DWORD activeWeapon = nbqmem.ReadMemory<DWORD>(csgo, localPlayer + m_hActiveWeapon) & 0xfff;
		DWORD weaponEntity = nbqmem.ReadMemory<DWORD>(csgo, client + dwEntityList + (activeWeapon - 1) * 0x10);
		if (weaponEntity == 0) { continue; }


		short weaponID = nbqmem.ReadMemory<short>(csgo, weaponEntity + m_iItemDefinitionIndex);

		int weaponViewModelID = nbqmem.ReadMemory<int>(csgo, weaponEntity + m_iViewModelIndex);
		
		if (weaponID == WEAPON_KNIFE && weaponViewModelID > 0 && knifeID == 0)
		{
			modelIndex = weaponViewModelID + precache_bayonet_ct + 3 * knifeID + knifeIDOffset;
		}
		else if (weaponID == WEAPON_KNIFE_T && weaponViewModelID > 0 && knifeID == 0)
		{
			modelIndex = weaponViewModelID + precache_bayonet_t + 3 * knifeID + knifeIDOffset;
		}
		else if (weaponID == WEAPON_KNIFE && weaponViewModelID > 0)
		{
			modelIndex = weaponViewModelID + precache_bayonet_ct + 3 * knifeID + knifeIDOffset + 3;
		}
		else if (weaponID == WEAPON_KNIFE_T && weaponViewModelID > 0)
		{
			modelIndex = weaponViewModelID + precache_bayonet_t + 3 * knifeID + knifeIDOffset + 3;
		}
		else if (weaponID != itemDef || modelIndex == 0) { continue; }


		DWORD knifeViewmodel = nbqmem.ReadMemory<DWORD>(csgo, localPlayer + m_hViewModel) & 0xfff;
		DWORD knifeEntity = nbqmem.ReadMemory<DWORD>(csgo, client + dwEntityList + (knifeViewmodel - 1) * 0x10);
		if (knifeEntity == 0) { continue; }

		nbqmem.WriteMemory<DWORD>(csgo, knifeEntity + m_nModelIndex, modelIndex);

		//radar
		for (auto i = 1; i <= 64; ++i)
		{
			const auto entity = nbqmem.ReadMemory<DWORD>(csgo, client + dwEntityList + i * 0x10);

			if (nbqmem.ReadMemory<DWORD>(csgo, client + (entity + m_iTeamNum)) == localTeam)
				continue;

			nbqmem.WriteMemory<bool>(csgo, entity + m_bSpotted, true);

		}

	}
}

namespace config
{
	std::string		m_config;
	std::string		m_current;

	auto m_exists(const std::string& name) -> bool
	{
		std::ifstream f(name);
		return f.good();
	}

	auto m_create(const std::string& name) -> bool
	{
		auto dir = name.substr(0, name.find_last_of("\\"));

		if (CreateDirectory(dir.c_str(), nullptr) || GetLastError() == ERROR_ALREADY_EXISTS)
		{
			std::ofstream f(name);

			if (f.good())
			{
				f.close();

				return true;
			}
		}

		return false;
	}
	auto GetPath() -> std::string
	{
		return m_config;
	}

	auto load_int(const std::string& strSection, const std::string& strName) -> int
	{
		char szData[MAX_PATH];
		GetPrivateProfileString(strSection.c_str(), strName.c_str(), "0", szData, MAX_PATH, m_current.c_str());
		return static_cast<int>(atoi(szData));
	}

	auto load_float(const std::string& strSection, const std::string& strName) -> float
	{
		char szData[MAX_PATH];
		GetPrivateProfileString(strSection.c_str(), strName.c_str(), "0", szData, MAX_PATH, m_current.c_str());
		return atof(szData);
	}

	auto load_bool(const std::string& strSection, const std::string& strName) -> bool
	{
		char szData[MAX_PATH];
		GetPrivateProfileString(strSection.c_str(), strName.c_str(), "0", szData, MAX_PATH, m_current.c_str());
		return atoi(szData);
	}

	auto save_bool(const std::string& strSection, const std::string& strName, bool bValue) -> void
	{
		WritePrivateProfileString(strSection.c_str(), strName.c_str(), std::to_string(bValue).c_str(), m_current.c_str());
	}

	auto SaveShit(const std::string& strSection, const std::string& strName, int iValue) -> void
	{
		WritePrivateProfileString(strSection.c_str(), strName.c_str(), std::to_string(iValue).c_str(), m_current.c_str());
	}

	auto save_float(const std::string& strSection, const std::string& strName, float flValue) -> void
	{
		WritePrivateProfileString(strSection.c_str(), strName.c_str(), std::to_string(flValue).c_str(), m_current.c_str());
	}
	auto save(const std::string& name) -> void
	{
		std::string changer("Skinchanger");
		auto current = name;

		if (current.find(".ini") == std::string::npos)
			current.append(".ini");

		m_current = m_config + current;

		if (!m_exists(m_current))
		{
			if (!m_create(m_current))
				printf("Config file doesnt exist, creating a new one.");
				printf("Config created!");

		}

		SaveShit(changer, "Knife", kmodelid);
		SaveShit(changer, "KnifeSkin", kskinid);
		SaveShit(changer, "Deagle", Deagle);
		SaveShit(changer, "Glock", Glock);
		SaveShit(changer, "Ak47", Ak47);
		SaveShit(changer, "Awp", Awp);
		SaveShit(changer, "M4A1S", M4A1S);
		SaveShit(changer, "Usp", Usp);
		SaveShit(changer, "M4a4", M4a4);
		SaveShit(changer, "Scar20", Scar20);
		SaveShit(changer, "Scout", Scout);
		SaveShit(changer, "Aug", Aug);
		SaveShit(changer, "Revolver", Revolver);
		SaveShit(changer, "Cz75", Cz75);
		SaveShit(changer, "P250", P250);
		SaveShit(changer, "Sg553", Sg553);
		SaveShit(changer, "Nova", Nova);
		SaveShit(changer, "Mp9", Mp9);
		SaveShit(changer, "Mp7", Mp7);
		SaveShit(changer, "P2000", P2000);
		SaveShit(changer, "Tec9", Tec9);
		SaveShit(changer, "Sawedoff", Sawedoff);
		SaveShit(changer, "Negev", Negev);
		SaveShit(changer, "Mag7", Mag7);
		SaveShit(changer, "Bizon", Bizon);
		SaveShit(changer, "Xm1014", Xm1014);
		SaveShit(changer, "Ump45", Ump45);
		SaveShit(changer, "Mp5sd", Mp5sd);
		SaveShit(changer, "P90", P90);
		SaveShit(changer, "Mac10", Mac10);
		SaveShit(changer, "M249", M249);
		SaveShit(changer, "Galil", Galil);
		SaveShit(changer, "G3sg1", G3sg1);
		SaveShit(changer, "Famas", Famas);
		SaveShit(changer, "Fiveseven", Fiveseven);
		SaveShit(changer, "DualBerettas", Dualberettas);
	}

}
using namespace config;
auto load(const std::string& name) -> void
{
	std::string changer("Skinchanger");
	auto current = name;

	if (current.find(".ini") == std::string::npos)
		current.append(".ini");

	m_current = m_config + current;

	if (!m_exists(m_current))
		save(name);

	kmodelid = load_int(changer, "Knife");
	kskinid = load_int(changer, "KnifeSkin");
	Deagle = load_int(changer, "Deagle");
	Glock = load_int(changer, "Glock");
	Ak47 = load_int(changer, "Ak47");
	Awp = load_int(changer, "Awp");
	M4A1S = load_int(changer, "M4A1S");
	Usp = load_int(changer, "Usp");
	M4a4 = load_int(changer, "M4a4");
	Scar20 = load_int(changer, "Scar20");
	Scout = load_int(changer, "Scout");
	Aug = load_int(changer, "Aug");
	Revolver = load_int(changer, "Revolver");
	Cz75 = load_int(changer, "Cz75");
	P250 = load_int(changer, "P250");
	Sg553 = load_int(changer, "Sg553");
	Nova = load_int(changer, "Nova");
	Mp9 = load_int(changer, "Mp9");
	Mp7 = load_int(changer, "Mp7");
	P2000 = load_int(changer, "P2000");
	Tec9 = load_int(changer, "Tec9");
	Sawedoff = load_int(changer, "Sawedoff");
	Negev = load_int(changer, "Negev");
	Mag7 = load_int(changer, "Mag7");
	Bizon = load_int(changer, "Bizon");
	Xm1014 = load_int(changer, "Xm1014");
	Ump45 = load_int(changer, "Ump45");
	Mp5sd = load_int(changer, "Mp5sd");
	P90 = load_int(changer, "P90");
	Mac10 = load_int(changer, "Mac10");
	M249 = load_int(changer, "M249");
	Galil = load_int(changer, "Galil");
	G3sg1 = load_int(changer, "G3sg1");
	Famas = load_int(changer, "Famas");
	Fiveseven = load_int(changer, "Fiveseven");
	Dualberettas = load_int(changer, "DualBerettas");
}

using std::cout;
using std::flush;
using std::string;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

void anim(const string&, unsigned int);

void anim(const string& message, unsigned int millis_per_char)
{
	for (const char c : message)
	{
		cout << c << flush;

		sleep_for(milliseconds(millis_per_char));
	}
}

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTitle(_T("Felps Skinchanger"));

	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.left, r.top, 465, 155, TRUE);

	config::m_config = ".\\";
	printf("---------------------------------\n");
	printf("|");
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	printf(" Knife/Skin changer by Felpsds ");
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	printf("|\n");
	printf("---------------------------------\n");

	TCHAR name[UNLEN + 1];
	DWORD size = UNLEN + 1;

	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	if (GetUserName((TCHAR*)name, &size))
	{
		string welcome = "Bem vindo: ";
		anim(welcome, 20);
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	string name1 = name;
	anim(name1, 20);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	string paja = ", vou carregar as skins!\n";
	anim(paja, 20);
	Beep(800, 100);

	load("Config.ini");
	Sleep(150);


	NBQMemory mem_;
	auto m_id = mem_.GetProcessIdByProcessName("csgo.exe");
	auto m_handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, m_id);
	auto dwClient = mem_.GetModuleBaseAddress(m_id, "client.dll");
	Sleep(150);

	if (m_handle != INVALID_HANDLE_VALUE)
		felpsds(m_handle, dwClient, kmodelid, kskinid);

	if (m_handle) {
		CloseHandle(m_handle);
	}






	return 0;
}
