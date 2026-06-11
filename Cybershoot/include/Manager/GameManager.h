#pragma once

#include <vector>

#include "GameTypes.h"

class GameManager
{
private:
	static constexpr int KILL_POINTS = 100;
	static constexpr int SURVIVAL_POINTS_PER_SECOND = 5;

	struct WeaponUnlock
	{
		float time;
		WeaponType type;
		bool isUnlocked = false;
	};

	std::vector<WeaponUnlock> weaponUnlocks = {
		{150.0f, WeaponType::Shotgun},
		{300.0f, WeaponType::Rifle},
	};

	float gameTime = 0.0f;
	int currentScore = 0;
	WeaponType currentWeaponType = WeaponType::Pistol;

	int CalculateFinalScore();
	void CheckWeaponUnlock();
public:
	float GetGameTime() { return gameTime; }
	int GetCurrentScore() { return currentScore; }
	void OnEnemyKilled();
	
	void Update(float deltaTime);
};