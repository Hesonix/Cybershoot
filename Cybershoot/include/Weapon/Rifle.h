#pragma once

#include "Weapon.h"

class Rifle : public Weapon
{
public:
	Rifle();

	void Fire() override;
};