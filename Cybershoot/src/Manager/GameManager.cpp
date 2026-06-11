#include "Manager/GameManager.h"

#include "Player.h"
#include "ManagerLocator.h"
#include "Manager/UIManager.h"
#include "Manager/StateManager.h"
#include "Manager/ScoreManager.h"
#include "State/GameOverState.h"

void GameManager::OnEnemyKilled()
{
	currentScore += KILL_POINTS;
	ManagerLocator::GetUIManager().UpdateScoreText(currentScore);
}

int GameManager::CalculateFinalScore()
{
	int survivalScore = static_cast<int>(gameTime * SURVIVAL_POINTS_PER_SECOND);

	int totalScore = currentScore + survivalScore;

	float timeMultiplier = 1.0f + (gameTime / 100.0f);

	return static_cast<int>(totalScore * timeMultiplier);
}

void GameManager::CheckWeaponUnlock()
{
	for (auto& weaponUnlock : weaponUnlocks)
	{
		if (gameTime >= weaponUnlock.time && !weaponUnlock.isUnlocked)
		{
			weaponUnlock.isUnlocked = true;

			Player::GetInstance().SetWeapon(weaponUnlock.type);
		}
	}
}

void GameManager::Update(float deltaTime)
{
	if (Player::GetInstance().IsAlive())
	{
		gameTime += deltaTime;
		ManagerLocator::GetUIManager().UpdateGameTimeText(gameTime);

		CheckWeaponUnlock();
	}
	else
	{
		currentScore = CalculateFinalScore();
		ManagerLocator::GetScoreManager().SaveHighscore(currentScore);
		ManagerLocator::GetStateManager().PushState(std::make_unique<GameOverState>());
	}
}