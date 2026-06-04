#include "Manager/GameManager.h"

#include "Player.h"
#include "ManagerLocator.h"
#include "Manager/UIManager.h"

void GameManager::Update(float deltaTime)
{
	if (Player::GetInstance().IsAlive())
	{
		gameTime += deltaTime;
		ManagerLocator::GetUIManager().UpdateGameTimeText(gameTime);
	}
}