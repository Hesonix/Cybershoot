#pragma once

#include "Weapon.h"

class Pistol : public Weapon
{
public:
	Pistol();

	void Fire() override;
};