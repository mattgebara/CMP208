#include "PlayerData.h"
#include <system\debug_log.h>

int PlayerData::getHealth()
{
	return health;
}

int PlayerData::getCredits()
{
	return credits;
}

void PlayerData::addCredits(int value)
{
	credits = credits + value;
}

void PlayerData::decrementCredits(int value)
{
	credits = credits - value;
}

void PlayerData::decrementHealth(float time, int value)
{
	if (lastDamageTime + 0.5f <= time)
	{
		//We last took damge 0.5 seconds ago, deal damage.
		health--;
		lastDamageTime = time;
	}
	return;
}

Weapon PlayerData::getActiveWeapon()
{
	return activeWeapon;
}

void PlayerData::addWeapon(Weapon newWeapon)
{
	//Check all the data before we push it
	if (newWeapon.getAmmo() == NULL)
	{
		gef::DebugOut("ERROR: Weapon has a null ammo count!");
		return;
	}
	else if (newWeapon.getCost() == NULL)
	{
		gef::DebugOut("ERROR: Weapon has a null cost!");
		return;
	}
	else if(newWeapon.getDamage() == NULL)
	{
		gef::DebugOut("ERROR: Weapon has a null damage count!");
		return;
	}
	else if (newWeapon.getIcon() == NULL)
	{
		gef::DebugOut("ERROR: Weapon has a null icon!");
		return;
	}
	else if (newWeapon.getReloadTime() == NULL)
	{
		gef::DebugOut("ERROR: Weapon has a null reload time!");
		return;
	}
	else if (newWeapon.getName() == "")
	{
		gef::DebugOut("ERROR: Weapon has a null name!");
		return;
	}
	weapons.push_back(newWeapon);
	activeWeapon = weapons.back();
	return;
}

void PlayerData::setActiveWeapon(char* name)
{
	for (unsigned int i = 0; i < weapons.size(); i++)
	{
		if (weapons[i].getName() == name)
		{
			activeWeapon = weapons[i];
		}
	}

	gef::DebugOut("ERROR: Unable to set active weapon!\n");
}

void PlayerData::removeMostRecentWeapon()
{
	weapons.erase(weapons.end()-1);
}

void PlayerData::addHealth(int value)
{
	if (health + value > 100)
	{
		health = 100;
	}
	else
	{
		health = health + value;
	}
}

void PlayerData::addRiflemen(int value)
{
	riflemen = riflemen + value;
}

unsigned short int PlayerData::getRiflemen()
{
	return riflemen;
}

void PlayerData::addRepairGuys(int value)
{
	repairGuys = repairGuys + value;
}

unsigned short int PlayerData::getReapirGuys()
{
	return repairGuys;
}

void PlayerData::setLastDamageTime(float value)
{
	lastDamageTime = value;
}

unsigned int PlayerData::getWeaponsSize()
{
	return weapons.size();
}

bool PlayerData::hasWeapon(char* weaponName)
{
	bool found = false;

	for (unsigned int i = 0; i < weapons.size(); i++)
	{
		if (weapons[i].getName() == weaponName)
		{
			found = true;
			return found;
		}
	}

	return found;
}

void PlayerData::resetData()
{
	credits = 0;
	weapons.clear();
	weapons.shrink_to_fit();
	health = 100;
	lastDamageTime = 0.0f;
	riflemen = 0;
	repairGuys = 0;
}
