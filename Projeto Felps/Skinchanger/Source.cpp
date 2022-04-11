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

#include "csgo.hpp"
#include "load.cpp"


//Offsets secundarios

#define m_nModelIndex 0x258
#define m_iViewModelIndex 0x3250 //netvar correto 
#define m_hViewModel 0x3308 //netvar 20h

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

NBQMemory mem_;
auto m_id = mem_.GetProcessIdByProcessName("csgo.exe");
auto m_handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, m_id);
auto dwClient = mem_.GetModuleBaseAddress(m_id, "client.dll");

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

	while (!GetAsyncKeyState(VK_F8))
	{
		if (GetAsyncKeyState(VK_END)) {
			cout << "Atualizados!" << endl;
			load("Config.ini");
			Sleep(150);
			felpsds(m_handle, dwClient, kmodelid, kskinid);
			Sleep(200);
		}

		DWORD localPlayer = nbqmem.ReadMemory<DWORD>(csgo, client + hazedumper::signatures::dwLocalPlayer);
		DWORD crosshairId = nbqmem.ReadMemory<DWORD>(csgo, localPlayer + hazedumper::netvars::m_iCrosshairId);
		DWORD localTeam = nbqmem.ReadMemory<DWORD>(csgo, client + hazedumper::netvars::m_iTeamNum);

		
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
				DWORD myWeapons = nbqmem.ReadMemory<DWORD>(csgo, localPlayer + hazedumper::netvars::m_hMyWeapons + i * 0x4) & 0xfff;
				DWORD weaponEntity = nbqmem.ReadMemory<DWORD>(csgo, client + hazedumper::signatures::dwEntityList + (myWeapons - 1) * 0x10);
				if (weaponEntity == 0) { continue; }


				short weaponID = nbqmem.ReadMemory<short>(csgo, weaponEntity + hazedumper::netvars::m_iItemDefinitionIndex);

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
					nbqmem.WriteMemory<short>(csgo, weaponEntity + hazedumper::netvars::m_iItemDefinitionIndex, itemDef);
					nbqmem.WriteMemory<DWORD>(csgo, weaponEntity + m_iViewModelIndex, modelIndex); //sem som e todos items atualizando
					nbqmem.WriteMemory<DWORD>(csgo, weaponEntity + m_nModelIndex, modelIndex); //sem som 
					nbqmem.WriteMemory<int>(csgo, weaponEntity + hazedumper::netvars::m_iEntityQuality, entityQuality); //  nada
					
				}
				nbqmem.WriteMemory<int>(csgo, weaponEntity + hazedumper::netvars::m_iItemIDHigh, itemIDHigh);
				nbqmem.WriteMemory<DWORD>(csgo, weaponEntity + hazedumper::netvars::m_nFallbackPaintKit, fallbackPaint);
				nbqmem.WriteMemory<float>(csgo, weaponEntity + hazedumper::netvars::m_flFallbackWear, fallbackWear);
				//
				
				
				
			}
		}


		DWORD activeWeapon = nbqmem.ReadMemory<DWORD>(csgo, localPlayer + hazedumper::netvars::m_hActiveWeapon) & 0xfff;
		DWORD weaponEntity = nbqmem.ReadMemory<DWORD>(csgo, client + hazedumper::signatures::dwEntityList + (activeWeapon - 1) * 0x10);
		if (weaponEntity == 0) { continue; }

		

		short weaponID = nbqmem.ReadMemory<short>(csgo, weaponEntity + hazedumper::netvars::m_iItemDefinitionIndex);

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
		DWORD knifeEntity = nbqmem.ReadMemory<DWORD>(csgo, client + hazedumper::signatures::dwEntityList + (knifeViewmodel - 1) * 0x10);
		if (knifeEntity == 0) { continue; }

		nbqmem.WriteMemory<DWORD>(csgo, knifeEntity + m_nModelIndex, modelIndex);
		


	}
}

using namespace config;

using std::cout;
using std::flush;
using std::string;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

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
	string loading = "Skins carregadas!\n";
	anim(loading, 15);

	

	if (m_handle != INVALID_HANDLE_VALUE)
		felpsds(m_handle, dwClient, kmodelid, kskinid);


	if (m_handle) {
		CloseHandle(m_handle);
	}

	return 0;
}
