#pragma once
#include <graphics/texture.h>
#include <string>
#include <load_texture.h>
#include <graphics/sprite.h>

using std::string;

namespace gef
{
	class Platform;
}

class Weapon: public gef::Sprite
{
public:
	Weapon();
	~Weapon();
	gef::Texture* getIcon();
	int getCost();
	int getDamage();
	int getAmmo();
	float getReloadTime();
	char* getName();
	void create(const char* pngFileName, gef::Platform* platform, int newCost, int newDamage, int newMaxAmmo, float newReloadTime, char* newName, char* newSfxPath);
	void decrementAmmo(int value);
	float getRanOutOfAmmoTime();
	void setRanOutOfAmmoTime(float newTime);
	int getMaxAmmo();
	void setAmmo(int value);
	char* getSfxPath();
private:
	gef::Texture* icon = NULL;
	unsigned short int cost = 0;
	unsigned short int damage = 0;
	unsigned short int ammo = 0;
	float reloadTime = 0.0f;
	float ranOutOfAmmoTime = 0.0f;
	unsigned short int maxAmmo = 0;
	char* name;
	char* sfxPath;
};

