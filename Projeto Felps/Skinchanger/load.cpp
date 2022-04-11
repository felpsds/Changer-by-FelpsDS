#include <stdlib.h>

int kmodelid = 508;
int kskinid = 416;

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
